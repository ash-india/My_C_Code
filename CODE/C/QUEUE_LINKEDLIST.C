#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int size;

struct queue{
    int data;
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

int is_full()
{
    Q *temp=(Q *)malloc(sizeof(Q));
    if(temp){
        free(temp);
        return 0;
    }
    return 1;
}

void enque(int val)
{
    Q *temp= (Q*)malloc(sizeof(Q));
    if(temp)
    {
        temp->data=val;
        if(!front){
            front=temp;
            rear=temp;
        }
        else{
            rear->next = temp;
            rear= temp;
        }
        temp->next = NULL;
        size+=1;
    }
    else
        printf("Queue Overload");
}

int deque()
{
    int val = INT_MIN;
    if(is_empty())
        printf("\nQueue is Empty");
    else{
        Q *temp= front;
        val = temp->data;
        front = front->next;
        if(temp==rear) 
            rear = NULL;
        free(temp);
        size-=1;
    }
    return val;
}

void display()
{
    Q *temp=front;
    if(temp)
    {   printf("\n Queue is :-  ");
        while(temp)
        {
            printf(" %d ",temp->data);
            temp = temp->next;
        }
    }
    else
        printf("Queue is Empty");
}

int main()
{
    int ch,val;
    printf("\n       QUEUE");
    do{
        printf("\n");
        printf("\n 1.Create List");
        printf("\n 2. Enque ");
        printf("\n 3. Deque");
        printf("\n 4. Display");
        printf("\n 5. Check for Empty");
        printf("\n 6. Queue is Full ?");
        printf("\n 7. Size");
        printf("\n 8. Exit");
        printf("\nEnter Your Choice  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: case 2: printf("\nEnter Data ");
                            scanf("%d",&val);
                            enque(val); break;
            case 3: printf("\n %d",deque()); break;
            case 4: display(); break;
            case 5: if(is_empty())
                        printf("\nQueue is Empty");
                    else
                        printf("\nQueue is not empty");
                    break;
            case 6: if(is_full())
                        printf("\nQueue is Full");
                    else    
                        printf("\nQueue is not Full");
                    break;
            case 7: printf("\nSize of Queue is %d",size);
                    break;
            case 8: printf("\nEXIT"); break;
            default: printf("Wrong Choice Entered");
        }
    }while(ch!=8);
}