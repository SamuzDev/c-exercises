/*
 * 2. Given the duration of a call in minutes, calculate its cost,
 * considering:
 *   - Up to three minutes, the cost is 50.
 *   - Above three minutes, the cost is 50 plus 15 for each minute
 *     beyond the first three.
 */

#include <stdio.h>

int main() {
    float minutes, cost;

    printf("Enter the call duration in minutes: ");
    if (scanf("%f", &minutes) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (minutes < 0) {
        printf("The number of minutes cannot be negative.\n");
        return 1;
    }

    // Assumption: partial minutes are charged proportionally
    // (e.g. 3.5 minutes costs 50 + 15 * 0.5 = 57.50).
    if (minutes <= 3) {
        cost = 50;
    } else {
        cost = 50 + 15 * (minutes - 3);
    }

    printf("The cost is: %.2f\n", cost);

    return 0;
}
