#include <stdio.h>

int seq[100][200];

int iszero(int *array, int count)
{
    int i;
    
    for (i = 0; i < count; i++)
    {
        if (array[i] != 0)
            return 0;
    }
    
    return 1;
}

int complete(int n, int c)
{
    int k = 0;
    int nk = n;
    int i;
    
    while (1)
    {
        k++;
        nk--;
        
        for (i = 0; i < nk; i++)
            seq[k][i] = seq[k - 1][i + 1] - seq[k - 1][i];
        
        if (nk == 0 || iszero(seq[k], nk))
        {
            k--;
            nk++;
            break;
        }
    }
    
    for (i = nk; i < nk + c; i++)
        seq[k][i] = seq[k][nk - 1];
    
    while (1)
    {
        k--;
        nk++;
        
        if (k < 0)
            break;
        
        for (i = nk; i < nk + c; i++)
            seq[k][i] = seq[k][i - 1] + seq[k + 1][i - 1];
    }
}

int main(int argc, char *argv[])
{
    int n;
    int i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        int s;
        int c;
        int j;
        
        scanf("%d %d", &s, &c);
        
        for (j = 0; j < s; j++)
            scanf("%d", &seq[0][j]);
        
        complete(s, c);
        
        for (j = 0; j < c; j++)
            printf("%s%d", j != 0 ? " " : "", seq[0][s + j]);
        
        printf("\n");
    }
    
    return 0;
}
