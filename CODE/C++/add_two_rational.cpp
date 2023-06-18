//Write a class for RAtional number(p/q) with overloading + and << operator

#include<iostream>
using namespace std;

class rational
{
    private:
    int p;
    int q;
    public:
    rational(int num=0,int denom=1)
    {
        p=num;
        q=denom;
    }
    friend rational operator+(rational R1,rational R2);
    friend ostream &operator<<(ostream &out,rational &R);
};

rational operator+(rational R1,rational R2)
{
    rational R3;
    if(R1.q==0 || R2.q==0)
    {
        R3.q=0;
        R3.p=0;
    }
    else
    {
        R3.p=R1.p*R2.q + R1.q*R2.p;
        R3.q=R1.q*R2.q;
    }
    return R3;
}

ostream &operator<<(ostream &out,rational &r)
{
    out<<r.p<<"/"<<r.q;
    return out;
}

int main()
{
    int p,q;
    cout<<"Enter numerator an denominator for 1st fraction: ";
    cin>>p>>q;
    rational r1(p,q);
    cout<<"Enter numerator an denominator for 2nd fraction: ";
    cin>>p>>q;
    rational r2(p,q);
    rational r3=r1+r2;
    cout<<"Sum of "<<r1<<" and "<<r2<<" is "<<r3<<endl;
    return 0;
}