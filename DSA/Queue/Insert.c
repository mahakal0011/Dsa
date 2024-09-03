#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
        printf("\n>>>>.....MAIN MENU.....<<<<\n");
        printf("1. )))))Enqueue((((((\n");
        printf("2. /////Dequeue//////\n");
        printf("3. +++++Display++++++\n");
        printf("4. *****Exit******\n");
    while (1) {
        printf("\n>>>>.....()()()()Let's go()()()().....<<<<\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

void enqueue() {
    int item;
    if (rear == MAX - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    } else {
        printf("Enter the value to enqueue: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
