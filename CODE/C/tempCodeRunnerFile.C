#include<stdio.h>
int main()
{
  int n,count=0;
  fscanf(stdin,"%d",&n);
  if(n!=0)
  {
    while(n%2==0)
    {
      n=n/2;
      count++;
    }
    count++;
  }
  fprintf(stdout, "%d",count);
}