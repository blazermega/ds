#include<stdio.h
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void ins_f();
void ins_l();
void ins_n();
void del_f();
void del_l();
void del_n();
void display();
void terminate();
int main() {
    ins_f();
    while (1) {
        int op;
        printf("Enter\n");
        printf("1.Insert node at beginning\n");
        printf("2.Insert node at end\n");
        printf("3.insert node at a position\n");
        printf("4.Delete node at beginning\n");
        printf("5.Delete node at end\n");
        printf("6.Delete node at a position\n");
        printf("7.Display all the nodes\n");
        printf("8.Exit\n");
        switch (op) {
            case 1:
                ins_f();
                break;
            case 2:
                ins_l();
                break;
            case 3:
                ins_n();
                break;
            case 4:
                del_f();
                break;
            case 5:
                del_l();
                break;
            case 6:
                del_n();
                break;
            case 7:
                display();
                break;
            case 8:
                terminate();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void ins_f() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    if (head == NULL) {
        head = nn;
    }
    else {
        nn->next = head;
        head = nn;
    }
}

