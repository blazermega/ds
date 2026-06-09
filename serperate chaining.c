//3. Separate Chaining in C

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node
{
    int data;
    struct node *next;
};

struct node *hash[SIZE];

int main()
{
    int n, key, i, index;

    for(i = 0; i < SIZE; i++)
        hash[i] = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        index = key % SIZE;

        struct node *newNode =
            (struct node *)malloc(sizeof(struct node));

        newNode->data = key;
        newNode->next = hash[index];
        hash[index] = newNode;
    }

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
    {
        struct node *temp = hash[i];

        printf("%d --> ", i);

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }

    return 0;
}

