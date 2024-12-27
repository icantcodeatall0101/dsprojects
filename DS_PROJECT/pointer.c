#include<stdio.h>
int main(){
int *bund;
int a=5;
bund=&a;
printf("%d\n",*bund);//dereferencing=showing the value



//using arrow pointer = arrow-> is mainly used to refer the components from a structure
struct p
{ int x, y;};

struct p anything={10,20};//it is a reference to struct p here think of "struct p" as data type
struct p *ptr= &anything;// here we make a pointer that points to the variable "anything"
printf("%d\n",ptr->x);//dereferemcing using -> PRINTS VALUE OF X

//using '.' pointer = it is used to refer a pointer directly insted of assigning a '*pointer' and then dereferencing it
printf("%d",anything.x);// gives output but remember to make a struct pointer
}
