#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    vector<int> v;
    int value,i,temp,f=0;
    int max1=0,maxx=0;
    for(i=0;i<n;i++)
    {
        cin>>value;
        v.push_back(value);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        temp=v[i];
        maxx=0;
        while(v[i]==temp && i<n)
        {
            maxx++;
        }
        if(maxx==max1)
            f=1;
        else if(maxx>max1)
        {
            max1=maxx;
            f=0;
        }
    }
    
    if(f==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    fun(n);
	}
	return 0;
}
