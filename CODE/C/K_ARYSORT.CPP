#include <bits/stdc++.h>

using namespace std;
int binSearch(int arr[], int x, int lb, int ub)
{
    // cout << "entered binary search";
    int mid;
    while (lb <= ub)
    {
        mid = (ub - lb) / 2 + lb;
        if (arr[mid] == x)
        {
            cout << "mil gya bhai";
            return 1;
        }
        else if (arr[mid] > x)
            ub = ub - 1;
        else
            lb = lb + 1;
    }
    return 0;
}
int K_ary_search(int arr[], int size, int x, int k)
{
    int *mid, lb = 0, ub = size - 1, i;
    mid = (int *)malloc(4 * (k - 1));
    int c = 0;
    while (lb <= ub)
    {
        cout << c++ << endl;
        // cout <<c++<< endl<< lb << "     " << ub << endl;
        for (i = 0; i < k - 1; i++)
        {
            int term = lb + (i + 1) * ((ub - lb) / k);
            if (term > lb)
                mid[i] = term;
            else
                return (binSearch(arr, x, lb, ub));
            // cout << mid[i] << "    ";
        }
        cout << endl;
        for (i = 0; i < k - 1; i++)
        {
            if (arr[mid[i]] == x)
            {
                cout << "mil gya h wo bhi " << mid[i] << " pe";
                return 1;
            }
            // cout << mid[i] << "->" << arr[mid[i]] << endl;
            // cout << mid[i + 1] << "->" << arr[mid[i + 1]] << endl;
            if (i == 0 && arr[mid[i]] > x)
            {
                ub = mid[i] - 1;
                break;
            }
            else if (i == k - 2 && arr[mid[i]] < x)
            {
                lb = mid[i] + 1;
                break;
            }
            else if (arr[mid[i]] < x && arr[mid[i + 1]] > x)
            {
                // cout << "i ka value " << i << endl;
                lb = mid[i] + 1;
                ub = mid[i + 1] - 1;
                // cout << "han aaya" << endl;
                // cout << mid[i] + 1 << "    " << mid[i + 1] - 1 << endl;
                break;
            }
        }
    }
    return 0;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    cout << K_ary_search(arr, 40, 3, 15);
}