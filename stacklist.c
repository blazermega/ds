#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node*  next;
};
typedef struct node node;
struct node* head = NULL;

void push();
void pop();
void peek();
void display();
int isEmpty();
void terminate();
int main() {
     push();
    while (1) {
        int op;
        printf("1.push");
        printf("2.pop");
        printf("3.peek");
        printf("4.display");
        printf("5.exit");
        scanf("%d",&op);
        switch (op) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                terminate();
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}

void push() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    if (isEmpty()) {
        head = nn;
    }
    else {
        nn->next = head;
        head = nn;
    }
}

void pop() {
    if (isEmpty()) {
        printf("The stack is empty");
        return;
    }
    else {
        int data = head->data;
        node* t = head;
        head = head ->next;
        free(t);
        printf("Popped data is %d\n", data);
    }
}

void peek() {
    if (isEmpty()) {
        printf("The stack is empty");
    }
    else {
        printf("the top element is %d", head->data);
    }
}
void display() {
    if (isEmpty()) {
        printf("The list is empty\n");
        return;
    }
    node* t = head;
    while (t!=NULL) {
        printf("%d",t->data);

        if (t->next != NULL) {
            printf("->");
        }
        t = t->next;
    }
    printf("\n");
}

int isEmpty() {
    if (head == NULL)
        return 1;
    else
        return 0;
}