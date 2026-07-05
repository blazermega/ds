#include<stdio.h>
#include<stdlib.h>

struct bst {
    int data;
    struct bst *left,*right;
};

typedef struct bst bst;

bst* ins(bst* root, int ele);
bst* del(bst*root, int ele);
void search(bst* root, int ele);
bst* finsMin(bst* root);
void inorder(bst* root);
bst* create(int ele);
void terminate(bst* root);

int main() {
    bst* root = NULL;
    while (1) {
        int ele;
        int op;
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to search\n");
        printf("Enter 4 to display");
        printf("Enter 5 to exit\n");    
        scanf("%d",&op);
        switch (op) {
            case 1:
                printf("Enter element:");
                scanf("%d",&ele);
                root=ins(root,ele);
                break;
            case 2:
                printf("Enter element:");
                scanf("%d",&ele);
                root=del(root,ele);
                break;
            case 3:
                printf("Enter element:");
                scanf("%d",&ele);
                search(root,ele);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                terminate(root);
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
}


bst* ins(bst* root, int ele) {
    if (root == NULL) {
        return create(ele);
    }

    if (ele < root->data) {
        root->left = ins(root->left,ele);
    }
    else if (ele > root->data) {
        root->right = ins(root->right,ele);
    }
    return root;
}
bst* create(int ele) {
    bst* nn = malloc(sizeof(bst));
    nn->data = ele;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

bst* del(bst* root, int ele) {
    if (root == NULL) {
        printf("element not found\n");
        return root;
    }
    if (ele < root->data) {
        root->left = del(root->left,ele);
    }
    else if (ele > root->data) {
        root->right = del(root->right,ele);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            bst* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            bst* temp = root->left;
            free(root);
            return temp;
        }
        else {
            bst* t = finsMin(root->right);
            root->data = t->data;
            free(t);
            t = NULL;
        }
    }
    return root;
}

bst* finsMin(bst* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void inorder(bst* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void search(bst* root, int ele) {
    if (root == NULL) {
        printf("element not found\n");
        return;
    }
    if (ele < root->data) {
        search(root->left,ele);
    }
    else if (ele > root->data) {
        search(root->right,ele);
    }
    else {
        printf("element found\n");
    }

}

void terminate(bst* root) {
    if (root != NULL) {
        terminate(root->left);
        terminate(root->right);
        free(root);
    }
}