/*
 * 7. A local company distributes chemical supplies for a variety of uses.
 * As part of its sales policy, it has a discount program that depends on
 * the quantity of products each customer buys. For example, if a customer
 * buys more than 5 kg of product A, they receive a 5 percent discount on
 * the total value of their purchase. For product B, the discount is
 * 13 percent for purchases of more than 80 kg. Finally, for product C,
 * the policy is a 3 percent discount for every 600 grams purchased.
 *
 * The company needs a program that, given the quantities of the three
 * products each customer buys, calculates the discount the customer
 * is entitled to for their purchase.
 */

#include <stdio.h>

int main() {
    float product_a_kg, product_b_kg, product_c_kg;
    float discount_rate_a = 0;
    float discount_rate_b = 0;
    float discount_rate_c = 0;

    printf("Enter the quantity of product A (kg): ");
    if (scanf("%f", &product_a_kg) != 1 || product_a_kg < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the quantity of product B (kg): ");
    if (scanf("%f", &product_b_kg) != 1 || product_b_kg < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the quantity of product C (kg): ");
    if (scanf("%f", &product_c_kg) != 1 || product_c_kg < 0) {
        printf("Invalid input\n");
        return 1;
    }

    if (product_a_kg > 5) {
        discount_rate_a = 0.05;
    }

    if (product_b_kg > 80) {
        discount_rate_b = 0.13;
    }

    // Assumption: product C quantity is entered in kg, and the 3% is applied
    // proportionally (every 0.6 kg = 3%), not only per complete block.
    discount_rate_c = 0.03 * product_c_kg / 0.6;

    if (discount_rate_c > 1) {
        discount_rate_c = 1;
    }

    printf("Discount for product A: %.2f%%\n", discount_rate_a * 100);
    printf("Discount for product B: %.2f%%\n", discount_rate_b * 100);
    printf("Discount for product C: %.2f%%\n", discount_rate_c * 100);

    return 0;
}
