#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *ptrdiff;
};
typedef struct node NDM;
NDM *head = NULL, *tail = NULL;

NDM *XOR(NDM *x, NDM *y)
{
    return (NDM *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void createlist()
{
    NDM *temp = NULL, *prev = NULL, *next = NULL, *curr;
    curr = (NDM *)malloc(sizeof(NDM));
    printf("\nEnter Data");
    scanf("%d",&curr->data);
    if(!head)
    {
        head = tail = curr;
        curr->ptrdiff=NULL;
    }
    else
    {
        temp = head;
        next = XOR(prev, temp->ptrdiff);
        while(next)
        {
            prev = temp;
            temp = next;
            next = XOR(prev, temp->ptrdiff);
        }
        temp->ptrdiff = XOR(prev, curr);
        curr->ptrdiff = XOR(temp, NULL);
        tail = curr;
    }
}

void print()
{
    NDM *prev = NULL, *temp = head, *ptr;
    while(temp)
    {
        printf("%d ",temp->data);
        ptr = temp;
        temp = XOR(prev, temp->ptrdiff);
        prev = ptr;
    }
}

void revprint()
{
    NDM *next = NULL, *temp = tail, *ptr;
    while(temp)
    {
        printf("%d ",temp->data);
        ptr = temp;
        temp = XOR(next, temp->ptrdiff);
        next = ptr;
    }
}

int main()
{
    printf("DOUBLY LINKED LIST WITH MEMORY OPTIMIZATION");
    int ch;
    do{
        printf("\n 1. Create List");
        printf("\n 2. Print List");
        printf("\n 3. Print List In Reverse Order");
        printf("\n 4. Exit");
        printf("\n Enter Your Choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: createlist(); break;
            case 2: print(); break;
            case 3: revprint(); break;
            case 4: printf("Thank You"); break;
            default: printf("Wrong Choice Entered");
        }
    }while(ch!=4);
}