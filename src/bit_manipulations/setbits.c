#include <stdio.h>

//Program setbits exercise 2-6.
int setbits(unsigned int x, int, int, int);

int main(void)
{
    printf("After modifications : %d\n",setbits(1057,9,3,6));
    return 0;
}

int setbits(unsigned int x, int p, int n, int y)
{
    int getbits, setb;
    printf("Numbers before : %d\n %d\n", x,y);
    getbits = (~(~0 << n)) & y;
    setb = x | (getbits<<(p-n));
    return (setb);
}