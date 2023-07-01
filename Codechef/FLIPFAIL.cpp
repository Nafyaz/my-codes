#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int i, ones, zeros, cost, ans;
    string s;

    cin >> s;

    ones = zeros = 0;
    for(i = 0; i < s.size(); i++)
    {
        ones += (s[i] == '1');
        zeros += (s[i] == '0');
    }

    ans = INT_MAX;

    cost = 0;
    for(i = 0; i < zeros; i++)
        cost += (s[i] == '1');
    ans = min(ans, cost);

    for(; i < s.size(); i++)
    {
        cost += (s[i] == '1');
        cost -= (s[i-zeros] == '1');

        ans = min(ans, cost);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
