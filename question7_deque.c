#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isEmpty(void) { return front == -1; }
int isFull(void) { return front == (rear + 1) % SIZE; }

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) front = rear = 0;
    else front = (front - 1 + SIZE) % SIZE;

    deque[front] = value;
    printf("%d inserted at the front.\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % SIZE;

    deque[rear] = value;
    printf("%d inserted at the rear.\n", value);
}

void deleteFront(void) {
    if (isEmpty()) {
        printf("Deque is empty. Nothing to delete.\n");
        return;
    }
    printf("%d deleted from the front.\n", deque[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void deleteRear(void) {
    if (isEmpty()) {
        printf("Deque is empty. Nothing to delete.\n");
        return;
    }
    printf("%d deleted from the rear.\n", deque[rear]);
    if (front == rear) front = rear = -1;
    else rear = (rear - 1 + SIZE) % SIZE;
}

void display(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    deleteRear();
    display();

    return 0;
}
