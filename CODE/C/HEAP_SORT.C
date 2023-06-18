/*
COMPLEXITY OF INSERTION IN HEAP TREE IS O(logn)
CREATING HEAP TREE IS O(nlogn)
DELETION IS O(nlogn)

HEAP SORT - nlogn + nlogn = 2logn = O(nlogn)
*/

#include<stdio.h>
#include<stdlib.h>

struct Heap{
    int *array;
    int count;
    int capacity;
};

void resize(struct Heap *H)
{
    H->array=(int *)realloc(H->array,sizeof(int)*H->capacity*2);
    H->capacity=H->capacity*2;
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

void insert_Heap(struct Heap *H,int data)
{
    int i;
    if(H->count == H->capacity)
        resize(H);
    i = H->count;
    while(i>0 && data > H->array[(i-1)/2])
    {
        H->array[i] = H->array[(i-1)/2];
        i = (i-1)/2;
    }
    H->array[i] = data;
    H->count++;
}

int delete_max(struct Heap *H)
{
    int i=0,j,del,temp;
    del = H->array[0];
    H->array[0] = H->array[H->count-1];
    H->count--;
    j = 2*i+1;
    while(j < H->count)
    {
        if(j+1 < H->count && H->array[j] < H->array[j+1])
            j=j+1;
        if(H->array[i] < H->array[j])
        {
            temp = H->array[i];
            H->array[i] = H->array[j];
            H->array[j] = temp;
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    return del;
}

void Heap_sort(struct Heap *H)
{
    int n=H->count;
    int i,temp;
    for(i=n-1;i>0;i--)
    {
        temp = delete_max(H);
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
        insert_Heap(H,data);
        printf("Enter Data (-1 to abort): ");
        scanf("%d",&data);
    }
    printf("\n After heapify: ");
    print(H);
    printf("After Heap Sort: ");
    Heap_sort(H);
    print(H);
    destroy_Heap(H);
    return 0;
}