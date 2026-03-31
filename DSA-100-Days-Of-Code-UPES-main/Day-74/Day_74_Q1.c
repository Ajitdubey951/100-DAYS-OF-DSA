#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void findWinner(int n, char **votes)
{
    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int maxVotes = 0;

    int currentCount = 1;
    char *currentName = votes[0];

    for (int i = 1; i <= n; i++)
    {
        if (i < n && strcmp(votes[i], currentName) == 0)
        {
            currentCount++;
        }
        else
        {
            if (currentCount > maxVotes)
            {
                maxVotes = currentCount;
                winner = currentName;
            }

            if (i < n)
            {
                currentName = votes[i];
                currentCount = 1;
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);
}

int main()
{
    int n;
    scanf("%d", &n);
    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        votes[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", votes[i]);
    }

    findWinner(n, votes);

    for (int i = 0; i < n; i++)
        free(votes[i]);
    free(votes);
    return 0;
}