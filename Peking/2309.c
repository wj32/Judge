#include <stdio.h>

int trailing(int v)
{
    int c = 0;
    
    while (!(v & 1))
    {
        c++;
        v /= 2;
    }
    
    return c;
}

int main(int argc, char *argv[])
{
    int n;
    int i;
    int k;
    int t;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        t = 1 << trailing(k);
        printf("%d %d\n", k - t + 1, k + t - 1);
    }
    
    return 0;
}
