#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;
    sort(s.begin(), s.end());

    string ans[n];
    int strStartIdx = 0, sIdx = 0;
    for (int charIdx = 0; charIdx < l; charIdx++)
    {
        for (int strIdx = strStartIdx; strIdx < k; strIdx++)
        {
            if (sIdx != 0 && s[sIdx - 1] != s[sIdx])
                strStartIdx = strIdx;

            ans[strIdx].push_back(s[sIdx]);
            sIdx++;
        }
    }

    for (int strIdx = 0; strIdx < n; strIdx++)
    {
        while (ans[strIdx].size() < l)
        {
            ans[strIdx].push_back(s[sIdx]);
            sIdx++;
        }

        cout << ans[strIdx] << "\n";
    }
}