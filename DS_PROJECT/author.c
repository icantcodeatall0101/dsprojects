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
        if (strcasecmp(current->author, searchAuthor) == 0) {
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