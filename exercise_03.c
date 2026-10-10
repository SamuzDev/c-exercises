/*
 * 3. Write an algorithm that gives the solution of a first-degree
 * equation:
 *
 *     ax + b = 0
 *
 * where, solving for x, we get x = -b / a.
 *
 * Analyzing the equation carefully, we observe that "a" must be different
 * from zero, otherwise the equation would have no solution. And if "a" is
 * equal to zero and "b" is also equal to zero, a mathematical
 * indeterminacy occurs.
 */

#include <stdio.h>

int main() {
    float a, b;

    printf("Enter the value of a: ");
    if (scanf("%f", &a) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the value of b: ");
    if (scanf("%f", &b) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (a == 0) {
        if (b == 0) {
            printf("Indeterminate equation: it has infinitely many solutions.\n");
        } else {
            printf("The equation has no solution.\n");
        }
    } else {
        float x = -b / a;
        printf("The solution is: x = %f\n", x);
    }

    return 0;
}
