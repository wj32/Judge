#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PEOPLE 5000
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// represents an interval [start,start+length).
typedef struct _node
{
    int start;
    int length;
    int count; // count of {start}
    int leftcount; // count of (start,start+length)
} node;

int p, k, n;
node *list[1 + PEOPLE * 2]; // contains nodes for [p,k)
int count;
int rightcount; // count of {k}

node buffer[1 + PEOPLE * 2];
int bufferindex;

node *makenode(void)
{
    return &buffer[bufferindex++];
}

int findnode(int x, int *index)
{
    int low = 0;
    int high = count - 1;
    int mid;
    int start;
    
    do
    {
        mid = (low + high) / 2;
        start = list[mid]->start;
        
        if (start <= x && x < start + list[mid]->length)
            goto done;
        else if (x < start)
            high = mid - 1;
        else
            low = mid + 1;
    } while (low <= high);
    
done:
    *index = mid;
    
    return start <= x && x < start + list[mid]->length;
}

void insert(int index, node *d)
{
    memmove(list + index + 1, list + index, (count - index) * sizeof(node *));
    list[index] = d;
    count++;
}

void printnodes(void)
{
    int i;
    
    for (i = 0; i < count; i++)
        printf("%d*[%d,%d)*%d ", list[i]->leftcount, list[i]->start, list[i]->start + list[i]->length, list[i]->count);
    
    printf("RIGHT: %d\n", rightcount);
}

void split(int x)
{
    int index;
    node *d;
    
    if (x == k)
        return;
    
    if (!findnode(x, &index))
        assert(0);
    
    d = list[index];
    
    if (d->start < x && x < d->start + d->length)
    {
        node *right;
        
        right = makenode();
        right->start = x;
        right->length = d->length - (x - d->start);
        right->count = d->count;
        right->leftcount = d->count;
        insert(index + 1, right);
        
        d->length = x - d->start;
    }
}

void increment(int a, int b)
{
    int index;
    node *d;
    
    if (a == k && b == k)
    {
        rightcount++;
        return;
    }
    
    split(a);
    split(b);
    
    if (!findnode(a, &index))
        assert(0);
    
    while (index < count)
    {
        d = list[index];
        d->leftcount++;
        
        if (d->start >= b)
            break;
        
        d->count++;
        index++;
    }
    
    if (b == k)
        rightcount++;
}

void testcase(void)
{
    int i;
    int min = PEOPLE + 1;
    int max = 0;
    
    scanf("%d %d", &p, &k);
    scanf("%d", &n);
    
    bufferindex = 0;
    count = 1;
    rightcount = 0;
    list[0] = makenode();
    list[0]->start = p;
    list[0]->length = k - p;
    list[0]->count = 0;
    list[0]->leftcount = 0;
    
    for (i = 0; i < n; i++)
    {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        if (a <= k && b >= p)
        {
            if (a < p)
                a = p;
            if (b > k)
                b = k;
            
            increment(a, b);
        }
    }
    
    if (p != k)
    {
        for (i = 0; i < count; i++)
        {
            if (min > MIN(list[i]->count, list[i]->leftcount))
                min = MIN(list[i]->count, list[i]->leftcount);
            if (max < MAX(list[i]->count, list[i]->leftcount))
                max = MAX(list[i]->count, list[i]->leftcount);
        }
    }
    
    if (min > rightcount)
        min = rightcount;
    if (max < rightcount)
        max = rightcount;
    
    printf("%d %d\n", min, max);
}

int main(int argc, char *argv[])
{
    int i;
    
    for (i = 0; i < 10; i++)
        testcase();
    
    return 0;
}
