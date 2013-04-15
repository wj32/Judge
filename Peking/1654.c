#include <stdio.h>

#define M 1000000

char input[M + 1];
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };

long long area2(void)
{
    long long sum = 0;
    long long x1, y1, x2, y2;
    char *c = input;
    
    x1 = 0;
    y1 = 0;
    
    while (*c != '5')
    {
        x2 = x1 + dx[*c - '1'];
        y2 = y1 + dy[*c - '1'];
        sum += x1 * y2 - x2 * y1;
        x1 = x2;
        y1 = y2;
        c++;
    }
    
    return sum;
}

int main(int argc, char *argv[])
{
    int n;
    int i;
    
    scanf("%d", &n);
    fgets(input, 2, stdin); // get rid of newline
    
    for (i = 0; i < n; i++)
    {
        long long area;
        
        fgets(input, sizeof(input), stdin);
        area = area2();
        
        if (area < 0)
            area = -area;
        
        printf("%I64d%s\n", area / 2, (area & 1) ? ".5" : "");
    }
    
    return 0;
}
