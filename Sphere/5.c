#include <stdio.h>
#include <string.h>

char buffer[1000002];

int addone(char **strp, int *lengthp, int position)
{
    char *str = *strp;
    int length = *lengthp;
    int i;
    
    for (i = position; i >= 0; i--)
    {
        if (str[i] == '9')
        {
            str[i] = '0';
        }
        else
        {
            str[i]++;
            break;
        }
    }
    
    if (i == -1)
    {
        str--;
        str[0]++;
        length++;
        
        *strp = str;
        *lengthp = length;
        
        return 1;
    }
    
    return 0;
}

int process(char *str, int length)
{
    int carry;
    int i;
    int j;
    int inc = 0;
    
    carry = addone(&str, &length, length - 1);
    
    // palindrome-ize
    
    for (j = length / 2; j < length; j++)
    {
        i = length - j - 1;
        
        if (str[i] != str[j])
        {
            if (str[i] < str[j] && !inc)
            {
                if (process(str + i + 1, j - i - 1))
                {
                    memset(str + i + 1, '0', j - i - 1);
                }
            }
            
            str[j] = str[i];
            inc = 1;
        }
    }
    
    return carry;
}

int main(int argc, char *argv[])
{
    int n;
    int k;
    int length;
    
    scanf("%d", &n);
    
    for (k = 0; k < n; k++)
    {
        buffer[0] = '0';
        scanf("%s", buffer + 1);
        length = strlen(buffer + 1);
        process(buffer + 1, length);
        printf("%s\n", buffer + (buffer[0] == '0'));
    }
    
    return 0;
}
