//Program to check for keywords in a given input.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key{
    char *word;
    int count;
};

struct key keywords[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    // Space between datatypes and other keywords.
    {"unsigned", 0},
    {"void", 0},
    {"while", 0},
};

int get_ch(void);
void unget_ch(int);
int getword(char *, int);
int Search_if_keyword(char *, struct key []);

#define PRE_PROCESSOR -2 
#define UNDERSCORE -2
#define COMMENT -2
#define TOTAL_KEYWORDS (sizeof(keywords)/sizeof(struct key))
#define WORD_MAX 100
char buf[WORD_MAX];
static int buffer;

int main(void){
    int check, store_val_temp, counter = 0;
    char input_string[WORD_MAX], *ptr = &input_string[0];
    printf("Please enter your line.\n");
    while((store_val_temp = getword(ptr ,WORD_MAX)) != EOF)
    {
        if(store_val_temp == -2)
        {
            while(input_string[counter] != '\0')
            {
                counter++;
            }
            counter -= 1;
            ptr += counter;
            continue;
        }
        if(isalpha(input_string[0]))
        {
            if((check = Search_if_keyword(ptr, keywords)) >= 0)
            {
                keywords[check].count++;
            }
        }
        while(input_string[counter] != '\0')
        {
            counter++;
        }
        counter -= 1;
        ptr += counter;
    }
    for(check = 0; check < TOTAL_KEYWORDS; check++)
    {
        if(keywords[check].count > 0)
        {
            printf("%s : occurred %d time(s).\n", keywords[check].word, keywords[check].count);
        }
    }
    
    return 0;
}

int Search_if_keyword(char *entered_word, struct key tab[]){
    int i;
    for(i = 0; i < TOTAL_KEYWORDS; i++)
    {
        if(strcmp(entered_word, tab[i].word) == 0)
        {
            return i;
        }
        else
        {
            continue;
        }
    }
    return -1;
}

int getword(char *g_word, int limit){
    int get_character;
    while(isspace(get_character = get_ch()))
        ;
    if(get_character != EOF)
    {
        *g_word = (char)get_character;
    }
    else
    {
        return EOF;
    }
    while(--limit > 0)
    {
        if(!isalnum(*g_word))
        {
            if((*g_word) == '/')
            {
                if((*++g_word = get_ch()) == '*')
                {
                    while(*g_word != '/')
                    {
                        *g_word = get_ch();
                    }
                    *g_word = '\0';
                    return COMMENT;
                }
                else if (*++g_word == '/')
                {
                    while(*g_word != '\n')
                    {
                        *g_word = get_ch();
                    }
                    *g_word = '\0';
                    return COMMENT;
                }
            }   
            else if((*g_word) == '#')
            {
                while(*g_word != '\n')
                {
                    *g_word = get_ch();
                }
                *g_word = '\0';
                return PRE_PROCESSOR;
            }
            else
            {
                unget_ch(*g_word);
                break;
            }
        }
        else
        {
            *++g_word = get_ch();
        }
    }
    *g_word = '\0';
    return g_word[0];
}

int get_ch(void){
    return (buffer > 0) ? buf[--buffer] : getchar();
}

void unget_ch(int c){
    if(buffer < WORD_MAX)
    {
        buf[buffer++] = c;
    }
    else
    {
        printf("Error : Buffer Full.\n");
    }
}