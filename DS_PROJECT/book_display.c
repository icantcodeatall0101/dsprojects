void displayBooks(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nNo books in library!\n");
        return;
    }
    
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