#include <stdio.h>

#define N 1000000

char sieve[N + 1];

void init(void)
{
    int i, j;
    
    for (i = 2; i <= N; i++)
    {
        if (sieve[i])
            continue;
        
        for (j = i + i; j <= N; j += i)
            sieve[j] = 1;
    }
}

void goldbach(int n, int *a, int *b)
{
    int k;
    
    for (k = 3; k <= n / 2; k++)
    {
        if (sieve[k])
            continue;
        
        if (!sieve[n - k])
        {
            *a = k;
            *b = n - k;
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    int n, a, b;
    
    init();
    
    while (1)
    {
        scanf("%d", &n);
        
        if (n == 0)
            break;
        
        goldbach(n, &a, &b);
        printf("%d = %d + %d\n", n, a, b);
    }
    
    return 0;
}
