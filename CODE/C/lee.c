#include<stdio.h>
#include<stdlib.h>

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

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    int *answer=(int *)calloc(queriesSize,sizeof(int));
    quicksort(nums,0,numsSize);
    int i,j;
    for(i=0;i<queriesSize;i++)
        answer[i]=0;
    for(i=1;i<numsSize;i++)
    {
        nums[i]=nums[i]+nums[i-1];
    }
    for(i=0;i<queriesSize;i++)
    {
        for(j=0;j<numsSize;j++)
        {
            if(nums[j]<=queries[i])
                answer[i]=j+1;
            else
                break;
        }
    }
    
    *returnSize=queriesSize;
    return answer;
}

int main()
{
    int nums[4]={2,3,4,5};
    int queries[1]={0};
    int returnsize;
    int *answers;
    answers=answerQueries(nums,4,queries,1,&returnsize);
    for(int i=0;i<returnsize;i++)
    {
        printf(" %d ",answers[i]);
    }
}