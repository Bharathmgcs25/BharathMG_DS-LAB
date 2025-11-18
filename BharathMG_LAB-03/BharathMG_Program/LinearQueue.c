 #include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", item);
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = item;
    printf("Enqueued: %d\n", item);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

