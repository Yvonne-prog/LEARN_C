#include <stdio.h>

#define TOTAL_BOOKS 5

// Function to check book availability
// Returns: 1 = available, 0 = borrowed, -1 = not found
int checkAvailability(int bookId, int availableBooks[], int originalBooks[]) {
    for (int i = 0; i < TOTAL_BOOKS; i++) {
        if (originalBooks[i] == bookId) {
            if (availableBooks[i] == 0)
                return 0;  // Borrowed
            else
                return 1;  // Available
        }
    }
    return -1; // Not found
}

// Function to borrow a book
void borrowBook(int bookId, int availableBooks[], int originalBooks[]) {
    for (int i = 0; i < TOTAL_BOOKS; i++) {
        if (originalBooks[i] == bookId) {
            if (availableBooks[i] == 0) {
                printf("Book %d is already borrowed.\n", bookId);
                return;
            } else {
                availableBooks[i] = 0; // Mark as borrowed
                printf("Book %d has been borrowed.\n", bookId);
                return;
            }
        }
    }
    printf("Book %d does not exist in the system.\n", bookId);
}

// Function to return a book
void returnBook(int bookId, int availableBooks[], int originalBooks[]) {
    for (int i = 0; i < TOTAL_BOOKS; i++) {
        if (originalBooks[i] == bookId) {
            if (availableBooks[i] == 0) {
                availableBooks[i] = bookId; // Return the book
                printf("Book %d has been returned.\n", bookId);
            } else {
                printf("Book %d was not borrowed.\n", bookId);
            }
            return;
        }
    }
    printf("Book %d does not exist in the system.\n", bookId);
}

// Function to display all books and their status
void displayAvailability(int availableBooks[], int originalBooks[]) {
    printf("\nBook Availability:\n");
    for (int i = 0; i < TOTAL_BOOKS; i++) {
        if (availableBooks[i] != 0) {
            printf("Book ID: %d - Available\n", availableBooks[i]);
        } else {
            printf("Book ID: %d - Borrowed\n", originalBooks[i]);
        }
    }
}

// Main function
int main() {
    int availableBooks[TOTAL_BOOKS] = {101, 102, 103, 104, 105};
    int originalBooks[TOTAL_BOOKS] = {101, 102, 103, 104, 105};
    int choice, bookId, bookStatus;

    do {
        printf("\nLibrary Menu\n");
        printf("1. Check Availability\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. Show All Books Availability\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter book ID to check: ");
                if (scanf("%d", &bookId) != 1) {
                    printf("Invalid input. Please enter a valid book ID.\n");
                    while (getchar() != '\n');
                    break;
                }
                bookStatus = checkAvailability(bookId, availableBooks, originalBooks);
                if (bookStatus == 1) {
                    printf("Book %d is available.\n", bookId);
                } else if (bookStatus == 0) {
                    printf("Book %d exists but is currently borrowed.\n", bookId);
                } else {
                    printf("Book %d does not exist in the system.\n", bookId);
                }
                break;

            case 2:
                printf("Enter book ID to borrow: ");
                if (scanf("%d", &bookId) != 1) {
                    printf("Invalid input. Please enter a valid book ID.\n");
                    while (getchar() != '\n');
                    break;
                }
                borrowBook(bookId, availableBooks, originalBooks);
                break;

            case 3:
                printf("Enter book ID to return: ");
                if (scanf("%d", &bookId) != 1) {
                    printf("Invalid input. Please enter a valid book ID.\n");
                    while (getchar() != '\n');
                    break;
                }
                returnBook(bookId, availableBooks, originalBooks);
                break;

            case 4:
                displayAvailability(availableBooks, originalBooks);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}