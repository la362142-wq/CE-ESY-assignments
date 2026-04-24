#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Buffer is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    buffer[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Buffer is empty!\n");
        return;
    }
    printf("Removed %d\n", buffer[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    dequeue();

    enqueue(60);
    enqueue(70);

    return 0;
}
