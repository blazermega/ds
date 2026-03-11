#include<stdio.h>
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
        scanf("%d",&op);
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
void ins_l() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    if (head == NULL) {
        head = nn;
        return;
    }
    node* t =head;
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = nn;
}
void ins_n() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
   if (pos<0) {
       printf("Invalid index\n");
       return;
   }
    node* t =head;
    for (int  i = 0; i < pos-1; i++) {
        if (t == NULL) {
            printf("Invalid index\n");
            return;
        }
        t = t->next;
    }
    nn -> next = t->next->next;
    t->next = nn;
}
void del_f() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node* t = head;
    head = head ->next;
    free(head);
}
void del_l() {
    if (head == NULL) {
        printf("The list is empty\n");
    }
    node* t = head;
    while (t->next->next != NULL) {
        t = t->next;
    }
    free(t->next);
    t->next = NULL;
}
void del_n() {
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (pos<0) {
        printf("Invalid index\n");
    }
    node* t = head;
    for (int  i = 0; i < pos-1; i++) {
        if (t == NULL) {
            printf("Invalid index\n");
            return;
        }
        t = t->next;
    }
    node* temp = t->next;
    t->next = t->next->next;
    free(temp);
}
void display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node* t = head;
    while (t!=NULL) {
        printf("%d",t->data);
    }
    if (t->next != NULL) {
        printf("->");
    }
}
void terminate() {
    node* t = head;
    while (t!=NULL) {
        node* temp = t;
        t = t->next;
        free(temp);
    }

}