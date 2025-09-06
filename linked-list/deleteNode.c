#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* tail;
int size;
void insert(int data);
void print();
void delete(int pos);

int main()
{
    head=NULL;
    tail=NULL;
    size=0;
    insert(56);
    insert(70);
    insert(716);
    insert(42);
    insert(50);

    print();

    delete(3);

    print();

    delete(1);

    print();

    delete(5);

    print();

    printf("Size is : %d\n",size);
    return 0;
}

void insert(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        size+=1;
        return;
    }else if(tail == head)
    { 
        head->next= temp;
        tail=temp;
        size+=1;
    }else{

        tail->next=temp;
        tail=temp;
        size+=1;
    }
   
}

void print()
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
    
}

void delete(int pos)
{
    struct Node* temp = head;
    if(pos>size)
    {
        printf("Invalid size!!!!\n");
        printf("Please enter size <= %d\n",size);
        return;
    }
    if(pos == 1)
    {
        struct Node* temp = head;
        head=temp->next;
        free(temp);
        size-=1;
    }
    if(pos == size)
    {
        struct Node* temp = head;
    
        for(int i=0; i < size-2; i++)
        {
            temp=temp->next;
        }
        tail=temp;
        temp->next=NULL;
        size-=1;
        free(temp->next);
    }

    for(int i = 2; i < pos; i++)
    {
        temp=temp->next;
    }
    struct Node* nextPtr = temp->next->next;
    temp->next=nextPtr;
    size-=1;
    
}