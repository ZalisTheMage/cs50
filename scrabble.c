#include <cs50.h>
#include <stdio.h>
#include <string.h>

int countPoints(char c);

int main(void)
{
    int sum1 = 0;
    int sum2 = 0;
    string word1 = get_string("Player 1: ");
    //loop for every single character in word
    for (int i = 0, n = strlen(word1); i < n; i++)
    {
        //counts the points for the word.
        sum1 += countPoints(word1[i]);
    }
    string word2 = get_string("Player 2: ");
    for (int j = 0, n2 = strlen(word2); j < n2; j++)
    {
        sum2 += countPoints(word2[j]);
    }
    //print results
    if (sum1 > sum2)
    {
        printf("Player 1 wins!\n ");
    }
    else if (sum1 < sum2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    printf("%i %i", sum1, sum2);
}

int countPoints(char c)
{
    const int arrayLenght = 7;
    // Score the points of a player
    string onePoint = "aAEeiIlLNnoOrRSstTuU";
    string twoPoints = "dDgG";
    string threePoints = "BbcCmMPp";
    string fourPoints = "fFhHvVWwyY";
    string fivePoints = "kK";
    string eightPoints = "JjxX";
    string tenPoints = "QqzZ";
    string array[] = {onePoint,twoPoints, threePoints, fourPoints, fivePoints, eightPoints, tenPoints};
    for (int i = 0; i < arrayLenght; i++)
    {
        for (int j = 0; j < strlen(array[i]); j++)
        {
            if (array[0][j] == c)
            {
                return 1;
            }
            else if (array[1][j] == c)
            {
                return 2;
            }
            else if (array[2][j] == c)
            {
                return 3;
            }
            else if (array[3][j] == c)
            {
                return 4;
            }
            else if (array[4][j] == c)
            {
                return 5;
            }
            else if (array[5][j] == c)
            {
                return 8;
            }
            else if (array[6][j] == c)
            {
                return 10;
            }
        }
    }
    return 0;
}
