#include <stdio.h>
#include <math.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct _point
{
    float x;
    float y;
} point;

point points[150];
float r;
int n;

int count(point normal)
{
    int i;
    int pos = 0;
    int neg = 0;
    
    for (i = 0; i < n; i++)
    {
        float dot = points[i].x * normal.x + points[i].y * normal.y;
        
        if (dot > 0)
            pos++;
        if (dot < 0)
            neg++;
    }
    
    return MAX(n - pos, n - neg);
}

// transmitter is at (0,0), and all points are on the unit circle
void process(void)
{
    int i;
    int m = 0;
    
    for (i = 0; i < n; i++)
    {
        point normal;
        int result;
        
        normal.x = -points[i].y;
        normal.y = points[i].x;
        result = count(normal);
        
        if (m < result)
            m = result;
    }
    
    printf("%d\n", m);
}

int main(int argc, char *argv[])
{
    float x, y;
    int i;
    int index;
    
    while (1)
    {
        scanf("%f %f %f", &x, &y, &r);
        
        if (r < 0)
            break;
        
        scanf("%d", &n);
        index = 0;
        
        for (i = 0; i < n; i++)
        {
            float u, v;
            point p;
            float l;
            
            scanf("%f %f", &u, &v);
            p.x = u - x;
            p.y = v - y;
            l = p.x * p.x + p.y * p.y;
            
            if (l <= r * r)
            {
                l = sqrt(l);
                p.x /= l;
                p.y /= l;
                points[index++] = p;
            }
        }
        
        n = index;
        process();
    }
    
    return 0;
}
