#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Program tail. Prints last n lines of input (n by default is 10, but can be modified using -n flag).
void tail_prog(int);

int main(int argc, char *argv[])
{
    int number_of_lines;
    printf("Please enter the - flag to give number of lines. If there are none, please only enter - for default of 10.\n");
    if(argv[1][0] == '-' && isdigit(argv[1][1]))                                        //Check if flag is given.
    {
        number_of_lines = isdigit(argv[1][1]);
    }
    else
    {
        number_of_lines = 10;
    }

    tail_prog(number_of_lines);
    
    return 0;
}

void tail_prog(int num_lines)
{
    int get_characters, string_number = 0, char_number = 0;
    int i, give_mem = 0;
    char *input_strings[50];                                                            //Array of 50 pointers.

    printf("\nPlease enter your lines.\n");

    for(; give_mem < 50; give_mem++)
    {
        input_strings[give_mem] = malloc(20 * sizeof(char*));                     //Allocate 20 bytes of memory to each string.
    }
    while((get_characters = getchar()) != EOF)                                          //Take input of strings.
    {
        if(islower(get_characters))
        {
            input_strings[string_number][char_number] = (char)get_characters;
            char_number++;
        }
        else if(isupper(get_characters))
        {
            input_strings[string_number][char_number] = (char)get_characters;
            char_number++;
        }
        else if(isdigit(get_characters))
        {
            input_strings[string_number][char_number] = get_characters - '0';
            char_number++;
        }
        else if(get_characters == ' ')
        {
            input_strings[string_number][char_number] = ' ';
            char_number++;
        }
        else if(get_characters == '\n')
        {
            input_strings[string_number][char_number+1] = '\0';
            string_number++;                                                            //Move to next pointer in the array, to allocate new string to a new ptr.
            char_number = 0;
        }
        else
        {
            break;
        }
    }

    if(num_lines == 10 && string_number > 9)
    {
        for(i = string_number; i>string_number - 11; i--)
        {
            printf("%s\n", input_strings[i]);
        }
    }
    else if (num_lines <= string_number)
    {
        for(i = string_number; i > string_number - num_lines; i--)
        {
            printf("%s\n", input_strings[i]);
        }
    }
    else
    {
        for(i = string_number; i>=0; i--)
        {
            printf("%s\n", input_strings[i]);
        }
    }
}
