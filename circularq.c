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

    int choice, val;

    do {
        printf("\n=== Circular Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}