#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push() {
    int item;
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW\n");
    } else {
        printf("Enter the element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Element %d pushed into the stack\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW\n");
    } else {
        printf("Element %d popped out of the stack\n", stack[top]);
        top--;
    }
}
void peek (){
    if (top ==-1){
        printf("\n Stack is underflow\n");
    }else {
        printf ("%d",stack [top]);
    }
}
void display() {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nSTACK MENU:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4 :
                display ();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

