#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<5;i++)
     v.push_back(i);
    auto id = find(v.begin(),v.end(),v.back());
    // if(id==v.end())
    //     cout<<"not found";
    // else
    //     printf("%u\n",id);
    for(int i=0;i<=v.size();i++)
        printf("%u\n",&v[i]);
    printf("%u",v.end());
    printf("\n%u\n",id);
    auto ghar = v.end();
    ghar--;
    cout<<*ghar;
    return 0;
}
