#include <stdio.h>
#include <string.h>

// Define the structure
struct stud {
    char name[50];
    int age;
    float marks;
};

// Function to update student details
void updatemarks(struct stud *student,int n) {
  
    {
    printf("Enter the name of the student: ");
    scanf(" %s", student->name);  // Read a string with spaces
    printf("Enter the age of the student: ");
    scanf("%d", &student->age);  // Get the age
    printf("Enter the marks of the student: ");
    scanf("%f", &student->marks);  // Get the marks
    printf("\n");
}
}

// Function to display student details
void display(struct stud *student,int n) {

    for(int i=0;i<n;i++)
    {
    printf("\nThe name of student: %s\n", student->name);
    printf("The age of student: %d\n", student->age);
    printf("The marks of student: %.2f\n", student->marks);
}
}
int main() {
    int n;
    printf("enter the no.of books u need to store=");
    scanf("%d",&n);

    struct stud mithun[n];  // Declare a student instance

    // Update the student details with user input
    updatemarks(mithun,n);

    // Display the updated student details
    display(mithun,n);

    return 0;
}
