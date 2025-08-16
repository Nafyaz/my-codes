#include <bits/stdc++.h>
using namespace std;

int a[5003];
unordered_map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (mp.find(x - a[i] - a[j]) != mp.end())
            {
                cout << mp[x - a[i] - a[j]] << " " << i << " " << j << "\n";
                return 0;
            }
        }

        mp[a[i]] = i;
        // cout << i << "\n";
    }

    cout << "IMPOSSIBLE\n";
}