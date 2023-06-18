#include <bits/stdc++.h>
using namespace std;

int check(int n)
{
    float p = log(n) / log(2);
    if (p - (int)p > 0)
        return (int)p;
    return 0;
}

int first(int n)
{
    int count = 0, sq, ch;

    ch = check(n);
    while (ch && n > 1)
    {
        sq = ch;
        n = n - pow(2, sq);
        count++;
        ch = check(n);
    }
    return count;
}

int second(int N)
{
    int c = 0;
    int X;
    while (N)
    {
        X = N % 2;
        N = N / 2;
        if (X == 1)
            c++;
    }
    return c - 1;
}

int main()
{
    // your code goes here
    int t, count = -1;
    cin >> t;
    while (t < 100000)
    {
        if (first(t) != second(t))
            cout << t << endl;
        t++;
    }
    cout << first(t) << endl;
    return 0;
}
