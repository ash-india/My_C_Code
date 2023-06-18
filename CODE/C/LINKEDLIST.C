#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node N;
N *head1=NULL, *head2=NULL;

void createlist(N **head)
{
    N *temp, *ptr;
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    temp = (N *)malloc(sizeof(N));
    scanf("%d",&temp->data);
    *head = temp;
    ptr = temp;
    for(int i=1; i<n; i++)
    {
        temp = (N *)malloc(sizeof(N));
        scanf("%d",&temp->data);
        ptr->next = temp;
        ptr = temp;
    }
    ptr->next = NULL;
}

int count_list(N *head)
{
    int count = 0;
    if(!head)
        printf("\nLIst is Empty");
    N *ptr=head;
    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void display(N **head)
{
    if(!*head)
        printf("List is empty");
    else
    {
        N *ptr=*head;
        while(ptr->next)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
    }
}

void insert_at_beg(N *head)
{
    N *temp;
    temp = (N *)malloc(sizeof(N));
    printf("Enter the element: ");
    scanf("%d",&temp->data);
    temp->next = head;
    head = temp;
}

void insert_at_end(N *head)
{
    N *temp,*ptr = head;
    while(ptr->next)
        ptr = ptr->next;
    temp = (N *)malloc(sizeof(N));
    temp->next = NULL;
    ptr->next = temp;
}

void insert_at_pos(N *head,int pos)
{
    int k = 1;
    N *ptr = head;
    while(k<pos-1 && ptr->next)
    {
        ptr = ptr->next;
        k++;
    }
    if(k<pos-1)
        printf("Invalid Position");
    else
    {
        N *temp = (N *)malloc(sizeof(N));
        printf("\nEnter value: ");
        scanf("%d",&temp->data);
        temp->next = ptr->next;
        ptr->next = temp;
        if(pos==1)
            head=temp;
    }
}

int main()
{
    int ch;
    do
    {
        printf("\n1. CREATE LIST");
        printf("\n2. PRINT list");
        printf("\n3. INSERT AT BEGINNING");
        printf("\n4. INSERT AT END");
        printf("\n5. INSERT AT POSITION");
        printf("\n6. DELETE FRONT");
        printf("\n7. DELETE END");
        printf("\n8. DELETE AT POSITION");
        printf("\n9. COUNT NODES");
        printf("\n10. SUM OF NODES");
        printf("\n11. REVERSE");
        printf("\n12. EXIT");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: createlist(&head1);
                    break;
            case 2: display(&head1);
                    break;
            default: printf("\nWRONG CHOICE ENTERED");
        }
    } while (ch!=12);
    
}