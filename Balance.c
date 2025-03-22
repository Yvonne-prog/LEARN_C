#include <stdio.h>

int main() {
    // Declare and initialize the initial account balance
    int initial_balance = 50000;

    // Declare and initialize the withdrawal amount
    int withdrawal = 20000;

    // Calculate the remaining balance after withdrawal
    int balance = initial_balance - withdrawal;

    // Output the resulting balance to the console
    printf("The balance after withdrawal is: %d\n", balance);

    // End the program
    return 0;
}