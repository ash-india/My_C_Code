#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"Base Construct"<<endl;
    }
    virtual ~Base(){
        cout<<"Base Destruct"<<endl;
    }
};
class Derived:public Base{
public:
// Derived(){
//     cout<<"Derived Construct"<<endl;
// }
~Derived(){
    cout<<"Derived Destruct"<<endl;
}
};
int main()
{
    Base *b=new Derived();
    delete b;
    //return 0;
}