#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// introduce text analytics functions
float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

// main program
int main(void)
{
    // get text from user
    string s = get_string("Text: ");

    // print number of letters
    printf("The text is %f letter(s) long\n", count_letters(s));

    // print number of words
    printf("The text has %f word(s)\n", count_words(s));

    // print number of sentences
    printf("The text has %f sentence(s)\n", count_sentences(s));

    // average number of letters per 100 words
    float L = count_letters(s) * 100 / count_words(s);

    // average number of sentences per 100 words
    float S = count_sentences(s) * 100 / count_words(s);

    // calculate Coleman-Liau index given inputs defined above
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    printf("%f\n", L);
    printf("%f\n", S);

    // printf("grade is %i\n", grade);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i \n", grade);
    }
}

// define functions below
float count_letters(string text)
{
    int length = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            length++;
        }
    }
    return length;
}

float count_words(string text)
{
    int tally = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            tally++;
        }
    }
    if (tally > 0 || strlen(text) > 0)
    {
        tally += 1;
    }
    return tally;
}

float count_sentences(string text)
{
    int tally = 0;
    int n = strlen(text);

    for (int i = 0; i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            tally++;
        }
    }
    return tally;
}
