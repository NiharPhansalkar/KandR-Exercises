#include <stdio.h>
#include <math.h>

// Its just how the bits would look like and not actual bit manipulation.

void setbits(unsigned int, int, int, int);

int main(void)
{
    setbits(250, 16, 4, 10);
    return 0;
}

void setbits(unsigned int x,int p, int n, int y)
{
    int i = 31, j = 1, k = 0, xchng;
    int result[31], result_1[31];
    int final[n-1];
    while(i >= 0)
    {
        int bit = (j&y);
        bit = (bit/pow(2,k));
        result[k] = bit;
        k++;
        j = j<<1;
        i--;
    }
    for(int counter = 31; counter>=0; counter--)
    {
        printf("%2d", result[counter]);
    }
    printf("\n");

    i = 0, j = 1, k = 0;
    while(i < n)
    {
        int bit_1 = (j&y);
        final[k] = (bit_1/pow(2,k));
        k++;
        j = j<<1;
        i++;
    }
    for(int counter = n-1; counter >= 0; counter--)
    {
        printf("%2d", final[counter]);
    }
    printf("\n");
    printf("\n");

    i = 31, j = 1, k = 0;
    while(i >= 0)
    {
        int bit = (j&x);
        bit = (bit/pow(2,k));
        result_1[k] = bit;
        k++;
        j = j<<1;
        i--;
    }
    for(int counter = 31; counter>=0; counter--)
    {
        printf("%2d", result_1[counter]);
    }
    printf("\n");

    k = 0;

    for(xchng = p-1; xchng < p+n; xchng++)
    {
        result_1[xchng] = final[k];
        k++;
    }    

    for(int counter = 31; counter>=0; counter--)
    {
        printf("%2d", result_1[counter]);
    }
    printf("\n");
}
