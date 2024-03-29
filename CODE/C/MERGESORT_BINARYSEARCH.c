#include<stdio.h>

void merge(int A[], int temp[], int left, int mid, int right);

void mergesort(int A[],int temp[],int left, int right)
{
    int mid;
    if(right > left)
    {
        mid = (right + left)/2;
        mergesort(A, temp, left, mid);
        mergesort(A, temp, mid+1, right);
        merge(A, temp, left, mid+1, right);
    }
}

void merge(int A[], int temp[], int left, int mid, int right)
{
    int i, left_end, size, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;
    while((left <= left_end) && (mid <= right))
    {
        if(A[left] <= A[mid])
        {
            temp[temp_pos] = A[left];
            temp_pos = temp_pos + 1;
            left=left +1;
        }
        else
        {
            temp[temp_pos] = A[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    while(left <= left_end) 
    {
        temp[temp_pos] = A[left];
        left = left + 1; 
        temp_pos = temp_pos + 1;
    }
    while(mid <= right) 
    {
        temp[temp_pos] = A[mid];
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    for(i=0; i <= size; i++)
    {
        A[right] = temp[right];
        right = right - 1;
    }
}


void binsearch(int A[],int n,int key)
{
    int low = 0, high = n, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(A[mid] == key)
        {
            printf("\n%d is present ",key);
            return;
        } 
        else if(A[mid] > key)
            high = mid-1;
        else    
            low = mid + 1;
    }
    printf("\n%d Not Found",key);
}

void print(int A[],int n)
{
    for(int i=0;i<=n;i++)
        printf("%d ",A[i]);
}

int main()
{
    int A[]={23, 12, 67, 34, 8, 29, 98, 3};
    int size=sizeof(A)/sizeof(int);
    int temp[size];

    printf("The given array is :\n");
    print(A,size-1);

    // mergesort function
    mergesort(A,temp,0,size-1);

    //sorted array is printed
    printf("\nThe sorted array is : \n");
    print(A,size-1);

    // chech whether 33 is present
    binsearch(A,size-1,33);
}