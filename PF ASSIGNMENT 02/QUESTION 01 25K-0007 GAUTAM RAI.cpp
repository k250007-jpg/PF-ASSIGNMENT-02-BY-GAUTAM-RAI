#include <stdio.h>
#include <string.h>

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], float prices[], int quantities[], int count);
void lowStock(int isbns[], char titles[][50], float prices[], int quantities[], int count);
int findBook(int searchISBN, int isbns[], int count);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n===== Liberty Books Inventory =====\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, prices, quantities, count);
                break;
            case 3:
                lowStock(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= 100) {
        printf("Inventory full!\n");
        return;
    }

    int newISBN;
    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    if (findBook(newISBN, isbns, *count) != -1) {
        printf("Book with this ISBN already exists.\n");
        return;
    }

    isbns[*count] = newISBN;

    printf("Enter title: ");
    scanf(" %[^\n]", titles[*count]);

    printf("Enter price: ");
    scanf("%f", &prices[*count]);

    printf("Enter quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;
    printf("Book added successfully!\n");
}

void processSale(int isbns[], float prices[], int quantities[], int count) {
    int searchISBN, sold;

    printf("Enter ISBN of book sold: ");
    scanf("%d", &searchISBN);

    int index = findBook(searchISBN, isbns, count);
    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("Enter number of copies sold: ");
    scanf("%d", &sold);

    if (sold > quantities[index]) {
        printf("Not enough stock. Only %d left.\n", quantities[index]);
        return;
    }

    quantities[index] -= sold;
    printf("Sale complete. Total = %.2f\n", prices[index] * sold);
    printf("Remaining stock: %d\n", quantities[index]);
}

void lowStock(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int found = 0;
    printf("\n--- Low Stock (less than 5) ---\n");
    printf("ISBN\tTitle\t\tPrice\tQty\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("%d\t%-15s\t%.2f\t%d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No books are low on stock.\n");
}

int findBook(int searchISBN, int isbns[], int count) {
    for (int i = 0; i < count; i++) {
        if (isbns[i] == searchISBN)
            return i;
    }
    return -1;
}

