#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 > score2) printf("Player 1 wins!\n");
    else if (score2 > score1) printf("Player 2 wins!\n");
    else printf("Tie!\n");
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int total = 0, size = strlen(word);

    for (int i = 0; i < size; i++)
    {
        if(toupper(word[i]) == 'A') total += POINTS[0];
        else if(toupper(word[i]) == 'B') total += POINTS[1];
        else if(toupper(word[i]) == 'C') total += POINTS[2];
        else if(toupper(word[i]) == 'D') total += POINTS[3];
        else if(toupper(word[i]) == 'E') total += POINTS[4];
        else if(toupper(word[i]) == 'F') total += POINTS[5];
        else if(toupper(word[i]) == 'G') total += POINTS[6];
        else if(toupper(word[i]) == 'H') total += POINTS[7];
        else if(toupper(word[i]) == 'I') total += POINTS[8];
        else if(toupper(word[i]) == 'J') total += POINTS[9];
        else if(toupper(word[i]) == 'K') total += POINTS[10];
        else if(toupper(word[i]) == 'L') total += POINTS[11];
        else if(toupper(word[i]) == 'M') total += POINTS[12];
        else if(toupper(word[i]) == 'N') total += POINTS[13];
        else if(toupper(word[i]) == 'O') total += POINTS[14];
        else if(toupper(word[i]) == 'P') total += POINTS[15];
        else if(toupper(word[i]) == 'Q') total += POINTS[16];
        else if(toupper(word[i]) == 'R') total += POINTS[17];
        else if(toupper(word[i]) == 'S') total += POINTS[18];
        else if(toupper(word[i]) == 'T') total += POINTS[19];
        else if(toupper(word[i]) == 'U') total += POINTS[20];
        else if(toupper(word[i]) == 'V') total += POINTS[21];
        else if(toupper(word[i]) == 'W') total += POINTS[22];
        else if(toupper(word[i]) == 'X') total += POINTS[23];
        else if(toupper(word[i]) == 'Y') total += POINTS[24];
        else if(toupper(word[i]) == 'Z') total += POINTS[25];
    }

    return total;
}
