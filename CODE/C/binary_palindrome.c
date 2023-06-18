// A PROGRAM TO CHECK IF THE BINARY REPRESENTATION OF INPUT NUMBERS ARE PALINDROME OR NOT. 


#include<stdio.h>
int palindrome(int bin[],int n);
int binary(int A[],int n)
{
  int i,p,result=0;
  for(i=0;i<n;i++)
  {
    int x=0;
    int bin[32];
    while(A[i]>0)
    {
      bin[x++]=A[i]%2;
      A[i]=A[i]/2;
    }
    p=palindrome(bin,x);
    if(p)
      result++;
  }
  return result;
}
int palindrome(int bin[],int n)
{
  int j=n-1;
  for(int i=0;i<n/2;i++,j--)
  {
    if(bin[i]==bin[j])
      continue;
    else
      return 0;
  }
  return 1;
}

int main()
{
 int n,i;
 scanf("%d",&n);
 int A[n];
 for(i=0;i<n;i++)
  scanf("%d",&A[i]);
 printf("%d",binary(A,n));
}