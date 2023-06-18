/*
Mahmud solved some easy math problems from SPOJ and called himself king of number theory. 
GodFather Rashad heard it and got angry, so he kidnapped Mahmud. 
Rashad gave him a task called "Operation - Modulo". Mahmud must solve this task, you know what will happen otherwise ;(. 
In the Operation - Modulo, we define a function f(n) = (n mod 1) + (n mod 2) + (n mod 3) + ... + (n mod n), 
where n mod x donates the remainder when dividing n by x. 
Rashad interests with integers n such that f(n) = f(n-1), so he gave Mahmud two numbers L and R, 
and demands him to find the sum of all integers n such that L ≤ n ≤ R and f(n) = f(n-1).

Input
First and the only line of input contains two positive integers, L and R (1 ≤ L ≤ R ≤ 1018).

1 3

Output
Print the demanded sum in one line.

3
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long l,r,poww;
    cin>>l>>r;
    float logg=log2(l);
    if(logg-(long long)logg >0)
        poww=(long long)logg +1;
    else
        poww=(long long)logg;
    long long sum=0;
    l=pow(2,poww);
    while(l<=r)
    {
        sum=sum+l;
        l=l*2;
    }
    cout<<sum;
}