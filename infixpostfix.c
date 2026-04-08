#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data[50];
    int top;
};
typedef struct node arr;

void push(char ele, arr* a);
char pop(arr* a);
char peek(arr* a);
int is_empty(arr* a);
int precedence(char op);
void infix_to_postfix(char str[]);
int check_infix(char str[]);

int main() {
    char str[50];
    printf("Enter an infix expression: ");
    scanf("%s", str);
    if (check_infix(str)) {
        printf("Infix expression is invalid\n");
        exit(1);
    }
    infix_to_postfix(str);
    printf("\n");
    return 0;
}

int check_infix(char str[]) {
    int i = 0;
    int count_a = 0;
    int count_b = 0;
    while (str[i] != '\0') {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/') {
                return 1;
            }
        }
        if (str[i] == '(')
            count_a++;
        else if (str[i] == ')')
            count_b++;
        i++;
    }
    return (count_a != count_b);
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int is_empty(arr* a) {
    return a->top == -1;
}

void infix_to_postfix(char str[]) {
    int len = strlen(str);
    char res[len * 2 + 1];  /* extra space to be safe */
    int i = 0, j = 0;       /* FIX 1: separate index j for res[] */
    arr a;
    a.top = -1;

    while (str[i] != '\0') {
        if (str[i] == '(') {
            push(str[i], &a);
        }
        else if (str[i] == ')') {
            /* FIX 2: pop until '(' — no extra pop needed after loop */
            while (!is_empty(&a) && peek(&a) != '(') {
                res[j++] = pop(&a);
            }
            if (!is_empty(&a))
                pop(&a);  /* discard the '(' */
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            /* FIX 3 & 4: push operators; pop higher/equal precedence ones first */
            while (!is_empty(&a) && peek(&a) != '(' &&
                   precedence(peek(&a)) >= precedence(str[i])) {
                res[j++] = pop(&a);
            }
            push(str[i], &a);
        }
        else {
            /* operand — write directly to result */
            res[j++] = str[i];
        }
        i++;
    }

    /* FIX 3 (cont): flush remaining operators from stack */
    while (!is_empty(&a)) {
        res[j++] = pop(&a);
    }

    res[j] = '\0';
    printf("Postfix expression: %s", res);
}

void push(char ele, arr* a) {
    a->data[++a->top] = ele;
}

char pop(arr* a) {
    return a->data[a->top--];
}

char peek(arr* a) {
    return a->data[a->top];
}