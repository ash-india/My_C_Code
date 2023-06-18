/*
2[a3[bc]d] = 2[abcbcbcd]=abcbcbcdabcbcbcd
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string sp;
    cin>>sp;
    stack <char> st;
    for(auto &ch:sp)
    {
        if(ch!=']')
        {
            st.push(ch);
        }
        else
        {
            string temp;
            while(!st.empty() && st.top()!='[')
            {
                temp.push_back(st.top());
                st.pop();
            }
            st.pop();
            vector <int> n;
            while(!st.empty() && isdigit(st.top()))
            {
                n.push_back(st.top() - '0');
                st.pop();
            }
            string rev;
            while(temp.size())
            {
                rev.push_back(temp[temp.size()-1]);
                temp.pop_back();
            }
            int num=0;
            while(n.size())
            {
                num = num *10 + n[n.size()-1];
                n.pop_back();
            }
            temp=rev;
            for(int i=1;i<num;i++)
            {
                temp+=rev;
            }
            for(auto c:temp)
            {
                st.push(c);
            }
        }
    }
    stack <char> stt;
    while(st.size())
    {
        stt.push(st.top());
        st.pop();
    }
    while(stt.size())
    {
        cout<<stt.top();
        stt.pop();
    }
}