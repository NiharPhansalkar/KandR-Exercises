//Program to read input and print words with their line no. (Ignore noise words).

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct noise{
    char *noises;
};

struct noise noise_words[] = {
    {"about"},{"after"},{"all"},{"also"},{"an"},{"and"},{"any"},{"are"},{"as"},{"at"},
    {"be"},{"because"},{"been"},{"before"},{"between"},{"both"},{"but"},{"by"},
    {"came"},{"can"},{"come"},{"could"},
    {"did"},
    {"each"},
    {"from"},
    {"get"},{"got"},
    {"has"},{"had"},{"he"},{"have"},{"her"},{"here"},{"him"},{"himself"},{"his"},{"how"},
    {"in"},{"into"},{"is"},{"it"},
    {"like"},
    {"make"},{"many"},{"me"},{"might"},{"more"},{"most"},{"much"},{"must"},{"my"},
    {"never"},{"now"},
    {"of"},{"on"},{"only"},{"or"},{"other"},{"our"},{"out"},{"over"},
    {"said"},{"same"},{"see"},{"should"},{"since"},{"some"},{"still"},{"such"},
    {"take"},{"than"},{"that"},{"the"},{"their"},{"them"},{"then"},{"there"},{"these"},{"they"},{"this"},{"those"},{"to"},{"too"},
    {"under"},{"up"},
    {"very"},
    {"was"},{"way"},{"we"},{"well"},{"were"},{"what"},{"where"},{"which"},{"who"},{"with"},{"would"},
    {"you"},{"your"}
};

struct tree_node {
    char *word;
    int line_number;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *addtree(struct tree_node *, char *);
char *str_dup(char *);
int get_word_line(char *);
void treeprint(struct tree_node *);
int get_ch(void);
void unget_ch(int);

#define MAX 200
int too_much_noise = 0, line_no = 0, line_ref = 1;

int main(void)
{
    struct tree_node *root;
    char words[MAX];
    while(get_word_line(words) != EOF)
    {
        if(too_much_noise == 0)
        {
            root = addtree(root, words);
        }
        else if(too_much_noise == 1)
        {
            too_much_noise = 0;
            continue;
        }
    }
    treeprint(root);
    return 0;
}

int get_word_line(char *take_word)
{
    int get_word, i;
    char *w = take_word;
    char *check;
    char for_check[MAX];
    check = for_check;
    if((get_word = get_ch()) != EOF)
    {
        *w++ = (char)get_word;
        *check++ = (char)get_word;
    }
    else
    {
        return EOF;
    }
    if(get_word == '\n')
    {
        line_no = 1;
        too_much_noise = 1;
        return -2;
    }
    while(isspace(get_word = get_ch()))
    {
        ;
        get_word = get_ch();
    }
    while(isalnum(get_word))
    {
        *w++ = (char)get_word;
        *check++ = (char)get_word;
        get_word = get_ch();
    }
    if(get_word == '\n')
    {
        unget_ch(get_word);
    }
    *w = '\0';
    *check = '\0';
    check = for_check;
    for(i = 0; i < 99; i++)
    {
        if(strcmp(check, noise_words[i].noises) == 0)
        {
            too_much_noise = 1;
        }
    }
    return (check[0]);
}

struct tree_node *
addtree(struct tree_node *p, char *add_word)
{
    int condition;
    if(p == NULL)
    {
        p = malloc(sizeof(struct tree_node));
        p -> word = str_dup(add_word);
        if(line_no == 1)
        {
            line_no = 0;
            line_ref++;
        }
        p->line_number = line_ref;
        p -> left = p -> right = NULL;
    }
    else if((condition = strcmp(add_word, p->word)) < 0)
    {
        p ->left = addtree(p->left, add_word);
    }
    else if((condition = strcmp(add_word, p->word)) > 0)
    {
        p ->right = addtree(p->right, add_word);
    }
    return p;
}

char *str_dup(char *s)
{
    char *safe_storage;
    safe_storage = malloc(strlen(s) + 1); // +1 for '\0'
    if(safe_storage != NULL)
    {
        strcpy(safe_storage, s);
    }
    return safe_storage;
}

void treeprint(struct tree_node *ptr)
{
    if(ptr != NULL)
    {
        treeprint(ptr->left);
        printf("%s : %d\n", ptr->word, ptr->line_number);
        treeprint(ptr->right);
    }
}

char buffer[MAX];
int buf = 0;

int get_ch(void)
{
    return (buf > 0) ? buffer[--buf] : getchar();
}

void unget_ch(int c)
{
    if(buf < MAX)
    {
        buffer[buf++] = c;
    }
}