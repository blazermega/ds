#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* prev;
    int data;
    struct node* next;
};
typedef struct node node;
node* head = NULL;
node* tail = NULL;
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
    nn->prev = NULL;
    if (head == NULL) {
        head = nn;
        tail = head;
    }
    else {
        head->prev = head;
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
    nn->prev = NULL;
    if (head == NULL) {
        head = nn;
        tail = head;
    }
    else {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}
void ins_n() {
    int ele,pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    printf("Enter the element\n");
    scanf("%d",&ele);
    if (pos<0) {
        printf("Position out of bounds\n");
        return;
    }
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    nn->prev = NULL;
    if (pos == 0) {
        ins_f();
        return;
    }
    node* t= head;
    for (int i = pos-1; i >= 0; i--) {
        if (t!=NULL) {
            printf("Invalid index");
            return;
        }
        t=t->next;
    }
    node* tt = t->next;
    nn->prev = tt;
    nn->next = t->next;
    t->next = nn;
    tt->prev = nn;
}
void del_f() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* t =head;
    head = head->next;
    head->prev = NULL;
    free(t);
}
void del_l() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* t = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(t);
}
void del_n() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if (pos<0) {
        printf("Position out of bounds\n");
        return;
    }
    node* t = head;
    if (pos == 0) {
        del_f();
        return;
    }
    for (int i = 0;i<pos;i++) {
        if (t!=NULL) {
            printf("Invalid index");
            return;
        }
        t=t->next;
    }
    if (t->next == NULL) {
        del_l();
        return;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* t = head;
    while (t!=NULL) {
        printf("%d\t",t->data);
        if (t->next != NULL) {
            printf("->");
        }
        t = t->next;
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