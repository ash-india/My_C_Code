#include <iostream>
using namespace std;
class StackOverFlow : exception
{
};
class StackUnderFlow : exception
{
};
class Stack
{
private:
    int *stk;
    int top = -1;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        stk = new int[this->size];
    }
    void push(int x)
    {
        if (top == size - 1)
            throw StackOverFlow();
        top++;
        stk[top] = x;
    }
    int pop()
    {
        if (top == -1)
            throw StackUnderFlow();
        return stk[top--];
    }
    friend ostream &operator<<(ostream &out,Stack &st);
};
ostream &operator<<(ostream &out,Stack &st)
{
    if(st.top==-1)
        out<<"Stack Under Flow"<<endl;
    for(int i=st.top;i>=0;i--)
        out<<st.stk[i]<<endl;
    return out;
}
int main()
{
    int n,ch,val;
    cout<<"Enter Size: ";
    cin>>n;
    Stack st(n);
    try{
        do{
            cout<<"1 Push"<<endl;
            cout<<"2 Pop"<<endl;
            cout<<"3 Display Stack"<<endl;
            cout<<"4 Exit"<<endl;
            cout<<"Enter Choice";
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"Enter Value: ";
                        cin>>val;
                        st.push(val);
                        break;
                case 2: val=st.pop();
                        cout<<val<<endl;
                        break;
                case 3:cout<<st;
                        break;
                case 4: cout<<"Thank You"<<endl;
                        break;
                default: cout<<"Wrong Choice "<<endl;
            }
        }while(ch!=4);
    }
    catch(StackOverFlow e)
    {
        cout<<"Stack Overflow";
    }
    catch(StackUnderFlow)
    {
        cout<<"Stack Underflow";
    }
    return 0;
}
