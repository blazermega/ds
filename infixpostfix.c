#include <stdio.h>
#define max 50

struct node {
    char data[max];
    int top;
}; 
typedef struct node node;

void push(node* stk, char ele);
char pop(node* stk);
char peek(node* stk);
void infixToPostfix();

int main() {
    infixToPostfix();
    return 0;
}

void infixToPostfix() {
    node stk;
    stk.top = -1;
    char infix[max];
    char postfix[max];
    int j = 0; // Fix 3: separate postfix index

    printf("Enter the infix expression\n");
    scanf("%s", infix);

    int i = 0;
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(&stk, infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-') {
            // Fix 2: pop while top has >= precedence
            while (stk.top != -1 && peek(&stk) != '(' &&
                  (peek(&stk)=='+' || peek(&stk)=='-' ||
                   peek(&stk)=='*' || peek(&stk)=='/')) {
                postfix[j++] = pop(&stk);
            }
            push(&stk, infix[i]);
        }
        else if (infix[i] == '*' || infix[i] == '/') {
            // Pop only higher-or-equal precedence (* and /)
            while (stk.top != -1 && peek(&stk) != '(' &&
                  (peek(&stk)=='*' || peek(&stk)=='/')) {
                postfix[j++] = pop(&stk);
            }
            push(&stk, infix[i]);
        }
        else if (infix[i] == ')') { // Fix 1: ')' not '('
            while (stk.top != -1 && peek(&stk) != '(') {
                postfix[j++] = pop(&stk);
            }
            pop(&stk); // discard the '('
        }
        else {
            postfix[j++] = infix[i]; // Fix 3: use j
        }
        i++;
    }

    // Fix 4: flush remaining operators
    while (stk.top != -1)
        postfix[j++] = pop(&stk);

    postfix[j] = '\0';
    printf("The postfix expression is %s\n", postfix);
}

void push(node* stk, char ele) {
    if (stk->top == max - 1) { printf("Stack is full\n"); return; }
    stk->data[++stk->top] = ele;
}

char pop(node* stk) {
    if (stk->top == -1) { printf("Stack underflow\n"); return '\0'; } // Fix 5
    return stk->data[stk->top--];
}

char peek(node* stk) {
    if (stk->top == -1) return '\0'; // Fix 5
    return stk->data[stk->top];
}