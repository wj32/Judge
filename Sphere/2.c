#include <math.h>
#include <stdio.h>

int isprime(int n)
{
    int top = (int)floor(sqrt(n));
    int i;
    
    for (i = 2; i <= top; i++)
    {
        if (n % i == 0)
            return 0;
    }
    
    return 1;
}

int main(int argc, char *argv[])
{
    int k;
    int j;
    int i;
    
    scanf("%d", &k);
    
    for (j = 0; j < k; j++)
    {
        int m;
        int n;
        
        scanf("%d %d", &m, &n);
        
        for (i = m; i <= n; i++)
        {
            if (isprime(i))
                printf("%d\n", i);
        }
        
        printf("\n");
    }
}
