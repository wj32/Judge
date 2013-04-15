#include <stdio.h>
#include <math.h>

// Number of multiples of k in {1,...,n}.
int mult(int n, int k)
{
    return n / k;
}

// Sum of d(m, p) for m=1,...,n,
// where d=d(m, p) is largest integer such that p^d divides m.
// p must be prime.
// sd is an integer such that p^sd >= n.
int xf(int n, int p, int sd)
{
    int result = 0;
    int d;
    int pd = p;
    
    for (d = 1; d <= sd; d++, pd *= p)
        result += n / pd;
    
    return result;
}

int zf(int n)
{
    // 2^30 > 10^9
    // 5^13 > 10^9
    //int d2 = xf(n, 2, 30);
    int d5 = xf(n, 5, 13);
    
    // note d2 is always larger than d5
    
    return d5;
}

int main(int argc, char *argv[])
{
    int n;
    int i;
    int k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        printf("%d\n", zf(k));
    }
    
    return 0;
}
