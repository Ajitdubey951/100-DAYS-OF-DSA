#include <stdio.h>
#include <stdlib.h>

/* Comparison function for qsort */
int compare(const void *a, const void *b) {
    long long val_a = *(const long long *)a;
    long long val_b = *(const long long *)b;
    
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main() {
    /* Declare all variables at the top for maximum compiler compatibility */
    int n, i;
    int val;
    long long *prefix_sums;
    long long current_sum = 0;
    long long count = 0;
    long long current_streak = 1;
    
    /* Read the number of elements */
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    /* Allocate memory for the prefix sums array (size n + 1) */
    prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    if (prefix_sums == NULL) {
        return 1;
    }

    /* The sum before adding any elements is 0 */
    prefix_sums[0] = 0;

    /* Read the array elements and calculate running prefix sums */
    for (i = 0; i < n; i++) {
        scanf("%d", &val);          /* Read as standard int to avoid %lld parsing issues */
        current_sum += val;         /* Add to the long long running sum */
        prefix_sums[i + 1] = current_sum;
    }

    /* Sort the prefix sums array */
    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    /* Count how many times each prefix sum appears */
    for (i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            current_streak++;
        } else {
            count += (current_streak * (current_streak - 1)) / 2;
            current_streak = 1;
        }
    }
    
    /* Add the combinations for the final streak in the array */
    count += (current_streak * (current_streak - 1)) / 2;

    /* Print the final count */
    printf("%lld\n", count);

    /* Clean up */
    free(prefix_sums);

    return 0;
}