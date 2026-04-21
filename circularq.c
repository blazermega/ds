#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node {
    int data[MAX];
    int f;
    int l;
};
typedef struct node node;

void push(node *q);
void pop(node *q);
void display(node *q);

int main() {
    node stk;
    stk.f = -1;
    stk.l = -1;
    while (1) {
        int op;
        printf("enter\n");
        printf("1.push");
        printf("2.pop");
        printf("3.display");
        printf("4.exit");
        scanf("%d",&op);
        switch (op) {
            case 1:
                push(&stk);
                break;
            case 2:
                pop(&stk);
                break;
            case 3:
                display(&stk);
                break;
            case 4:
                exit(0);
            default:
                printf("enter valid option");
        }
    }

}

void push(node *q) {
    printf("enter the ele");
    int ele;
    scanf("%d",&ele);
    if (q->f == -1) {
        q->l++;
        q->f++;
    }
    else {
        q->l++;
    }

}