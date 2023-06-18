# include<stdio.h>
 
void knapsack(int n, float weight[], float profit[], float capacity) {
  float tp = 0, rem;
   int i , u;
   u = capacity;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)  rem = u / weight[i];
 
   tp = tp + (rem * profit[i]);
 
 
   printf("\nMaximum profit is:- %f", tp);
 
}
 
int main() {
  
  int num;
   printf("\nEnter the no. of objects:- \n");
   scanf("%d", &num);
    float weight[num], value[num], capacity;
   int  i, j;
   float ratio[num], temp;
 
   printf("\nEnter the weight  of each object:- \n");
   for (i = 0; i < num; i++) {
      scanf("%f", &weight[i]);
   }

   printf("\nEnter the values of each object:- \n");

    for (i = 0; i < num; i++) {
      scanf("%f", &value[i]);
   }
 
   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = value[i] / weight[i];
   }
 // sorting
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = value[j];
            value[j] = value[i];
            value[i] = temp;
         }
      }
   }
   printf("the weight and profits are after weight value sorting \n");
   for (int i = 0; i < num; i++)
   {
       printf("%f\t%f\n",weight[i],value[i]);
   }
   
 
   knapsack(num, weight, value, capacity);
   return(0);
}
