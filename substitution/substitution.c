#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool nonRepeat(string s);
bool onlyAlpha(string s);
char substitution(char c, string s);

int main(int argc, string argv[])
{
// check if there's only 1 command-line argument, if the key has only alphabetical ,if the key has a lenght of 26, and if there's only 1 of each character.
    if (argc != 2 || onlyAlpha(argv[1]) == false || strlen(argv[1]) != 26 || nonRepeat(argv[1]) == false)
    {
        printf("./substitution key\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if (isupper(text[i]) != 0)
            {
                char encrypted = toupper(substitution(text[i], argv[1]));
                printf("%c", encrypted);
            }
            else
            {
                char encrypted = tolower(substitution(text[i], argv[1]));
                printf("%c", encrypted);
            }
        }
        printf("\n");
        return 0;
    }
}
// check if the command-line argument has only alphabetical characters
bool onlyAlpha(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

// check if there's repeated characters
bool nonRepeat(string s)
{
    for (int j = 0, n = strlen(s) - 1; j < n; j++)
    {
        for (int i = j + 1, m = strlen(s); i < m; i++)
        {
            if (toupper(s[j]) == toupper(s[i]))
            {
                return false;
            }
        }
    }
    return true;
}

//substitutes the character
char substitution(char c, string s)
{
    if (isupper(c) != 0)
    {
        c = c - 65;
        return s[(int) c];
    }
    else if (islower(c) != 0)
    {
        c = c - 97;
        return s[(int) c];
    }
    else
    {
        return c;
    }
}
