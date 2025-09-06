#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top=-1;

// fuctions declaration
void push(int x);
void pop();
bool isEmpty();
void peek();
void print();

int main()
{

    push(45);
    push(65);
    push(44);
    push(34);

    print();

    pop();

    print();

    printf("%d\n",isEmpty());
    
    return 0;
}

void push(int x)
{
    if(top==MAX_SIZE-1)
    {
        printf("Stack overflow..\n");
        return;
    }
    A[++top]=x;
}

void pop()
{
    if(top>=-1)
    {
        printf("%d is popped from the stack!\n",A[top--]);
    }else
    {
        printf("stack is empty!");
    }
}

bool isEmpty()
{
    if(top<=MAX_SIZE || top < 0)
    {
        return true;
    }else
    {
        return false;
    }
}

void peek()
{
    if(top>-1 || top < MAX_SIZE)
        printf("%d\n",A[top]);
    return;
}

void print()
{
    if(top>=0)
        for(int i = 0; i<=top; i++)
            printf("%d ",A[i]);
    printf("\n");
}