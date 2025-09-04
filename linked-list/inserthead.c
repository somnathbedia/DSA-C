#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* HEAD;

void insert(int a)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=a;
    temp->next=NULL;

    if(HEAD!=NULL)
    {
        temp->next=HEAD;
        HEAD=temp;
    }else
    {
        HEAD=temp;
    }
}

void insertTail(int a)
{
    if(HEAD ==NULL)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=a;
        temp->next=NULL;
        HEAD=temp; 
        return;
    }
    
    struct Node* current=HEAD;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=a;
    temp->next=NULL;

    

    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=temp;
}


void insertPosition(int data,int pos){
    struct Node* temp = HEAD;

    if(pos==1)
    {
        insert(data);
        return;
    }

    for(int i = 2; i < pos; i++)
    {
        temp=temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=temp->next;
    temp->next=newNode;

}

void print()
{
    struct Node* temp = HEAD;

    printf("Head->");
    while (temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}

void printRec(struct Node* head)
{

    struct Node* temp=head;

    if(temp == NULL)
    {
        return;
    }
        
    printRec(temp->next);
    printf("%d ",temp->data);
    
}

void reverse(struct Node* temp)
{
    if(temp->next == NULL)
    {
        HEAD=temp;
        return;
    }

    reverse(temp->next);

    // pointer to the last node
    struct Node* q = temp->next;
    q->next=temp;
    temp->next=NULL;
     

}

void reverseList()
{
    struct Node* prev=NULL;
    struct Node* current=HEAD;
    struct Node* next = NULL;

    
    struct Node* temp=NULL;
    
    while(current != NULL)
    {
    
        // Take reference for next node
       next=current->next;
        
       // update pointers
        current->next=prev;
        prev=current;
        current=next;
    }
    
    HEAD=prev;
}

void main()
{
    HEAD=NULL;
    int A[5]={67,33,56,90,100};
    int x;
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
    {
        insertTail(A[i]);
    }
    
    // reverseList();

    reverse(HEAD);
    print();
 
    // printRec(HEAD);
}