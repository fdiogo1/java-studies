#include <stdio.h>
#include <cs50.h>

float average(int array[]);

const int N = 3; // it will not change

int main(void)
{
    // WITHOUT ARRAY

    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    //printf("Average: %f\n", (score1 + score2 + score3) / (float) 3);


    //int scores[3] = {72, 73, 33};
    // scores[0] = 72;
    // scores[1] = 73;
    // scores[2] = 33;

    int score[N];

    for(int i = 0; i < N; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf("Average: %.2f\n", average(score));
}

float average(int array[])
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += array[i];
    }
    return sum / (float) N;
}
