#include <bits/stdc++.h>
using namespace std;

template <typename T>
T maxi(T x,T y)
{
  return x>y?x:y;
}

int main() 
{
    cout<<maxi(10,15)<<endl;
    cout<<maxi<float>(11.5,9.7);
    return 0;
} 