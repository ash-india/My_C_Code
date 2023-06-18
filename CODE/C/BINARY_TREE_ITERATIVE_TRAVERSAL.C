#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};
typedef struct node N;
N *root = NULL;

struct queue{
    struct node *point;
    struct queue *next;
};
typedef struct queue Q;
Q *front = NULL, *rear = NULL;

struct stack
{
    int size;
    int top;
    N **c;
};
typedef struct stack st;

int is_empty()
{
    if(front)
        return 0;
    return 1;
}

int isempty(st *ss)
{
    if(ss->top == -1)
        return 1;
    else
        return 0;
}

void push(st *ss, N* x)
{
    ss->c[++ss->top] = x;
}

N* pop(st *ss)
{
    N* x = ss->c[ss->top--];
    return x;
}

N* enque(int n)
{
    if(n!= -1)
    {
        Q *temp= (Q*)malloc(sizeof(Q));
        temp->point = (N *)malloc(sizeof(N));
        temp->point->data=n;
        temp->point->lchild=NULL;
        temp->point->rchild=NULL;
        if(!front){
            front=temp;
            rear=temp;
        }
        else{
            rear->next = temp;
            rear= temp;
        }
        temp->next = NULL;
        return temp->point;
    }
    return NULL;
}

N* deque()
{
    N *ptr;
    if(is_empty())
        return NULL;
    else{
        Q *temp= front;
        ptr = temp->point;
        front = front->next;
        if(temp==rear) 
            rear = NULL;
        free(temp);
        return ptr;
    }
}

void preorder(N *ptr)
{
    st st1;
    st1.size=20;
    st1.top=-1;
    st1.c=(N **)malloc(sizeof(N*)*20);
    while(ptr || !isempty(&st1))
    {
        if(ptr)
        {
            printf(" %d ",ptr->data);
            push(&st1,ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr=pop(&st1);
            ptr=ptr->rchild;
        }
    }
}

void inorder(N *ptr)
{
    st st1;
    st1.size=20;
    st1.top=-1;
    st1.c=(N **)malloc(sizeof(N*)*20);
    while(ptr || !isempty(&st1))
    {
        if(ptr)
        {
            push(&st1,ptr);
            ptr=ptr->lchild;
        }
        else
        {
            ptr=pop(&st1);
            printf(" %d ",ptr->data);
            ptr=ptr->rchild;
        }
    }
}

void postorder(N *ptr)
{
    st st1;
    st1.size=20;
    st1.top=-1;
    st1.c=(N **)malloc(sizeof(N*)*20);
    long int temp;
    while(ptr || !isempty(&st1))
    {
        if(ptr)
        {
            push(&st1,ptr);
            ptr=ptr->lchild;
        }
        else
        {
            temp=(uintptr_t)pop(&st1);
            if(temp>0)
            {
                push(&st1,(N *)(-temp));
                ptr=((N*)temp)->rchild;
            }
            else
            {
                printf(" %d ",((N*)(-temp))->data);
                ptr=NULL;
            }
        }
    }
}

int main()
{   
    int val;
    printf("\n   Binary Tree ");
    printf("\nEnter Root Value of Tree (-1 to abort):- ");
    scanf("%d",&val);
    root = enque(val);
    N *temp=deque();
    if(root)
    {
        do
        {
            printf("\n Enter Left Child of %d(-1 to abort):- ",temp->data);
            scanf("%d",&val);
            temp->lchild=enque(val);
            printf("\n Enter Right Child of %d(-1 to abort):- ",temp->data);
            scanf("%d",&val);
            temp->rchild=enque(val);
            temp=deque();
        }while(temp);
    }
    printf("\npreorder:-  ");
    preorder(root);
    printf("\ninorder:- ");
    inorder(root);
    printf("\npostorder:- ");
    postorder(root);
}