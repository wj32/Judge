#include <stdio.h>

int n;
int order[7];
char terminal[129];
char vva[8];

char line[3 * 7 + 1];

void docase(void)
{
    int width = 1 << (n - 1);
    int i = 0;
    int index = 0;
    
    do
    {
        if (vva[order[i++]])
            index += width;
    } while (width >>= 1);
    
    printf("%c", '0' + terminal[index]);
}

int main(int argc, char *argv[])
{
    int count = 0;
    
    while (1)
    {
        int i;
        int j;
        int m;
        
        count++;
        scanf("%d", &n);
        
        if (n == 0)
            break;
        
        fgets(line, 2, stdin); // get rid of newline - stupid C
        fgets(line, sizeof(line), stdin);
        
        for (i = 0; i < n; i++)
            order[i] = line[1 + 3 * i] - '1';
        
        scanf("%s", terminal);
        
        for (i = 0; i < (1 << n); i++)
            terminal[i] = terminal[i] == '1';
        
        scanf("%d", &m);
        
        printf("S-Tree #%d:\n", count);
        
        for (i = 0; i < m; i++)
        {
            scanf("%s", vva);
            
            for (j = 0; j < n; j++)
                vva[j] = vva[j] == '1';
            
            docase();
        }
        
        printf("\n\n");
    }
}
