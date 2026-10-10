/*
 * 8. Given a date in the format dd/mm/yyyy, write it in the format
 * dd/month/yy. For example, 4/09/2008 should be written as:
 * 4/September/2008
 */

#include <stdio.h>

int main() {
    int day, month, year;
    const char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Enter a date (dd/mm/yyyy): ");
    if (scanf("%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 1;
    }

    // Assumption: the year is printed with 4 digits, following the example
    // in the statement (the stated format says "yy", but the example shows 2008).
    printf("%d/%s/%d\n", day, month_names[month - 1], year);

    return 0;
}
