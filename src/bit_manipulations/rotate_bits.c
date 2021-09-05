#include <stdio.h>

//Program to rotate bits exercise 2-8
short rightrot(unsigned char x,char);

int main(void)
{
    printf("\nAfter rotation : %d\n", rightrot(4, 6));
    return 0;
}

short rightrot(unsigned char x, char n)
{
    short getbit, middle_man, setbits;
    getbit = (~(~0 << n)) & x;
    middle_man = (x >> n);
    setbits = (middle_man) | (getbit << (16-n));
    return (setbits);
}