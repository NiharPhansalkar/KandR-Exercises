#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
enum {NAME, PAREN, BRACKETS};
//Function declarations.
int gettoken(void);
void my_dcl(void);
void my_dirdcl(void);
int get_ch(void);
char out[MAX];
char datatype[MAX];
void unget_ch(int);
//Global variables.
char buf[MAX];
int buffer = 0;
char token[MAX];
int tokentype;
char name[MAX];

int main(void){
    printf("Please enter your expression.\n");
    while(gettoken() != '\n')
    {
        strcpy(datatype, token);
        my_dcl();
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int get_ch(void){
    return (buffer > 0 ? buf[--buffer] : getchar());
}

void unget_ch(int c){
    if(buffer > MAX)
    {
        printf("Buffer full.\n");
    }
    else
    {
        buf[buffer++] = (char)c;
    }
}

int gettoken(void){
    char *ptr = token;
    int c;
    while((c = get_ch()) == ' ' || c == '\t')
        ;
    if(c == '('){
        if((c = get_ch()) == ')'){
            return tokentype = PAREN;
        }
        else{
            unget_ch(c);
            return tokentype = '(';
        }
    }
    else if(c == '['){
        for(*ptr++ = (char)c; (*ptr++ = get_ch()) != ']'; )
                ;
        *ptr = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)){
        for(; isalnum(c); ){
            *ptr++ = (char)c;
            c = get_ch(); 
        }
        *ptr = '\0';
        unget_ch(c);
        return tokentype = NAME;
    }
    else{
        tokentype = c;
        return tokentype;  
    }
}

void my_dcl(void){
    int stars;
    for(stars = 0; gettoken() == '*'; ){
        stars++;
    }
    my_dirdcl();

    while(stars-- > 0){
        strcat(out, " pointer to ");
    }
}

void my_dirdcl(void){
    int type;

    if(tokentype == '('){
        my_dcl();
        if(tokentype != ')')
            printf("Check bracktes. Please enter a valid expression.\n");
    }
    else if(tokentype == NAME){
        strcpy(name, token);
    }
    while((type = gettoken()) == PAREN || type == BRACKETS){
        if(type == PAREN){
            strcat(out, " function returning ");
        }
        else{
            strcat(out, " array ");
            strcat(out, token);
            strcat(out, " of ");
        }
    }
}