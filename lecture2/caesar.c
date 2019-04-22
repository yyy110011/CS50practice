#include <cs50.h>
#include <stdio.h>
#include <string.h>

//caesar.c
//Zun Ren, Yao
//20 April, 2019


// Check digit
int digitCheck(int argc, string argv[])
{
    int key = 0;
    char *p;
    string plaintext;
    int counter = 0;
    char temp;
    // Check the argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = strtol(argv[1], &p, 10);
        // Check the argument is integer
        if (p == argv[1] || *p != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        // Processing
        else
        {
            plaintext = get_string("plaintext:");
            printf("ciphertext:");
            while (plaintext[counter] != '\0')
            {
                temp = plaintext[counter];
                if (temp < 65 || (temp > 90 && temp < 97) || temp > 122)
                {
                    printf("%c", temp);
                }
                else
                {
                    //Upper case
                    if (temp >= 65 && temp <= 90)
                    {
                        printf("%c", (temp - 65 + key) % 26 + 65);
                    }
                    //lower case
                    if (temp >= 97 && temp <= 122)
                    {
                        printf("%c", (temp - 97 + key) % 26 + 97);
                    }
                }
                counter++;
            } 
            printf("\n");
        }
        return 0;
    }
}


int main(int argc, string argv[])
{
    return digitCheck(argc, argv);
}
