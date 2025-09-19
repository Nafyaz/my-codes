#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string s)
{
    int n = s.size();
    vector<int> kmp(n);

    for (int i = 1; i < n; i++)
    {
        int j = kmp[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = kmp[j - 1];
        }

        if (s[i] == s[j])
            j++;

        kmp[i] = j;
    }

    return kmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> kmp = KMP(s);

    stack<int> ans;
    for (int i = s.size() - 1; i > 0 && kmp[i] > 0; i = kmp[i] - 1)
    {
        ans.push(kmp[i]);
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}