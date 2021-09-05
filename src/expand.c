#include <stdio.h>

void Input(void);
void escape(char []);

int main(void)
{
    Input();
    return 0;
}

void Input(void)
{
    printf("Input your characters with a '-' to expand.\n");
    int c, i = 0;
    char s1[50];
    while((c = getchar()) != EOF)
    {
        if(c != '\n' && c != '\t')
        {
            s1[i] = (char)c;
            i++;
        }
        else if(c == '\n')
        {
            break;
        }
    }
    escape(s1);
}

void escape(char s1[])
{
    int counter = 0;
    while(s1[counter] != '\0')
    {
        counter++;
    }

    for(int k = 0; k<counter; k++)
    {
        if(s1[k] >= 'A' && s1[k] <= 'Z')
        {
            s1[k] = s1[k] + 32;
        }
    }

    for(int i = 0; i<counter; i++)
    {
        if(s1[i] >= 'a' && s1[i] <= 'z')
        {
            if(s1[i+2] >= 'a' && s1[i+2] <= 'z')
            {
                for (char j = s1[i]; j <= s1[i+2]; j++)
                {
                    putchar(j);
                }
            }
        }
        else if(s1[i] >= '0' && s1[i] <= '9')
        {
            if(s1[i+2] >= '0' && s1[i+2] <= '9')
            {
                for (char j = s1[i]; j <= s1[i+2]; j++)
                {
                    putchar(j);
                }
            }
        }
    }
    printf("\n");
}