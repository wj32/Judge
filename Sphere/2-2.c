#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        int top;
        char *data;
        
        scanf("%d %d", &m, &n);
        top = (int)(sqrt(n) + 1);
        
        data = malloc(n - m + 1);
        memset(data, 0, n - m + 1);

        for (i = 2; i <= top; i++)
        {
            if (i >= m && i <= n && data[i - m])
                continue;

            int p = m - m % i;

            if (p < m)
                p += i;
            if (p == i)
                p += i;

            for (; p <= n; p += i)
                data[p - m] = 1;
        }

        if (m == 1)
            data[0] = 1;

        for (i = m; i <= n; i++)
        {
            if (!data[i - m])
                printf("%d\n", i);
        }

        printf("\n");
    }

    return 0;
}
