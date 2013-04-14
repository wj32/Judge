#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PEOPLE 5000

typedef struct _node
{
    int start;
    int length;
    int count;
} node;

int p, k, n;
node *list[1 + PEOPLE * 2];
int count;

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
    int y;
    
    do
    {
        mid = (low + high) / 2;
        y = list[mid]->start;
        
        if (x == y)
            goto done;
        else if (x < y)
            high = mid - 1;
        else
            low = mid + 1;
    } while (low <= high);
    
done:
    if (mid > 0 && list[mid - 1]->start <= x && x < list[mid - 1]->start + list[mid - 1]->length)
        *index = mid - 1;
    else 
        *index = mid;
    
    return x == y;
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
        printf("[%d,%d):%d ", list[i]->start, list[i]->start + list[i]->length, list[i]->count);
    
    printf("\n");
}

void split(int x)
{
    int index;
    node *d;
    
    findnode(x, &index);
    d = list[index];
    
    if (d->start < x && x < d->start + d->length)
    {
        node *right;
        
        right = makenode();
        right->start = x;
        right->length = d->length - (x - d->start);
        right->count = d->count;
        insert(index + 1, right);
        
        d->length = x - d->start;
    }
}

void increment(int a, int b)
{
    int index;
    node *d;
    
    split(a);
    split(b + 1);
    
    if (!findnode(a, &index))
        assert(0);
    
    while (index < count)
    {
        d = list[index];
        
        if (d->start > b)
            break;
        
        d->count++;
        index++;
    }
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
    list[0] = makenode();
    list[0]->start = p;
    list[0]->length = k - p + 1;
    list[0]->count = 0;
    
    for (i = 0; i < n; i++)
    {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        if (a <= k)
        {
            if (a < p)
                a = p;
            if (b > k)
                b = k;
            
            increment(a, b);
        }
    }
    
    for (i = 0; i < count; i++)
    {
        if (min > list[i]->count)
            min = list[i]->count;
        if (max < list[i]->count)
            max = list[i]->count;
    }
    
    printf("%d %d\n", min, max);
}

int main(int argc, char *argv[])
{
    int i;
    
    for (i = 0; i < 10; i++)
        testcase();
    
    return 0;
}
