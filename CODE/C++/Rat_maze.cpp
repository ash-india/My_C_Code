#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,q;
	cin>>n>>q;
	int i,j;
	char ch;
	int hh[n+1][n+1]={0};
	string sp[n];
	for(i=1;i<=n;i++)
	{
	   cin>>sp[i];
	}
	for(i=1;i<n+1;i++)
	{
	    for(j=1;j<n+1;j++)
	    {
	        if(sp[i-1][j-1]=='.')
	            hh[i][j]=0;
	        else if(sp[i-1][j-1]=='*')
	            hh[i][j]=1;
	    }
	}
	int pf[n+1][n+1]={0};
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        pf[i][j]=hh[i][j]+pf[i][j-1]+pf[i-1][j]-pf[i-1][j-1];
	    }
	}
	while(q--)
	{
	    string x;
	    cin>>x;
	    int count=0;
	    for(i=0;i<x.length();i++)
	    {
	        if(x[i]==' ')
	            count++;
	    }
	    if(count==2)
	    {
	        int arr[3];
	        for(j=0,i=0;i<3;i++)
	        {
	            string spp;
	            
	            while(x[j]!=' ' && x[j]!='\n')
	            {
	                spp.push_back(x[j]);
	                j++;
	            }
	            arr[i]=stoi(spp);
	        }
	        int qq;
	        if(pf[arr[1]][arr[2]]==1)
	            qq=-1;
	        else
	            qq=1;
	        for(i=arr[1];i<=n;i++)
	        {
	            for(j=arr[2];j<=n;j++)
	                pf[i][j]+=qq;
	        }
	    }
	    else if(count==4)
	    {
	        int arr[5];
	        for(j=0,i=0;i<5;i++)
	        {
	            string spp;
	            
	            while(x[j]!=' ' && x[j]!='\n')
	            {
	                spp.push_back(x[j]);
	                j++;
	            }
	            arr[i]=stoi(spp);
	        }
	        cout<<pf[arr[3]][arr[4]]-pf[arr[1]-1][arr[4]]-pf[arr[3]][arr[2]-1]+pf[arr[1]-1][arr[2]-1];
	        cout<<endl;
	    }
	}
	return 0;
}
