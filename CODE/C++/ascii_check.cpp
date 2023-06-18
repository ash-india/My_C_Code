#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        char ch;
        int ch_ka, sum = 0;
        while ((ch = getchar()) != '\n')
        {
            ch_ka = (int)ch;
            if (ch_ka > 47 && ch_ka < 58)
                sum = sum + ch_ka - 48;
        }
        cout << sum << endl;
    }
    return 0;
}
