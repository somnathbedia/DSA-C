#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* HEAD;

void insertHead(int data);
void print(struct Node* head);
struct Node* getNewNode(int data);

int main()
{
    HEAD=NULL;

    insertHead(16);
    insertHead(89);
    insertHead(22);
    insertHead(30);

    print(HEAD);
    return 0;
}

void insertHead(int data)
{
    struct Node* newNode = getNewNode(data);

    if(HEAD==NULL)
    {
        HEAD=newNode;
        return;
    }

    newNode->next=HEAD;
    HEAD->prev=newNode;
    HEAD=newNode;
}

void print(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
}

struct Node* getNewNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    (*node).data=data;
    (*node).next=NULL;
    (*node).prev=NULL;

    return node;
}
