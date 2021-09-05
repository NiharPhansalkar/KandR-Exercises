#include <stdio.h>

//Program invert exercise 2-7 (Very imp. EXOR application).
int invert (unsigned int x, int, int);

int main(void)
{
    printf("\nResult is : %d\n", invert(102, 5, 4));
    return 0;
}

int invert(unsigned int x, int p, int n)
{
    int store;
    store = x ^ ((~(~0 << n)) << (p-1));
    return (store);
}