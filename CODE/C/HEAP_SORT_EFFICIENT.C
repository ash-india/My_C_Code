/*
COMPLEXITY OF CREATIONOF HEAP TREE IN THIS WAY IS O(n) 
WHILE COMPLEXITY OF DELETION IS O(nlogn)
SO COMPLEXITY OF HEAP SORT IS O(nlogn)
*/

// THIS IS MAX_HEAP

#include<stdio.h>
#include<stdlib.h>

struct Heap{
    int *array;
    int count;
    int capacity;
};

int parent(struct Heap *H,int child)
{
    if((child-1)/2 >= 0)
        return (child-1)/2;
    else 
        return -1;
}

int lchild(struct Heap *H,int index)
{
    if(2*index + 1<H->count)
        return 2*index+1;
    else
        return -1;
}

int rchild(struct Heap *H,int index)
{
    if(2*index +2<H->count)
        return 2*index+2;
    else
        return -1;
}

void resize(struct Heap *H)
{
    H->array=(int *)realloc(H->array,sizeof(int)*H->capacity*2);
    H->capacity=H->capacity*2;
}

void percolate_down(struct Heap *H,int index)
{
    int lc,rc,max,temp;
    lc = lchild(H,index);
    rc = rchild(H,index);
    if(lc != -1 && H->array[lc] > H->array[index])
        max = lc;
    else    
        max = index;
    if(rc != -1 && H->array[rc] > H->array[max])
        max = rc;
    if(max != index)
    {
        temp = H->array[index];
        H->array[index] = H->array[max];
        H->array[max] = temp;
        percolate_down(H,max);
    }
}

struct Heap *create_Heap(int capacity)
{
    struct Heap *H=(struct Heap *)malloc(sizeof(struct Heap));
    if(H)
    {
        H->capacity = capacity;
        H->count=0;
        H->array = (int *)malloc(sizeof(int)*H->capacity);
        if(!H->array)
        {
            printf("\nMemory Error");
            free(H);
            return NULL;
        }
        return H;
    }
    printf("\nMemory Error");
    return NULL;
}

void build_heap(struct Heap *H)
{
    int i;
    if(!H)
        return;
    for(i = (H->count-2)/2;i>=0;i--)      // LAST CHILD - H->count -1       PARENT - (h->count-1-1)/2
        percolate_down(H,i);
}

void Heap_sort(struct Heap *H)
{
    int n=H->count;
    int i,temp;
    for(i=n-1;i>0;i--)
    {
        temp = H->array[0];
        H->array[0] = H->array[H->count-1];
        H->count--;
        percolate_down(H,0);
        H->array[H->count] = temp;
    }
    H->count=n;
}

void print(struct Heap *H)
{
    int i;
    for(i=0;i<H->count;i++)
        printf(" %d ",H->array[i]);
    printf("\n");
}

void destroy_Heap(struct Heap *H)
{
    free(H->array);
    free(H);
    H=NULL;
}

int main()
{
    int capacity,data;
    printf("Enter the capacity of heap: ");
    scanf("%d",&capacity);
    struct Heap *H=create_Heap(capacity);
    printf("Enter Data (-1 to abort): ");
    scanf("%d",&data);
    while(data != -1)
    {
        if(H->count == H->capacity)
            resize(H);
        H->array[H->count] = data;
        H->count++;
        printf("Enter Data (-1 to abort): ");
        scanf("%d",&data);
    }
    build_heap(H);
    printf("\n After heapify: ");
    print(H);
    printf("After Heap Sort: ");
    Heap_sort(H);
    print(H);
    destroy_Heap(H);
    return 0;
}