#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int main(int argc, char *argv[])
{
    int k;
    int i;
    float R;
    int n;
    
    scanf("%d", &k);
    
    for (i = 1; i <= k; i++)
    {
        float sint, answer;
        
        scanf("%f %d", &R, &n);
        
        sint = sin(PI / n);
        answer = R * (1 - 1 / (1 + sint));
        printf("Scenario #%d:\n%.3f\n\n", i, answer);
    }
    
    return 0;
}
