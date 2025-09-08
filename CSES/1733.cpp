#include <bits/stdc++.h>
using namespace std;

vector<int> Z(string s)
{
    int n = s.size();
    vector<int> z(n, 0);

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    int n;
    cin >> s;
    n = s.size();

    vector<int> z = Z(s);

    for (int i = 1; i < n; i++)
    {
        if (i + z[i] == n)
            cout << i << " ";
    }

    cout << n << "\n";
}