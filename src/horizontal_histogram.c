#include <stdio.h>
//Program to print Histogram based on the size the word.

//Ver. 2 (Horizontal)
int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            printf("%2c", '*');
        }
        else if (c == '\n' || c == '\t' || c == ' ')
        {
            printf("\n");
        }
    }
    return 0;
}

//Ver. 1 (Horizontal)
/*#define UPPERLIM 100 //Max letters allowed
#define LOWERLIM 1 //Min letters allowed

int main()
{
    int c, flag = 0; // To take character input. 
    char Stars[10];

    for(int i = 0; i<10; i++)
    {
        Stars[i] = '*';
    }
    while ((c = getchar()) != EOF)
    {
        if(c >= LOWERLIM && c <= UPPERLIM)
        {
            if (c == '\n')
            {
                printf("\n");
                continue;
            }
            else if(c == ' ' || c == '\t')
            {
                flag = 0;
                printf("\n");
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 1)
        {
            printf("%4c", Stars[0]);
        }
    }
    printf("\n\n");
    return 0;
}*/