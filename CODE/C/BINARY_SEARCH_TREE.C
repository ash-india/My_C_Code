#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};
typedef struct node N;
N *root = NULL;

int height(N *ptr)
{
    int x,y;
    if(ptr)
    {
        x=height(ptr->lchild);
        y=height(ptr->rchild);
        return ((x > y)? x+1 : y+1);
    }
    return -1;
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

N *Inpre(N *ptr)
{
    while(ptr && ptr->rchild)
        ptr = ptr->rchild;
    return ptr;
}

N *Insucc(N *ptr)
{
    while(ptr && ptr->lchild)
        ptr = ptr->lchild;
    return ptr;
}


N* delet(N *ptr,int key)
{
    N *temp;
    if(!ptr)
        printf("\n Element is not present");
    else if(key < ptr->data)
        ptr->lchild = delet(ptr->lchild,key);
    else if(key > ptr->data)
        ptr->rchild = delet(ptr->rchild,key);
    else
    {
        if(ptr->lchild && ptr->rchild)
        {
            /*
              in books the minimum value node in right child is replaced 
            but for height efficiency we delete inorder successor and predecessor
            */
            if(height(ptr->lchild) > height(ptr->rchild))
            {
                temp = Inpre(ptr->lchild);
                ptr->data = temp->data;
                ptr->lchild = delet(ptr->lchild, temp->data);
            }
            else
            {
                temp=Insucc(ptr->rchild);
                ptr->data = temp->data;
                ptr->rchild = delet(ptr->rchild,temp->data);
            }
        }
        else
        {
            temp = ptr;
            if(!ptr->lchild && !ptr->rchild)
                ptr = NULL;
            else if(!ptr->lchild)
                ptr = ptr->rchild;
            else if(!ptr->rchild)
                ptr = ptr->lchild;
            free(temp);
        }
    }
    return ptr;
}

N *insert(N *ptr,int key)
{
    N *temp;
    if(!ptr)
    {
        temp = (N*)malloc(sizeof(N));
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    if(key < ptr->data)
        ptr->lchild = insert(ptr->lchild,key);
    else if(key > ptr->data)
        ptr->rchild = insert(ptr->rchild,key);
    return ptr;
}

int main()
{
    int key;
    printf("Enter root node of tree (-1 to abort): ");
    scanf("%d",&key);
    while(key != -1)
    {
        root = insert(root,key);
        printf("Enter new node of tree (-1 to abort): ");
        scanf("%d",&key);
    }
    printf("\npreorder:-  ");
    preorder(root);
    printf("\ninorder:- ");
    inorder(root);
    printf("\npostorder:- ");
    postorder(root);

    printf("\n Enter node to be deleted (-1 to abort): ");
    scanf("%d",&key);
    while(key != -1)
    {
        root = delet(root,key);
        printf("\npreorder:-  ");
        preorder(root);
        printf("\ninorder:- ");
        inorder(root);
        printf("\npostorder:- ");
        postorder(root);
        printf("\n Enter node to be deleted (-1 to abort): ");
        scanf("%d",&key);
    }
    return 0;
}