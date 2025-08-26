#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node* A)
{
    struct Node* temp=A;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* A = NULL;

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=67;
    temp->next=NULL;
    A=temp;

    struct Node* node2=(struct Node*)malloc(sizeof(struct Node));
    node2->data=90;
    node2->next=NULL;

    temp->next=node2;


    print(A);
    return 0;
}