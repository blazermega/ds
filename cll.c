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
        printf("\nEnter\n");
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
        head->next = head;
        return;
    }

    nn->next = head;
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = nn;
    head = nn;

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
        head->next = head;
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = nn;
    nn->next = head;
}

void ins_n() {
    int ele;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    if (pos<0) {
        printf("Invalid Position\n");
        return;
    }
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    if (pos == 0) {
        if (head == NULL) {
            head = nn;
            head->next = head;
            return;
        }

        nn->next = head;
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = nn;
        head = nn;
        return;
    }
    node* t = head;
    for (int i=1; i<pos-1; i++) {
        t = t->next;
        if (t ==  head) {
            printf("invalid index");
            return;
        }
    }
    if (t->next == head) {
        t->next = nn;
        nn->next = head;
    }
    else {
        nn->next = t->next;
        t->next = nn;
    }
}

void del_f() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
}
void del_l() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
    }
}
void del_n() {
    int pos;
    printf("Enter the position to delete\n");
    scanf("%d",&pos);
    if (pos<0) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 0) {
        if (head == NULL) {
            printf("The list is empty\n");
            return;
        }
        if (head->next == head) {
            free(head);
            head = NULL;
        }
        else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp ->next;
        }
        return;
    }
    node* temp = head;
    for (int i=1; i<pos-1; i++) {
        temp = temp->next;
        if (temp->next == head) {
            printf("invalid index");
            return;
        }
    }
    if (temp->next->next== head) {
        free(temp->next);
        temp->next = head;
    }
    else {
        node* t = temp->next;
        temp->next = temp -> next->next;
        free(t);
    }

}

void display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    node* temp = head;
    do {
        printf("%d", temp->data);
        if (temp->next != head) {
            printf("->");
        }
        temp = temp->next;
    }while (temp!=head);
}
void terminate() {
    if (head == NULL) {
        return;
    }
    node* t =head;
    do {
        node* t2 = t;
        t = t->next;
        free(t2);
    }while (t!=head);
}
