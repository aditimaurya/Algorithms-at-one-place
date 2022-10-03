#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &x : arr)
        cin >> x;
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    int key;
    cin >> key;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (arr[mid] == key)
        {
            cout << "Found at index " << mid << endl;
            return 0;
        }
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}