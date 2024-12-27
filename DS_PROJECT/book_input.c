#include<stdio.h>
#include<string.h>

struct book{
    char book_name[100];
    int book_id;
    char author[100];
    int isAvailable
};

struct node{
    struct book data;
    struct node*next;   
    };

struct queue{
        struct node*front;
         struct node*rear;
    };
struct queue* createqueue(){
    struct queue*queue=(struct queue*)malloc(sizeof(struct queue));
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}
int isEmpty(struct queue* queue){
    return(queue->front==NULL);
}
void add_book(struct queue* queue)
{
    int n;
    printf("enter the total number of books to add=");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct book*newbook=(struct book*)malloc(sizeof(struct book));
         printf("\nenter the details of the book %d\n",i+1);
    printf("enter id of book:");
    scanf("%d",newbook->book_id);
    printf("enter the title of the book:");
    scanf("%s",newbook->book_name);
    printf("enter the authors name:");
    scanf("%s",newbook->author);
    
}

}