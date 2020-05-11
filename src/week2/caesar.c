#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// start program
int main(int argc, string argcv[])
{
    // did user provide one extra argument?
    if (argc == 2)
    {
        int tally = 0;
        int n = strlen(argcv[1]);

        // is the extra argument made up of all digits?
        for (int i = 0; i < n; i++)
        {
            if (isdigit(argcv[1][i]))
            {
                tally++;
            }
        }

        // if it's all digits, proceed to ask for plain text
        if (tally == n)
        {
            int k = atoi(argcv[1]);

            string ptext = get_string("plaintext: ");
            int len = strlen(ptext);

            printf("ciphertext: ");

            // start the encription process, based on extra argument given by user
            for (int i = 0; i < len; i++)
            {
                // check if it's letters
                if (isalpha(ptext[i]))
                {
                    // check if uppercase
                    if (isupper(ptext[i]))
                    {
                        char c = ptext[i] - 65;
                        char c_i = ((c + k) % 26);
                        char c_i_def = c_i + 65;

                        printf("%c", c_i_def);
                    }
                    else
                    {
                        char c = ptext[i] - 97;
                        char c_i = ((c + k) % 26);
                        char c_i_def = c_i + 97;

                        printf("%c", c_i_def);
                    }
                }
                else
                {
                    char c = ptext[i];
                    printf("%c", c);
                }
            }
            printf("\n");
            return 0; // success
        }
        // if extra argument is not all digits
        else
        {
            printf("Usage: %s key\n", argcv[0]); // print error message to user
            return 1; // error
        }
        
    }
    // if extra argument is missing
    else
    {
        printf("Usage: %s key\n", argcv[0]);
        return 1; // error
    }
}