#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull(void) {
    return (rear + 1) % SIZE == front;
}

int isEmpty(void) {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue(void) {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to remove.\n");
        return;
    }

    printf("%d removed.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display(void) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    enqueue(50);
    enqueue(60);
    display();

    return 0;
}
