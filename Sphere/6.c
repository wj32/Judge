#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

char buffer[1002];

void printlines(char **lines, int count, int skip)
{
    int i;
    
    for (i = 0; i < count; i++)
        printf("%s\n", lines[i] + skip);
}

char **alloclines(int width, int count)
{
    char *buffer = malloc((width + 1) * count);
    char **lines = malloc(count * sizeof(char *));
    int i;
    
    memset(buffer, ' ', (width + 1) * count);
    
    for (i = 0; i < count; i++)
    {
        lines[i] = buffer + i * (width + 1);
        lines[i][width] = 0;
    }
    
    return lines;
}

// if op = '-', assumes second number is less than or equal to first number
// if op is a digit, multiplies n1 by that digit.
int add(char *n1, int l1, char *n2, int l2, char *destend, char op)
{
    int length;
    int mul = op >= '0' && op <= '9';
    char *p = destend;
    char *q;
    int carry = 0;
    int i;
    
    // make sure l2 <= l1
    if (l1 < l2)
    {
        char *tn = n1;
        int tl = l1;
        
        if (op == '-')
            assert(0);
        
        n1 = n2;
        l1 = l2;
        n2 = tn;
        l2 = tl;
    }
    
    length = l1;
    q = n2 + l2;
    
    for (i = 0; i < l1; i++)
    {
        if (n1[i] != ' ')
            *(destend - l1 + i) = n1[i];
        else
            *(destend - l1 + i) = '0';
    }
    
    do
    {
        char c;
        
        p--;
        q--;
        
        if (l2 > 0)
            c = *q;
        else
            c = '0';
        
        if (c == ' ')
            c = '0';
        
        if (op == '+')
        {
            *p += carry + c - '0';
            carry = *p > '9';
            
            if (carry)
                *p -= 10;
        }
        else if (op == '-')
        {
            *p -= carry + c - '0';
            carry = *p < '0';
            
            if (carry)
                *p += 10;
        }
        else if (mul)
        {
            int result = (*p - '0') * (op - '0') + carry;
            
            *p = '0' + (result % 10);
            carry = result / 10;
        }
        
        l2--;
    } while (--l1 != 0);
    
    if (carry != 0)
    {
        p--;
        *p = '0' + carry;
        length++;
    }
    
    if (op == '-')
        assert(carry == 0);
    
    // crop zeros
    while (*p == '0' && p != destend - 1)
    {
        *p = ' ';
        p++;
        length--;
    }
    
    return length;
}

void doaddsub(char *n1, int l1, char *n2, int l2, char op)
{
    int width = MAX(l1, l2) + 1;
    char **lines = alloclines(width, 4);
    int carry;
    int w1;
    int w2;
    
    memcpy(lines[0] + width - l1, n1, l1);
    memcpy(lines[1] + width - l2, n2, l2);
    lines[1][width - l2 - 1] = op;
    w1 = add(n1, l1, n2, l2, lines[3] + width, op);
    w2 = MAX(l1, l2 + 1);
    memset(lines[2] + width - MAX(l2 + 1, w1), '-', MAX(l2 + 1, w1));
    
    printlines(lines, 4, width - MAX(w1, w2));
}

void domul(char *n1, int l1, char *n2, int l2)
{
    int width = l1 + l2;
    char **lines = alloclines(width, 3 + l2 + 3);
    int firstlength = 0;
    int maxlength = 0;
    int i;
    int lastlength = 1;
    int w1;
    int w2;
    int iszero;
    
    memcpy(lines[0] + width - l1, n1, l1);
    memcpy(lines[1] + width - l2, n2, l2);
    lines[1][width - l2 - 1] = '*';
    
    for (i = 0; i < l2; i++)
    {
        int length;
        
        length = add(n1, l1, 0, 0, lines[3 + i] + width - i, n2[l2 - i - 1]);
        length += i;
        
        if (firstlength == 0)
            firstlength = length;
        if (maxlength < length)
            maxlength = length;
    }
    
    w1 = MAX(l2 + 1, firstlength);
    memset(lines[2] + width - w1, '-', w1);
    
    lines[3 + l2 + 1][width - 1] = '0';
    
    for (i = 0; i < l2; i++)
    {
        lastlength = add(lines[3 + l2 + 1] + width - lastlength, lastlength,
            lines[3 + i] + width - maxlength, maxlength,
            lines[3 + l2 + 2] + width, '+');
        memcpy(lines[3 + l2 + 1], lines[3 + l2 + 2], width);
    }
    
    w2 = MAX(maxlength, lastlength);
    memset(lines[3 + l2] + width - w2, '-', w2);
    
    printlines(lines, 3 + l2 + (l2 > 1) * 2, width - MAX(l1, MAX(w1, w2)));
}

int main(int argc, char *argv[])
{
    int n;
    int i;
    char *p;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%s", buffer);
        p = buffer;
        
        while (*p >= '0' && *p <= '9')
            p++;
        
        if (*p == '+' || *p == '-')
            doaddsub(buffer, (int)(p - buffer), p + 1, strlen(p + 1), *p);
        else if (*p == '*')
            domul(buffer, (int)(p - buffer), p + 1, strlen(p + 1));
        
        printf("\n");
    }
    
    return 0;
}
