#include<stdio.h>
#include<stdlib.h>

SinglyLinkedListNode {
     int val;
     SinglyLinkedListNode *next;
 };

void createlist(SinglyLinkedListNode **head)
{
    SinglyLinkedListNode *temp, *ptr;
    int n;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    temp = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    scanf("%d",&temp->val);
    *head = temp;
    ptr = temp;
    for(int i=1; i<n; i++)
    {
        temp = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
        scanf("%d",&temp->val);
        ptr->next = temp;
        ptr = temp;
    }
    ptr->next = NULL;
}


//takes two no.s as linked list display their sum
SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l1, SinglyLinkedListNode* l2){
    SinglyLinkedListNode* arr1[100];
    SinglyLinkedListNode* arr2[100];
    int i=0,j=0,res[101],temp=0,rem=0,sum,n;
    SinglyLinkedListNode *ptr1=l1;
    SinglyLinkedListNode *ptr2=l2;
    SinglyLinkedListNode *l3=NULL;
    while(ptr1)
    {
        arr1[i]=ptr1;
        ptr1=ptr1->next;
        i++;
    }
    while(ptr2)
    {
        arr2[j]=ptr2;
        ptr2=ptr2->next;
        j++;
    }
    if(i<j)
        temp=j;
    else
        temp=i;
    n=temp;
    while(i && j)
    {
        sum=arr1[i-1]->val + arr2[j-1]->val+rem;
        res[temp]=sum%10;
        rem=sum/10;
        i--;
        j--;
        temp--;
    }
    while(i)
    {
        sum=arr1[i-1]->val +rem;
        res[temp]=sum%10;
        rem=sum/10;
        i--;
        temp--;
    }
    while(j)
    {
        sum=arr2[j-1]->val +rem;
        res[temp]=sum%10;
        rem=sum/10;
        j--;
        temp--;
    }
    res[temp]=rem;
    i=0;
    while(res[i]==0)
        i++;
    l3=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    l3->val=0;
    if(i<=n)
        l3->val=res[i];
    l3->next=NULL;
    ptr1=l3;
    i++;
    for(;i<=n;i++)
    {
        ptr2=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
        ptr2->val=res[i];
        ptr2->next=NULL;
        ptr1->next=ptr2;
        ptr1=ptr2;
    }
    return l3;
}

void display(SinglyLinkedListNode **head)
{
    if(!*head)
        printf("List is empty");
    else
    {
        SinglyLinkedListNode *ptr=*head;
        while(ptr->next)
        {
            printf("%d -> ",ptr->val);
            ptr = ptr->next;
        }
        printf("%d",ptr->val);
    }
    printf("\n");
}

int main(){
    SinglyLinkedListNode *head1;
    SinglyLinkedListNode *head2;
    createlist(&head1);
    display(&head1);
    createlist(&head2);
    SinglyLinkedListNode *head3;
    head3 = addTwoNumbers(head1,head2);
    display(&head1);
    display(&head2);
    display(&head3);

}