#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int f, r;
} Queue;

void init(Queue *q) {
    q->f = q->r = -1;
}

void enqueue(Queue *q, int val) {
    if ((q->r + 1) % MAX == q->f) {
        printf("Queue is full\n");
        return;
    }
    if (q->f == -1) q->f = 0;
    q->r = (q->r + 1) % MAX;
    q->data[q->r] = val;
}

int dequeue(Queue *q) {
    if (q->f == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = q->data[q->f];
    if (q->f == q->r) q->f = q->r = -1;
    else q->f = (q->f + 1) % MAX;
    return val;
}

void display(Queue *q) {
    if (q->f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->f; ; i = (i + 1) % MAX) {
        printf("%d ", q->data[i]);
        if (i == q->r) break;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    enqueue(&q, 60); // Full

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    return 0;
}