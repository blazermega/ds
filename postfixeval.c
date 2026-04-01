#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
struct arr {
    int data[MAX];
    int top;

};
typedef struct arr arr;
void eval(char str[]);
void push(arr* a,int ele);
int pop(arr* a);
//int peek(arr* a);
int main() {
    printf("Enter the postfix expression");
    char str[MAX];
    scanf("%s",str);
    eval(str);

}
void eval(char str[]) {
    char result[MAX];
    int i = 0;
    arr a;
    a.top = -1;
    while (str[i] != '\0') {
        if (str[i] == '+') {
            push(&a,pop(&a) + pop(&a));
        }
        else if (str[i] == '-') {
            push(&a,-1*(pop(&a) - pop(&a)));
        }
        else if (str[i] == '*') {
            push(&a,pop(&a) * pop(&a));
        }
        else if (str[i] == '/') {
            int b = pop(&a);
            int c = pop(&a);
            push(&a,c/b);
        }
        else {
            push(&a,str[i]-'0');
        }
        i++;
    }
    printf("the ans is %d", pop(&a));
}

void push(arr* a, int ele) {
    a->data[++a->top] = ele;
}

int pop(arr* a) {
    return a->data[a->top--];
}
/*int peek(arr* a) {
    return a->data[a->top];
}*/