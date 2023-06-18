#include<stdio.h>
#include<stdlib.h>

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

int is_empty()
{
    if(front)
        return 0;
    return 1;
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
    if(ptr)
    {
        printf(" %d ",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void inorder(N *ptr)
{
    if(ptr)
    {
        inorder(ptr->lchild);
        printf(" %d ",ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(N *ptr)
{
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf(" %d ",ptr->data);
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