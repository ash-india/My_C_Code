#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int ltag;
    int data;
    int rtag;
    struct node *rchild;
};
typedef struct node N;
N *dummy = NULL;

void insert(N *root,int data)
{
    N *ptr=NULL;
    while(root)
    {
        if(data == root->data)
            return;
        else if(data<root->data)
        {
            if(root->ltag==1)
                root=root->lchild;
            else 
                break;
        }
        else
        {
            if(root->rtag==1)
                root=root->rchild;
            else
                break;
        }
    }
    ptr=(N *)malloc(sizeof(N));
    ptr->ltag=ptr->rtag=0;
    ptr->data=data;
    if(data<root->data)
    {
        ptr->lchild=root->lchild;
        root->ltag=1;
        root->lchild=ptr;
        ptr->rchild=root;
    }
    else
    {
        ptr->rchild=root->rchild;
        root->rtag=1;
        root->rchild=ptr;
        ptr->lchild=root;
    }
}

N *inorder_successor(N *root)
{
    if(root->rtag==0)
        return root->rchild;
    else
    {
        root = root->rchild;
        while(root->ltag==1)
            root=root->lchild;
        return root;
    }
}

void inorder_print(N *root)
{
    N *ptr=inorder_successor(root);
    while(ptr!=root)
    {
        printf(" %d ",ptr->data);
        ptr = inorder_successor(ptr);
    }
}

N *preorder_successor(N *root)
{
    if(root->ltag==1)
        return root->lchild;
    else
    {
        while(root->rtag==0)
            root=root->rchild;
        return root->rchild;
    }
}

void preorder_print(N *root)
{
    N *ptr=preorder_successor(root);
    while(ptr!=root)
    {
        printf(" %d ",ptr->data);
        ptr = preorder_successor(ptr);
    }
}

int main()
{
    int data;
    dummy=(N*)malloc(sizeof(N));
    dummy->ltag=dummy->rtag=1;
    dummy->lchild=NULL;
    dummy->rchild=dummy;

    printf("\nEnter root value: ");
    scanf("%d",&data);
    N *root=(N *)malloc(sizeof(N));
    root->data=data;
    dummy->lchild=root;
    root->ltag=root->rtag=0;
    root->lchild=root->rchild=dummy;

    while(1)
    {
        printf("New Node: (-1 to abort)");
        scanf("%d",&data);
        if(data != -1)
            insert(root,data);
        else
            break;
    }
    printf("\nInorder:- ");
    inorder_print(dummy);

    printf("\nPreorder:- ");
    preorder_print(dummy);
    return 0;
}
