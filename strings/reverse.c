#include<stdio.h>
#include<string.h>

void reverse(int* str,int n)
{
    int low=0;
    int end=n-1;
    while(low<end)
    {
        int temp = str[low];
        str[low] = str[end];
        str[end]=temp;
        low++;
        end--;
    }
}

void reverseString(char* str,int n)
{
    int low=0;
    int end=n-1;
    while(low<end)
    {
        char temp = str[low];
        str[low] = str[end];
        str[end]=temp;
        low++;
        end--;
    }
    
}

int main()
{
    char str[] = "somnath";

    
    reverseString(str,strlen(str));

    return 0;
}