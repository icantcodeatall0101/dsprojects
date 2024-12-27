#include <stdio.h>
#include <string.h>

// Define the structure
struct stud {
    char name[50];
    int age;
    float marks;
};

// Function to update student details
void updatemarks(struct stud students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter the name of the student: ");
        scanf(" %s", students[i].name);  // Read a string with spaces
        printf("Enter the age of the student: ");
        scanf("%d", &students[i].age);  // Get the age
        printf("Enter the marks of the student: ");
        scanf("%f", &students[i].marks);  // Get the marks
    }
}

// Function to display student details
void display(struct stud students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDetails of student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct stud students[n];  // Declare an array of students

    // Update the student details with user input
    updatemarks(students, n);

    // Display the updated student details
    display(students, n);

    return 0;
}
