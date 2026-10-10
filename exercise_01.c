/*
 * 1. A worker has 10% deducted from their salary if the salary is less
 * than or equal to 1000. For the part above 1000 and up to 2000, 5% of
 * the additional amount is deducted, and for the part above 2000, 3% of
 * the additional amount is deducted. Calculate the discount and the net
 * salary the worker receives, given their salary.
 */

#include <stdio.h>

int main() {
    float salary, discount, net_salary;

    printf("Enter the salary: ");
    scanf("%f", &salary);

    // Assumption: the tiers are cumulative. Each percentage applies only
    // to the portion of the salary that falls within its tier.
    if (salary <= 1000) {
        discount = salary * 0.10;
    } else if (salary <= 2000) {
        // 10% of the first 1000 (= 100) + 5% of the amount above 1000
        discount = 100 + (salary - 1000) * 0.05;
    } else {
        // 100 + 5% of the next 1000 (= 50), plus 3% of the amount above 2000
        discount = 150 + (salary - 2000) * 0.03;
    }

    net_salary = salary - discount;

    printf("Net salary: %.2f\n", net_salary);
    printf("Discount: %.2f\n", discount);

    return 0;
}
