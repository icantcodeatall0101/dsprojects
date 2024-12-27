#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure for the doubly linked list
typedef struct Node {
    int price;               // Stock price
    struct Node *prev;       // Pointer to the previous node
    struct Node *next;       // Pointer to the next node
} Node;

// Doubly Linked List structure
typedef struct {
    Node *head;              // Pointer to the first node
    Node *tail;              // Pointer to the last node
} StockList;

// Function to initialize the stock list
void initializeList(StockList *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to add a stock price
void addStockPrice(StockList *list, int price) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->price = price;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (list->head == NULL) { // If the list is empty
        list->head = list->tail = newNode;
    } else { // Add the new node at the end
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("Added stock price: %d\n", price);
}

// Function to display stock prices
void displayStockPrices(StockList *list) {
    if (list->head == NULL) {
        printf("No stock prices available.\n");
        return;
    }

    printf("Stock Prices: ");
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->price);
        current = current->next;
    }
    printf("\n");
}

// Function to display stock prices in reverse order
void displayReverse(StockList *list) {
    if (list->tail == NULL) {
        printf("No stock prices available.\n");
        return;
    }

    printf("Stock Prices in Reverse: ");
    Node *current = list->tail;
    while (current != NULL) {
        printf("%d ", current->price);
        current = current->prev;
    }
    printf("\n");
}

// Function to find the highest and lowest stock prices in a range
void findMinMax(StockList *list) {
    if (list->head == NULL) {
        printf("No stock prices available.\n");
        return;
    }

    int maxPrice = INT_MIN, minPrice = INT_MAX;
    Node *current = list->head;

    while (current != NULL) {
        if (current->price > maxPrice) maxPrice = current->price;
        if (current->price < minPrice) minPrice = current->price;
        current = current->next;
    }

    printf("Highest Stock Price: %d\n", maxPrice);
    printf("Lowest Stock Price: %d\n", minPrice);
}

// Function to free the memory allocated for the list
void freeList(StockList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = list->tail = NULL;
}

int main() {
    StockList stockList;
    initializeList(&stockList);

    int choice, price;

    printf("Stock Market Tracker\n");
    printf("---------------------\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Stock Price\n");
        printf("2. Display Stock Prices\n");
        printf("3. Display Prices in Reverse\n");
        printf("4. Find Highest and Lowest Prices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock price to add: ");
                scanf("%d", &price);
                addStockPrice(&stockList, price);
                break;
            case 2:
                displayStockPrices(&stockList);
                break;
            case 3:
                displayReverse(&stockList);
                break;
            case 4:
                findMinMax(&stockList);
                break;
            case 5:
                freeList(&stockList);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
};