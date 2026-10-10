/*
 * 6. The company CASTELL has decided to implement a new salary system to
 * improve its organizational climate. The new raise rules are:
 *
 * a. If the employee is a laborer, the salary increases by 10 percent.
 * b. If the employee is an engineer and earns less than 1,000,000, the
 *    salary increases by 8 percent.
 * c. If the employee is an engineer and earns between 1,000,001 and
 *    2,000,000, the salary increases by 0.06.
 * d. If the employee is an engineer and earns between 2,000,001 and
 *    3,000,000, the salary increases by 5 percent.
 * e. If the employee is an engineer, earns between 3,000,001 and
 *    4,000,000, and is named Rupeto Jesus, the salary increases by 0.30.
 * f. If the employee is an engineer and earns more than 4,000,000, the
 *    salary increases by 8 percent.
 * g. If the employee is an advertiser and earns more than 1,500,000, the
 *    salary increases by 150,000.
 * h. If the employee is a manager, the salary increases by 5 percent for
 *    each letter in the name.
 * i. If a case is not covered by any of the previous rules, the salary
 *    increases by 0.02.
 *
 * Optional: if the employee's last name is Intrepido, they receive an
 * additional 10 percent on top of the previous rules.
 *
 * Develop an algorithm that implements these changes to the salary system
 * and displays on screen the employee's name, position, initial salary,
 * raise, and final salary.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[50], position[20];
    double current_salary, final_salary, raise_amount;

    printf("Enter the employee's name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == 0) {
        printf("Error: No name was entered. The program will now exit.\n");
        return 1;
    }

    printf("Enter the current salary: ");
    if (scanf("%lf", &current_salary) != 1) {
        printf("Error: Invalid salary.\n");
        return 1;
    }

    if (current_salary <= 0) {
        printf("Error: The salary must be greater than zero.\n");
        return 1;
    }

    printf(
        "Select the employee's position:\n"
        "1. Laborer\n"
        "2. Engineer\n"
        "3. Advertiser\n"
        "4. Manager\n"
        "5. Other\n"
        "Option: "
    );

    int option;
    if (scanf("%d", &option) != 1) {
        printf("Error: Invalid option.\n");
        return 1;
    }

    // Count letters in the name (ignores spaces; counts accented
    // UTF-8 letters once by checking only their first byte)
    int letter_count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        unsigned char c = name[i];
        if (isalpha(c) || c >= 0xC0) {
            letter_count++;
        }
    }

    switch (option) {
        case 1:
            strcpy(position, "Laborer");
            raise_amount = current_salary * 0.1;
            break;
        case 2:
            strcpy(position, "Engineer");
            // A salary of exactly 1,000,000 matches neither rule b nor c,
            // so it falls to rule i (default 2% raise)
            if (current_salary < 1000000) {
                raise_amount = current_salary * 0.08;
            } else if (current_salary >= 1000001 && current_salary <= 2000000) {
                raise_amount = current_salary * 0.06;
            } else if (current_salary > 2000000 && current_salary <= 3000000) {
                raise_amount = current_salary * 0.05;
            } else if (current_salary > 3000000 && current_salary <= 4000000
                       && strcmp(name, "Rupeto Jesus") == 0) {
                raise_amount = current_salary * 0.3;
            } else if (current_salary > 4000000) {
                raise_amount = current_salary * 0.08;
            } else {
                raise_amount = current_salary * 0.02;
            }
            break;
        case 3:
            strcpy(position, "Advertiser");
            if (current_salary > 1500000) {
                raise_amount = 150000;
            } else {
                raise_amount = current_salary * 0.02;
            }
            break;
        case 4:
            strcpy(position, "Manager");
            raise_amount = current_salary * (letter_count * 0.05);
            break;
        case 5:
            strcpy(position, "Other");
            raise_amount = current_salary * 0.02;
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    // Case-insensitive check for the "Intrepido" last name (+10% extra)
    char name_lower[50];
    int j;
    for (j = 0; name[j] != '\0'; j++) {
        name_lower[j] = tolower((unsigned char)name[j]);
    }
    name_lower[j] = '\0';

    if (strstr(name_lower, "intrepido") != NULL || strstr(name_lower, "intrépido") != NULL) {
        raise_amount += current_salary * 0.1;
    }

    final_salary = current_salary + raise_amount;

    printf("Name: %s\n", name);
    printf("Position: %s\n", position);
    printf("Initial salary: %.2f\n", current_salary);
    printf("Raise applied: %.2f\n", raise_amount);
    printf("Final salary: %.2f\n", final_salary);

    return 0;
}
