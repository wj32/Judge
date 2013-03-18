#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    float numbers[12];
    float average;
    
    for (i = 0; i < 12; i++)
    {
        scanf("%f", numbers + i);
    }
    
    average = 0;
    
    for (i = 0; i < 12; i++)
    {
        average += numbers[i];
    }
    
    average /= 12;
    printf("$%.2f", average);
    
    return 0;
}
