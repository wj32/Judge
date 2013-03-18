#include <stdio.h>
#include <string.h>
#include <assert.h>

#define FAIL 9999
#define DIRBIT 0x8000
#define DIR(x) ((x) & DIRBIT)
#define LEN(x) ((x) & ~DIRBIT)
#define MAKECOST(l, d) ((l) + ((d) ? DIRBIT : 0))

char board[77][77];
int mem[77][77];
int step[77][77];
int width;
int height;
int changed;
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

int setmem(int result, int x2, int y2)
{
    if (mem[y2][x2] != result)
    {
        mem[y2][x2] = result;
        changed = 1;
    }
    
    return result;
}

// adds cost2 ONTO cost1:
// direction of result will be direction of cost2
int addcost(int cost1, int cost2)
{
    if (LEN(cost1) == 0)
        return cost2;
    
    return LEN(cost1) + cost2 - (DIR(cost1) == DIR(cost2));
}

// Returns min. segments to get from (x1,y1) to (x2,y2).
int rec(int x1, int y1, int x2, int y2, int iter)
{
    int best = FAIL;
    int result;
    int i;
    
    if (step[y2][x2] == iter)
        return mem[y2][x2];
    
    step[y2][x2] = iter;
    
    if (x2 == x1 && y2 == y1)
        return setmem(0, x2, y2);
    
    for (i = 0; i < 4; i++)
    {
        int newx2 = x2 + dir[i][0];
        int newy2 = y2 + dir[i][1];
        int d = !!dir[i][1];
        
        result = FAIL;
        
        if (newx2 >= 0 && newx2 < width + 2 && newy2 >= 0 && newy2 < height + 2)
        {
            if (newx2 == x1 && newy2 == y1)
                result = MAKECOST(1, d);
            else if (!board[newy2][newx2])
                result = addcost(rec(x1, y1, newx2, newy2, iter), MAKECOST(1, d));
        }
        
        if (LEN(best) > LEN(result))
            best = result;
    }
    
    // normalize FAIL
    if (LEN(best) > FAIL)
        best = FAIL;
    
    return setmem(best, x2, y2);
}

int main(int argc, char *argv[])
{
    int boardno = 0;
    
    while (1)
    {
        int w, h;
        int i, j;
        int pairno = 0;
        
        scanf("%d %d", &w, &h);
        
        if ((w | h) == 0)
            break;
        
        width = w;
        height = h;
        memset(board, 0, sizeof(board));
        
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
            
            for (j = 0; j < w; j++)
            {
                board[i + 1][j + 1] = data[j] == 'X';
            }
        }
        
        printf("Board #%d:\n", ++boardno);
        
        while (1)
        {
            int x1, y1, x2, y2;
            int ans;
            int iter = 0;
            
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            
            if ((x1 | y1 | x2 | y2) == 0)
                break;
            
            printf("Pair %d: ", ++pairno);
            
            for (i = 0; i < h + 2; i++)
            {
                for (j = 0; j < w + 2; j++)
                {
                    mem[i][j] = FAIL;
                }
            }
            
            memset(step, 0, sizeof(step));
            
            // run until fixed point
            while (1)
            {
                iter++;
                ans = LEN(rec(x1, y1, x2, y2, iter));
                
                if (!changed)
                    break;
                
                changed = 0;
            }
            
            if (ans != FAIL)
                printf("%d segments", ans);
            else
                printf("impossible");
            
            printf(".\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
