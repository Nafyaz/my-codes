#include <bits/stdc++.h>
using namespace std;

int main()
{
    int low = 1, high = 1000000009, ans, mid;
    string s;

    while (low <= high)
    {
        if (low == high)
        {
            cout << "! " << low << "\n";
            return 0;
        }
        mid = (low + high) / 2;

        cout << "? " << mid << "\n";

        cin >> s;
        if (s == "NO")
            high = mid;
        else
            low = mid + 1;
    }
}