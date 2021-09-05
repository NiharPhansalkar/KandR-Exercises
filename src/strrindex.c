#include <stdio.h>
#include <stdlib.h>
//Program to return the position of the rightmost occurance of t(Particular string) in s(Actual string), or give -1 if there is none. Like grep command.

int strrindex(char [], char[]);

#define MAX 256

int main(void)
{
    char str[MAX] = "lol";

    int c, a = 0;
    char input[MAX];
    printf("Please enter your string.");
    printf("\n");
    while((c = getchar()) != EOF)
    {
        if(c != '\n' && c != '\t')
        {
            input[a] = (char)c;
            a++;
        }
        if(c == '\n')
        {
            break;
        }
    }
    printf("\n");
    printf("%d\n", strrindex(input, str));
    return 0;
}

int strrindex(char s[], char t[])
{
    int counter = 0, counter1 = 0;
    while(s[counter] != '\0')
    {
        counter++;
    }

    while(t[counter1] != '\0')
    {
        counter1++;
    }

    int i = 0, j = 0, flag = 0, k, pos = 0;

    for(i = 0; i < counter; i++)
    {
        if(s[i] == t[j])
        {
            k = i;
            for(int l = 0;l<counter1;l++)
            {
                if(s[k] == t[l])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
                k++;
            }
            if(flag == 1)
            {
                pos = i+1;
            }
        }
        else
        {
            continue;
        }
    }
    if(pos != 0)
    {
        return (pos);
    }
    else
    {
        return (-1);
    }
    
    exit(0);
}