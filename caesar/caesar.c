#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool onlyDigits(string);
char rotate(char c, int amount);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (onlyDigits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string text = get_string("plaintext: ");
        printf("\nciphertext: ");
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            char encrypted = rotate(text[i], key);
            printf("%c", encrypted);
        }
        printf("\n");
    }
}

bool onlyDigits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int amount)
{
    if (isalpha(c) == 0)
    {
        return c;
    }
    else if (isupper(c) != 0)
    {
        c = c - 65;
        c = (c + amount) % 26;
        c = c + 65;
        return c;
    }
    else
    {
        c = c - 97;
        c = (c + amount) % 26;
        c = c + 97;
        return c;
    }
}
