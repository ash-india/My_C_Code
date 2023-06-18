#include<stdio.h>

int partition(int a[],int low, int high)
{
    int left, right, partition_element, temp;
    left=low;
    right=high;
    partition_element=a[low];
    while(left<right)
    {
        do{
            left++;
        }while(a[left] <= partition_element);

        do{
            right--;
        }while(a[right] > partition_element);

        if(left<right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    a[low] = a[right];
    a[right] = partition_element;
    return right;
}

void quicksort(int a[],int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot = partition(a,low,high);
        quicksort(a,low,pivot);
        quicksort(a,pivot+1,high);
    }
}

void display(int a[], int n)
{
    int i;
    printf("\nSorted:");
    for(i=0;i<n;i++)
        printf(" %d",a[i]);
}

int main()
{
    int n,i;
    printf("Enter No. of Elements: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n);
    display(arr,n);
    return 0;
}