#include<stdio.h>
#include<stdlib.h>

struct bt {
    int data;
    struct bt *r,*l;
};

typedef struct bt bt;

bt* create(bt *root, int ele) {
    bt* nn = (bt*)malloc(sizeof(bt));
    nn->data = ele;
    nn->r = NULL;
    nn->l = NULL;
    return nn;
}

bt* insert(bt *root, int ele);

void display(bt *root);

int main() {
    bt *root = NULL;
    root = insert(root,1);
    root->l = insert(root->l,2);
    root->r = insert(root->r,3);
    root->l->r = insert(root->l->r,4);
    root->l->l = insert(root->l->l,5);

    display(root);


}
bt* insert(bt *root, int ele) {
    bt* nn = (bt*)malloc(sizeof(bt));
    nn->data = ele;
    nn->r = NULL;
    nn->l = NULL;
    return nn;
}

void display(bt *root) {
    if(root != NULL) {
        display(root->l);
        printf("%d ",root->data);
        display(root->r);
    }
}