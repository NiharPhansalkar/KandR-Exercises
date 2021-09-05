#include <stdio.h>
#include <stdlib.h>

//Program that counts similar characters in two strings.

void input(void);
int any(char [], char[]);

int main(void)
{
    input();
    return 0;
}

void input(void)
{
    printf("Please enter the first string.\n");
    int c1,c2, i = 0, j = 0, prnt;
    char s1[50], s2[50];

    while((c1 = getchar()) != EOF)
    {
        if (c1 == '\n')
        {
            break;
        }
        else if (c1 != '\t' && c1 != '\n')
        {
            s1[i] = (char)c1;
            i++;
        }
    }
    printf("Please enter the second string.\n");

    while((c2 = getchar()) != EOF)
    {
        if (c2 == '\n')
        {
            break;
        }
        else if (c2 != '\t' && c2 != '\n')
        {
            s2[j] = (char)c2;
            j++;
        }
    }
    prnt = any(s1,s2);
    printf("\n");
    printf("%-2d\n", prnt);
}

int any(char str_one[], char str_two[])
{
    int i = 0;
    int j = 0;
    int pos, flag = 0;
    int counter1 = 0, counter2 = 0;

    while(str_one[counter1] != '\0')
    {
        counter1++;
    }
    while(str_two[counter2] != '\0')
    {
        counter2++;
    }

    while (j<counter2)
    {
        for (i = 0; i<counter1; i++)
        {
            if(str_one[i] == str_two[j])
            {
                pos = i+1;
                flag = 1;
                return (pos);
            }
        }
        j++;
    }
    if(flag == 0)
    {
        return (-1);
    }
    else
    {
        printf("Invalid input. Please try again with valid input.");
        exit(0);
    }
}