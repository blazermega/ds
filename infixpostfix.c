#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char data[50];
    int top;
};
typedef struct node arr;
void push(char ele,arr* a);
char pop(arr* a);
char peek(arr* a);
void infix_to_postfix(char str[]);
int check_infix(char str[]);
int main() {
    char str[50];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    if (check_infix(str)) {
        printf("Infix expression is invalid");
        exit(1);
    }
   infix_to_postfix(str);
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

void infix_to_postfix(char str[]) {
    char res[strlen(str)+1];
    int i = 0;
    arr a;
    a.top = -1;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            push(str[i],&a);
        }
        else if (str[i] == ')') {
            char ele = pop(&a);
            while (ele != '(') {
                res[i] = ele;
                ele = pop(&a);
            }
        }
        else if (str[i] == '+' || str[i] == '-') {
            if (peek(&a) == '*' || peek(&a) == '/') {
                res[i] = pop(&a);
                push(str[i],&a);
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
    printf("%s",res);
}


void push( char ele, arr* a) {
    a->data[++a->top] = ele;
}

char pop(arr* a) {
    return a->data[a->top--];
}
char peek(arr* a) {
    return a->data[a->top];
}