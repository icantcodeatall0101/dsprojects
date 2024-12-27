#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a Structure to represent a book
struct Book {
    int id;
    char title[100];
    char author[50];
    int isAvailable;
    struct Book* next;
};

// defining a Structure to represent the queue
struct Queue {
    struct Book* front;
    struct Book* rear;
};

// dynamic memo allocation of a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

//it  Checks if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// it adds Function to add multiple books
void addBooks(struct Queue* queue) {
    int n;
    printf("\nEnter number of books to add: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
        printf("\nEnter details for Book %d:\n", i+1);
        
        printf("Enter Book ID: ");
        scanf("%d", &newBook->id);
        
        printf("Enter Book Title: ");
        scanf(" %s", newBook->title);
        
        printf("Enter Author Name: ");
        scanf(" %s", newBook->author);
        
        newBook->isAvailable = 1;//checks the books availablity if property of newly created book becomes 1,,indicating that its available for borrowing
        newBook->next = NULL;
        
        // Add to queue
        if (isEmpty(queue)) {
            queue->front = queue->rear = newBook;// what happens here is that it checks if the q is empty if yes then the book becomes the rear nd front
        } else {
            queue->rear->next = newBook;//if q isnt full then rear's next is  given as rhe new book
            queue->rear = newBook;//new book is init as rear
        }
        
        printf("Book %d added successfully!\n", i+1);
    }
    printf("\nAll %d books have been added to the library!\n", n);
}

// Function to display all books
void displayBooks(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    //initializes pointer current to the front of q for traversing
    struct Book* current = queue->front;
    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tStatus\n");
    printf("------------------------------------------------\n");
    
    while (current != NULL) {
        printf("%d\t%s\t\t%s\t\t%s\n", 
            current->id, 
            current->title, 
            current->author,
            current->isAvailable ? "Available" : "Borrowed");
        current = current->next;
    }
}

// Function to search by author
void searchByAuthor(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    
    char searchAuthor[50];
    printf("\nEnter author name to search: ");
    scanf(" %s", searchAuthor);
    
    struct Book* current = queue->front;
    int found = 0;
    
    while (current != NULL) {
        if (strcasecmp(current->author, searchAuthor) == 0) {//strcasecmp we use for case sensitivity or here we use to check the authors name with case variations
            if (!found) {
                printf("\nBooks by %s:\n", searchAuthor);
                printf("ID\tTitle\t\tStatus\n");
                printf("--------------------------------\n");
            }
            printf("%d\t%s\t\t%s\n", 
                current->id, 
                current->title,
                current->isAvailable ? "Available" : "Borrowed");
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("\nNo books found by author: %s\n", searchAuthor);
    }
}

// Function to borrow a book
void borrowBook(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    
    int bookId;
    printf("\nEnter Book ID to borrow: ");
    scanf("%d", &bookId);
    
    struct Book* current = queue->front;
    while (current != NULL) {
        if (current->id == bookId) {
            if (current->isAvailable) {
                current->isAvailable = 0;
                printf("\nBook '%s' has been borrowed successfully!\n", current->title);
                return;
            } else {
                printf("\nThis book is already borrowed!\n");
                return;
            }
        }
        current = current->next;
    }
    printf("\nBook not found!\n");
}

// Function to return a book
void returnBook(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    
    int bookId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &bookId);
    
    struct Book* current = queue->front;
    while (current != NULL) {
        if (current->id == bookId) {
            if (!current->isAvailable) {
                current->isAvailable = 1;
                printf("\nBook '%s' has been returned successfully!\n", current->title);
                return;
            } else {
                printf("\nThis book is already in the library!\n");
                return;
            }
        }
        current = current->next;
    }
    printf("\nBook not found!\n");
}

// Function to delete a book
void deleteBook(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    
    int choice;
    printf("\n1. Delete by ID\n2. Delete by Title\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        int bookId;
        printf("Enter Book ID to delete: ");
        scanf("%d", &bookId);
        
        struct Book* current = queue->front;
        struct Book* prev = NULL;
        
        while (current != NULL) {
            if (current->id == bookId) {
                if (prev == NULL) {
                    queue->front = current->next;
                    if (queue->front == NULL) queue->rear = NULL;
                } else {
                    prev->next = current->next;
                    if (current == queue->rear) queue->rear = prev;
                }
                free(current);
                printf("\nBook deleted successfully!\n");
                return;
            }
            prev = current;
            current = current->next;
        }
        printf("\nBook not found!\n");
    } else if (choice == 2) {
        char title[100];
        printf("Enter Book Title to delete: ");
        scanf(" %s", title);
        
        struct Book* current = queue->front;
        struct Book* prev = NULL;
        
        while (current != NULL) {
            if (strcmp(current->title, title) == 0) {
                if (prev == NULL) {
                    queue->front = current->next;
                    if (queue->front == NULL) queue->rear = NULL;
                } else {
                    prev->next = current->next;
                    if (current == queue->rear) queue->rear = prev;
                }
                free(current);
                printf("\nBook deleted successfully!\n");
                return;
            }
            prev = current;
            current = current->next;
        }
        printf("\nBook not found!\n");
    }
}

int main() {
    struct Queue* libraryQueue = createQueue();
    int choice;
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Books\n");
        printf("2. Display All Books\n");
        printf("3. Search by Author\n");
        printf("4. Borrow Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addBooks(libraryQueue); break;
            case 2: displayBooks(libraryQueue); break;
            case 3: searchByAuthor(libraryQueue); break;
            case 4: borrowBook(libraryQueue); break;
            case 5: returnBook(libraryQueue); break;
            case 6: deleteBook(libraryQueue); break;
            case 7: printf("\nThank you for using the Library Management System!\n"); break;
            default: printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    // Free allocated memory before exiting
    while (!isEmpty(libraryQueue)) {
        struct Book* temp = libraryQueue->front;
        libraryQueue->front = libraryQueue->front->next;
        free(temp);
    }
    free(libraryQueue);
    
    return 0;
}
