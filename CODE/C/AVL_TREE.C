#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
};
typedef struct Node N;
N *Root_tree = NULL;

int height(N *root)
{
    if(!root)
        return -1;
    else
    {
        int x=height(root->lchild);
        int y=height(root->rchild);
        return ((x>y) ? x : y) + 1;
    }
}

N *LL_Rotation(N *root)
{
    N *newroot = root->lchild;
    root->lchild = newroot->rchild;
    newroot->rchild = root;
    root->height = height(root);
    newroot->height = height(newroot);
    return newroot;
}

N *RR_Rotation(N *root)
{
    N *newroot = root->rchild;
    root->rchild = newroot->lchild;
    newroot->lchild = root;
    root->height = height(root);
    newroot->height = height(newroot);
    return newroot;
}

N *LR_Rotation(N *root)
{
    root->lchild = RR_Rotation(root->lchild);
    return LL_Rotation(root);
}

N *RL_Rotation(N *root)
{
    root->rchild = LL_Rotation(root->rchild);
    return RR_Rotation(root);
}

N *find_min(N *ptr)   //Inorder Successor
{
    while(ptr && ptr->lchild)
        ptr = ptr->lchild;
    return ptr;
}

N *insert(N *root, int data)
{
    if(!root)
    {
        root = (N *)malloc(sizeof(N));
        root->lchild = root->rchild = NULL;
        root->height = 0;
        root->data = data;
    }
    else if(data < root->data)
    {
        root->lchild = insert(root->lchild, data);
        if(height(root->lchild) - height(root->rchild) == 2)
        {
            if(data < root->lchild->data)
                root = LL_Rotation(root);
            else
                root = LR_Rotation(root);
        }
    }
    else if(data > root->data)
    {
        root->rchild = insert(root->rchild, data);
        if(height(root->rchild) - height(root->lchild) == 2)
        {
            if(data > root->rchild->data)
                root = RR_Rotation(root);
            else    
                root = RL_Rotation(root);
        }
    }

    root->height = height(root);
    return root;
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

N *delet(N *ptr, int key)
{
     N *temp = NULL;
    if(!ptr)
        printf("\n Element is not present");
    else if(key < ptr->data)
    {
        ptr->lchild = delet(ptr->lchild,key);
        if(height(ptr->rchild) - height(ptr->lchild) == 2)
        {
            if(height(ptr->rchild->lchild) > height(ptr->rchild->rchild))
                ptr = RL_Rotation(ptr);
            else
                ptr =  RR_Rotation(ptr);
        }
    }
    else if(key > ptr->data)
    {
        ptr->rchild = delet(ptr->rchild,key);
        if(height(ptr->lchild) - height(ptr->rchild) == 2)
        {
            if(height(ptr->lchild->rchild) > height(ptr->lchild->lchild))
                ptr = LR_Rotation(ptr);
            else
                ptr = LL_Rotation(ptr);
        }
    }
    else
    {
        if(ptr->lchild && ptr->rchild)
        {
            temp = find_min(ptr->rchild);
            ptr->data = temp->data;
            ptr->rchild = delet(ptr->rchild, temp->data);
            if(height(ptr->lchild) - height(ptr->rchild) == 2)
            {
                if(height(ptr->lchild->rchild) > height(ptr->lchild->lchild))
                    ptr = LR_Rotation(ptr);
                else
                    ptr = LL_Rotation(ptr);
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
    if(ptr) 
        ptr->height = height(ptr);
    return ptr;
}


int main()
{
    int data;
    printf("\n Enter root of tree(-1 to abort): ");
    scanf("%d",&data);

    while(data != -1)
    {
        Root_tree=insert(Root_tree, data);
        printf("\n Enter root of tree(-1 to abort): ");
        scanf("%d",&data);
    }
    printf("\npreorder:-  ");
    preorder(Root_tree);
    printf("\ninorder:- ");
    inorder(Root_tree);
    printf("\npostorder:- ");
    postorder(Root_tree);

    printf("\n Enter node to be deleted (-1 to abort): ");
    scanf("%d",&data);
    while(data != -1)
    {
        Root_tree = delet(Root_tree,data);
        printf("\npreorder:-  ");
        preorder(Root_tree);
        printf("\ninorder:- ");
        inorder(Root_tree);
        printf("\npostorder:- ");
        postorder(Root_tree);
        printf("\n Enter node to be deleted (-1 to abort): ");
        scanf("%d",&data);
    }
    return 0;
}
