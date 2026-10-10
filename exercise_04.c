/*
 * 4. Design the algorithm that solves a second-degree equation:
 *
 *     ax^2 + bx + c = 0
 *
 * using the quadratic formula:
 *
 *     x = (-b ± sqrt(b^2 - 4ac)) / (2a)
 */

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant;

    printf("Enter the value of a: ");
    if (scanf("%f", &a) != 1) {
        printf("Error: enter a valid value for a.\n");
        return 1;
    }

    printf("Enter the value of b: ");
    if (scanf("%f", &b) != 1) {
        printf("Error: enter a valid value for b.\n");
        return 1;
    }

    printf("Enter the value of c: ");
    if (scanf("%f", &c) != 1) {
        printf("Error: enter a valid value for c.\n");
        return 1;
    }

    if (a == 0) {
        printf("Error: a cannot be zero.\n");
        return 1;
    }

    discriminant = b * b - 4 * a * c;
    printf("The discriminant is: %f\n", discriminant);

    if (discriminant > 0) {
        printf("The equation has two real solutions.\n");
    } else if (discriminant == 0) {
        printf("The equation has one real solution.\n");
    } else {
        printf("The equation has no real solutions.\n");
    }

    if (discriminant >= 0) {
        float x1 = (-b + sqrtf(discriminant)) / (2 * a);
        float x2 = (-b - sqrtf(discriminant)) / (2 * a);
        printf("The solutions are: x1 = %f, x2 = %f\n", x1, x2);
    }

    return 0;
}
