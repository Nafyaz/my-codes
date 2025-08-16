#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[5003];

int main()
{
    int n, x;

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);

    for (int i = 0; i + 2 < n; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            if (x - a[i].first < a[left].first + a[right].first)
            {
                right--;
            }
            else if (x - a[i].first > a[left].first + a[right].first)
            {
                left++;
            }
            else
            {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
