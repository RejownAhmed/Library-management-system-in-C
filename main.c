#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create Structure of Library
struct library {
    char book_name[20];
    char author[20];
    int pages;
    float price;
};

// Function prototypes
void displayMenu();
void addBookInformation(struct library[], int*);
void displayBookInformation(struct library[], int);
void listBooksByAuthor(struct library[], int);
void listTotalBookCount(int);
void pressEnterToContinue();

int main() {
    struct library lib[100];
    int i, input, count;

    i = input = count = 0;

    // Iterate the loop
    while (input != 5) {
        displayMenu();

        // Enter the book details
        printf("\n\nEnter one of the above: ");
        scanf("%d", &input);

        // Process the input
        switch (input) {
            case 1:
                addBookInformation(lib, &count);
                pressEnterToContinue();
                break;

            case 2:
                displayBookInformation(lib, count);
                pressEnterToContinue();
                break;

            case 3:
                listBooksByAuthor(lib, count);
                pressEnterToContinue();
                break;

            case 4:
                listTotalBookCount(count);
                pressEnterToContinue();
                break;

            case 5:
                exit(0);
        }
    }

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n\n\n********Select an option********\n\n");
    printf("1. Add book information\n");
    printf("2. Display book information\n");
    printf("3. List all books of given author\n");
    printf("4. List the count of books in the library\n");
    printf("5. Exit");
}

// Function to add book information
void addBookInformation(struct library lib[], int *count) {
    printf("Enter book name = ");
    scanf("%s", lib[*count].book_name);

    printf("Enter author name = ");
    scanf("%s", lib[*count].author);

    printf("Enter pages = ");
    scanf("%d", &lib[*count].pages);

    printf("Enter price = ");
    scanf("%f", &lib[*count].price);

    (*count)++;
}

// Function to display book information
void displayBookInformation(struct library lib[], int count) {
    printf("\nYou have entered the following information:\n");
    for (int i = 0; i < count; i++) {
      
        printf("Book name: %s\nAuthor name: %s\nPages: %d\nPrice: %f\n\n",
               lib[i].book_name, lib[i].author, lib[i].pages, lib[i].price);
    }
}

// Function to list books by a given author
void listBooksByAuthor(struct library lib[], int count) {
    char authorName[30];
    printf("Enter author name: ");
    scanf("%s", authorName);

    printf("\n======Book Lists=====\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(authorName, lib[i].author) == 0) {
            printf("Id: %d\nName: %s\nAuthor: %s\nPages: %d\nPrice: %f\n\n",
                   i + 1, lib[i].book_name, lib[i].author, lib[i].pages, lib[i].price);
        } 
    }
}

// Function to list the total count of books
void listTotalBookCount(int count) {
    printf("\nNo of books in library: %d\n", count);
}

// Function to wait for user input (press enter to continue)
void pressEnterToContinue() {
    getchar(); // Clear the newline character
    printf("\nPress enter to continue: ");
    while (getchar() != '\n');
}
