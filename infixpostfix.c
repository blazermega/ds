#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void push(char ele);
char pop();
char peek();
char* infix_to_postfix(char str[]);
int check_infix(char str[]);
int main() {
    char str[50];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    if (check_infix(str)) {
        printf("Infix expression is invalid");
        exit(1);
    }
    char* res = infix_to_postfix(str);
    printf("%s", res);
    free(res);
}
int check_infix(char str[]) {
    int i = 0;
    int count_a= 0;
    int count_b=0;
    while (str[i] != '\0') {
        if (str[i] == '+' || str[i] == '-'|| str[i] == '*' || str[i] == '/') {
            if (str[i+1] == '+' || str[i+1] == '-'|| str[i+1] == '*' || str[i+1] == '/') {
                return 1;
            }
        }
        if (str[i] == '(') {
            count_a++;
        }
        else if (str[i] == ')') {
            count_b++;
        }
        i++;
    }
    if (count_a ==  count_b)
        return 0;
    else
        return 1;
}

char* infix_to_postfix(char str[]) {
    char res[strlen(str)+1];
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            push(str[i]);
        }
        else if (str[i] == ')') {
            char ele = pop();
            while (ele != '(') {
                res[i] = ele;
                ele = pop();
            }
        }
        else if (str[i] == '+' || str[i] == '-') {
            if (peek() == '*' || peek() == '/') {
                res[i] = pop();
                push(str[i]);
            }
            else {
                res[i] = str[i];
            }
        }
        else {
            res[i] = str[i];
        }
        i++;
    }
    res[i] = '\0';
    return res;
}

void push(char ele) {
    node* nn = malloc(sizeof(node));
    nn->data = ele;
    nn->next = NULL;
    if (head == NULL) {
        head = nn;
    }
    else {
        head->next = head;
        head = nn;
    }
}
char pop() {
    char ele = head->data;
    node* temp = head;
    head = head->next;
    free(temp);
    return ele;
}
char peek() {
    return head->data;
}
