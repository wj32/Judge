#include <stdio.h>
#include <string.h>
#include <assert.h>

char maze[75][76];
int status[200][75];
int width;
int height;
int statusheight;
int unique = 0;

int statuswidth(int row)
{
    return width - ((row + 1) % 2);
}

int findfree(int *x, int *y)
{
    int i, j;
    
    for (i = 0; i < statusheight; i++)
    {
        int w = statuswidth(i);
        
        for (j = 0; j < w; j++)
        {
            if (!status[i][j])
            {
                *x = j;
                *y = i;
                return 1;
            }
        }
    }
    
    return 0;
}

int validate(int x, int y)
{
    int w = statuswidth(y);
    
    if (y < 0 || y >= statusheight)
        return 0;
    if (x < 0 || x >= w)
        return 0;
    
    return 1;
}

// returns 1 if point has exactly 2 adjacent points,
// otherwise returns 0.
int adj(int sx, int sy, int *x1, int *y1, int *x2, int *y2)
{
    if (sy % 2)
    {
        char top = maze[sy / 2][sx];
        char bottom = maze[sy / 2 + 1][sx];
        
        if (top == '/')
        {
            *x1 = sx;
            *y1 = sy - 1;
        }
        else
        {
            *x1 = sx - 1;
            *y1 = sy - 1;
        }
        
        if (bottom == '/')
        {
            *x2 = sx - 1;
            *y2 = sy + 1;
        }
        else
        {
            *x2 = sx;
            *y2 = sy + 1;
        }
    }
    else
    {
        char left = maze[sy / 2][sx];
        char right = maze[sy / 2][sx + 1];
        
        if (left == '/')
        {
            *x1 = sx;
            *y1 = sy + 1;
        }
        else
        {
            *x1 = sx;
            *y1 = sy - 1;
        }
        
        if (right == '/')
        {
            *x2 = sx + 1;
            *y2 = sy - 1;
        }
        else
        {
            *x2 = sx + 1;
            *y2 = sy + 1;
        }
    }
    
    return validate(*x1, *y1) && validate(*x2, *y2);
}

// returns length of cycle, or 0 if there is no cycle
int cycle(int sx, int sy)
{
    int length = 0;
    int x, y;
    
    x = sx;
    y = sy;
    
    unique++;
    
    while (1)
    {
        int x1, y1, x2, y2;
        
        status[y][x] = unique;
        
        if (!adj(x, y, &x1, &y1, &x2, &y2))
            return 0;
        
        length++;
        
        if (!status[y1][x1])
        {
            x = x1;
            y = y1;
        }
        else if (!status[y2][x2])
        {
            x = x2;
            y = y2;
        }
        else
        {
            if (status[y1][x1] != unique || status[y2][x2] != unique)
                return 0;
            
            break;
        }
    }
    
    return length;
}

void domaze(void)
{
    int cycles = 0;
    int maxlength = 0;
    
    statusheight = 2 * height - 1;
    
    while (1)
    {
        int sx;
        int sy;
        int length;
        
        if (!findfree(&sx, &sy))
            break;
        
        length = cycle(sx, sy);
        
        if (length != 0)
        {
            cycles++;
            
            if (maxlength < length)
                maxlength = length;
        }
    }
    
    if (cycles != 0)
        printf("%d Cycles; the longest has length %d.\n", cycles, maxlength);
    else
        printf("There are no cycles.\n");
}

int main(int argc, char *argv[])
{
    int mazeno = 0;
    
    while (1)
    {
        int w, h;
        int i;
        
        scanf("%d %d", &w, &h);
        
        if ((w | h) == 0)
            break;
        
        width = w;
        height = h;
        memset(maze, 0, sizeof(maze));
        
        for (i = 0; i < h; i++)
        {
            char data[76];
            
            fgets(data, sizeof(data), stdin);
            
            if (data[0] == '\n')
            {
                // stupid C
                i--;
                continue;
            }
            
            memcpy(maze[i], data, sizeof(data));
        }
        
        memset(status, 0, sizeof(status));
        printf("Maze #%d:\n", ++mazeno);
        domaze();
        printf("\n");
    }
    
    return 0;
}
