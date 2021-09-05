//Program to implement a binary tree concept to search for variables in a file.

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tree_node 
{
    char *word;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node datatypes[] = {
    {"char"},
    {"int"},
    {"float"},
    {"double"}
};

int getword(char *);
int get_ch(void);
char *str_dup(char *);
struct tree_node *addtree(struct tree_node *, char *);
void treeprint(struct tree_node *);
void unget_ch(int);

#define MAX_LIM 150
int found = 0, proper_length = 0;
int how_many_chars;

int main(int argc, char *argv[])
{
    if(argv[1][0] != '-')
    {
        how_many_chars = argv[1][0];
    }
    else
    {
        how_many_chars = 6;
    }
    struct tree_node *root;
    char word[MAX_LIM];
    printf("Please enter your input.\n");
    while(getword(word) != EOF)
    {
        if(proper_length == 1)
        {
            proper_length = 0;
            continue;
        }
        if(found == 1)
        {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

struct tree_node *addtree(struct tree_node *pointer, char *w)
{
    int condition;
    if(pointer == NULL)
    {
        pointer = malloc(15 * sizeof(struct tree_node));
        pointer -> word = str_dup(w);
        pointer ->left = pointer ->right = NULL;
    }
    else if((condition = strcmp(w, pointer -> word) < 0))
    {
        pointer -> left = addtree(pointer ->left, w);
    }
    else if((condition = strcmp(w, pointer -> word) > 0))
    {
        pointer -> right = addtree(pointer -> right, w);
    }
    return pointer;
}

char *str_dup(char *s)
{
    char *p;

    p = malloc(strlen(s) + 1);
    if(p != NULL)
    {
        strcpy(p,s);
    }
    return p;
}
int getword(char *needed_word){
    int get_char, i;
    char *words = needed_word;
    char *check, for_check[MAX_LIM];
    check = for_check;
    if((get_char = get_ch()) == EOF)
    {
        return EOF;
    }
    else
    {
        while(isspace(get_char))
        {
            ;
            get_char = get_ch();
        }
        while(isalnum(get_char))
        {
            *words++ = get_char;
            *check++ = get_char;
            get_char = get_ch();
        }
        *words = '\0';
        *check = '\0';
        check = for_check;
        unget_ch(get_char);
        if(found == 0)
        {
            for(i = 0; i < 4; i++)
            {
                if(strcmp(check, datatypes[i].word) == 0)
                {
                    found = 1;
                }
            }
        }
        if(*check == '\n')
        {
            found = 0;
        }
        if(strlen(check) >= how_many_chars)
        {
            return (words[0]);
        }
        else
        {
            proper_length = 1;
        }
    }
}

void treeprint(struct tree_node *printer)
{
    if(printer != NULL)
    {
        treeprint(printer -> left);
        printf("%s\n", printer -> word);
        treeprint(printer -> right);
    }
}

char buffer[MAX_LIM];
int buf = 0;

int get_ch(void)
{
    return (buf>0) ? buffer[--buf] : getchar();
}

void unget_ch(int c)
{
    if(c < MAX_LIM)
    {
        buffer[buf] = c;
        buf++;
    }
    else
    {
        printf("Buffer is full, please try again with shorter words.\n");
        exit(0);
    }
}