#include <stdio.h>
#include <math.h>

// Number of multiples of k in {1,...,n}.
int mult(int n, int k)
{
    return n / k;
}

// Returns b^e.
int powi(int b, int e)
{
    int r = 1;
    
    while (e)
    {
        if (e & 1)
            r *= b;
        
        e /= 2;
        b *= b;
    }
    
    return r;
}

// Sum of d(m, p) for m=1,...,n,
// where d=d(m, p) is largest integer such that p^d divides m.
// p must be prime.
// sd is an integer such that p^sd >= n.
int xf(int n, int p, int sd)
{
    int result = 0;
    int d = sd;
    int pd = powi(p, d);
    int k;
    int j;
    
    j = mult(n, pd);
    result = j * d;
    
    while (--d >= 1)
    {
        pd /= p;
        k = mult(n, pd);
        result += (k - j) * d;
        j = k;
    }
    
    return result;
}

int zf(int n)
{
    // 2^30 > 10^9
    // 5^13 > 10^9
    int d2 = xf(n, 2, 30);
    int d5 = xf(n, 5, 13);
    
    if (d2 < d5)
        return d2;
    else
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
