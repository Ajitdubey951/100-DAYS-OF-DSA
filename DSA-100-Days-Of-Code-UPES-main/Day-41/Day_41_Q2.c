#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char *tasks, int tasksSize, int n)
{
    int freq[26] = {0};
    int maxFreq = 0;
    int maxFreqCount = 0;

    for (int i = 0; i < tasksSize; i++)
    {
        int index = tasks[i] - 'A';
        freq[index]++;
        if (freq[index] > maxFreq)
        {
            maxFreq = freq[index];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == maxFreq)
        {
            maxFreqCount++;
        }
    }

    int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;

    return MAX(intervals, tasksSize);
}