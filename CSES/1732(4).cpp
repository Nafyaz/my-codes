#include <bits/stdc++.h>
using namespace std;

int z[1000006];

void Z(string s)
{
    int n = s.size();
    z[0] = 0;

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;

    cin >> s;

    Z(s);

    for (int i = s.size() - 1; i > 0; i--)
    {
        if (i + z[i] == s.size())
            cout << z[i] << " ";
    }
}