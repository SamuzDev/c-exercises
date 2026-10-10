/*
 * 5. A company that develops user interfaces for mobile phones has decided
 * to create a new menu option that lets users automatically organize the
 * phone numbers in their contacts into groups. The grouping is based on a
 * study carried out by the company, which concluded that the following
 * groups should exist: Friends, Colleagues, Family, Business and Others.
 * The criteria for including a person in one group or another are:
 *
 * a. If the number of outgoing calls to a phone number is approximately
 *    equal to the number of incoming calls, and the number of outgoing
 *    calls is less than 5, the contact is classified in the Colleagues
 *    group.
 * b. If the number of incoming calls is greater than 10 times the number
 *    of outgoing calls, the contact belongs to the Family group.
 * c. If the number of outgoing calls to a phone number is approximately
 *    equal to the number of incoming calls from that number, or the number
 *    of outgoing calls is greater than 50, the contact is classified in
 *    the Friends group.
 *
 * The missing criteria must be completed in order to decide which group
 * each phone number belongs to, and the algorithm that implements this
 * menu option must be written so that phones can classify contacts
 * automatically.
 *
 * "Approximately" can be defined mathematically as:
 *
 *     a ≡ b : abs(a - b) < 2
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int calls_in, calls_out;

    printf("Enter number of calls out: ");
    if (scanf("%d", &calls_out) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter number of calls in: ");
    if (scanf("%d", &calls_in) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    if (calls_in < 0 || calls_out < 0) {
        printf("Invalid input\n");
        return 1;
    }

    // A contact with no calls in either direction has no data to classify
    if (calls_in == 0 && calls_out == 0) {
        printf("Group: Others\n");
        return 0;
    }

    // The criteria are checked in order, so the first one that matches wins.
    // Assumption: Business is not defined in the statement, so we define it
    // as many more incoming calls than outgoing (like Family), but with a low
    // total volume (fewer than 20 incoming calls).
    if (abs(calls_out - calls_in) < 2 && calls_out < 5) {
        printf("Group: Colleagues\n");
    } else if (calls_in > (calls_out * 10) && calls_in < 20) {
        printf("Group: Business\n");
    } else if (abs(calls_out - calls_in) < 2 || calls_out > 50) {
        printf("Group: Friends\n");
    } else if (calls_in > (calls_out * 10)) {
        printf("Group: Family\n");
    } else {
        printf("Group: Others\n");
    }

    return 0;
}
