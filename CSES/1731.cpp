#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006
#define MOD 1000000007

string s;
int trie[MAXN][26];
bool hasEnded[MAXN];
int id;
int dp[MAXN];

void Add(string w)
{
    int r = 0;

    for (auto c : w)
    {
        if (trie[r][c - 'a'] == 0)
            trie[r][c - 'a'] = ++id;

        r = trie[r][c - 'a'];
    }

    hasEnded[r] = true;
}

int func(int idx)
{
    if (idx == s.size())
        return 1;

    if (dp[idx] != -1)
        return dp[idx];

    int r = 0, ret = 0;
    for (int i = idx; i < s.size(); i++)
    {
        r = trie[r][s[i] - 'a'];

        if (r == 0)
            break;

        if (hasEnded[r])
            ret = (ret + func(i + 1)) % MOD;
    }

    return dp[idx] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        string w;
        cin >> w;

        Add(w);
    }

    memset(dp, -1, sizeof dp);
    cout << func(0) << "\n";
}