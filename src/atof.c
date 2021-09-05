#include <stdio.h>
#include <math.h>
//Program to convert character to floating point number.

//Using pointers.

double a_to_f(char *);

int main (void)
{
    char s[50] = "95.84";
    printf("%f\n", a_to_f(s));
    return 0;
}

double a_to_f(char *chr_in)
{
    char *traverse_arr = chr_in;
    int counter_i = 0, counter_f = 0, i = 0;
    double answer_i = 0, answer_f = 0, answer;
    while(*traverse_arr++ != '.') //Counter numbers upto the decimal point.
    {
        counter_i++;
    }
    traverse_arr = chr_in;
    while(i < counter_i)
    {
        answer_i = (10 * (answer_i)) + (double)((*traverse_arr++) - '0');
        i++;
    }
    while(*traverse_arr++ != '\0') //Counter numbers after the decimal point.
    {
        counter_f++;
    }
    traverse_arr = &chr_in[counter_i + 1];
    i = 0;
    while(i < counter_f - 1)
    {
        answer_f = (10 * (answer_f)) + (double)((*traverse_arr++) - '0');
        i++;
    }
    answer_f = (answer_f/pow(10, (counter_f - 1)));
    answer = answer_i + answer_f;
    return answer;
}

// Without pointers. Just for reference.

/*double atof(char []);

int main(void)
{
    char input[50] = "5253.456e-2";
    printf("%f\n", atof(input));
    return 0;
}

double atof(char s[])
{
    double val, temp = 10, bfour_deci, after_deci = 0, epower;
    int i = 0;
    double sign;
    int counter = 0;
    double j;
    int  count_decimal = 0;
    
    while (s[counter] != '\0')
    {
        if(s[counter] == 'e')
        {
            break;
        }
        counter++;
    }

    if(s[counter] == 'e')
    {
        sign = (s[counter+1] == '-') ? -1 : 1;
    }

    int ecount = counter+2;

    while(s[ecount] != '\0')
    {
        ecount ++;
    }

    while(s[count_decimal] != '.')
    {
        count_decimal++;
    }

    j = count_decimal - 1;

    for (i = 0; i< count_decimal; i++)
    {
        bfour_deci = bfour_deci + (s[i]-'0')*pow(temp, j);
        j--;
    }

    j = -1;

    for(i = count_decimal+1; i < counter; i++)
    {
        after_deci = after_deci + (s[i] - '0')*pow(temp, j);
        j--;
    }

    j = (ecount-(counter+2)) - 1;

    if(s[counter] == 'e')
    {
        for (i = counter+2; i < ecount; i++)
        {
            epower = epower + (s[i] - '0')*pow(temp, j);
            j--;
        }
    }

    val = after_deci + bfour_deci;
    if(s[counter] == 'e')
    {
        return(val*pow(temp, sign*epower));
    }
    else
    {
        return(val);
    }
}*/
