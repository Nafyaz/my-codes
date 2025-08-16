#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

string s[2];
int dp[2][MAXN];

int func(int side, int start)
{
    if (start >= s[0].size())
        return 0;

    if (dp[side][start] != -1)
        return dp[side][start];

    return dp[side][start] = min(s[side][start] - '0' + func(side, start + 1), s[side][start] - '0' + 1 + func(side ^ 1, start + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s[0];

    s[0] = '0' + s[0];

    for (int i = 0; i < s[0].size(); i++)
    {
        int digit = s[0][i] - '0';

        if (i != s[0].size() - 1)
            s[1].push_back('9' - digit);
        else
            s[1].push_back('9' + 1 - digit);
    }

    memset(dp, -1, sizeof dp);
    cout << func(0, 0) << "\n";
}