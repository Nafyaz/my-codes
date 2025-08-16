#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 10004

ll n;
string s;
set<string> st;
ll dp[MAXN][4];

bool call(ll i, ll prevLen)
{
    if(dp[i][prevLen] != -1)
        return dp[i][prevLen];

    if(i == n)
        return 1;

    bool ret = 0;

    if((n-i == 3 || n-i > 4) && (prevLen != 3 || s.substr(i-3, 3) != s.substr(i, 3)))
    {
        if(call(i + 3, 3) == 1)
        {
            st.insert(s.substr(i, 3));
            ret = 1;
        }
    }

    if((n-i == 2 || n-i > 3) && (prevLen != 2 || s.substr(i-2, 2) != s.substr(i, 2)))
    {
        if(call(i + 2, 2) == 1)
        {
            st.insert(s.substr(i, 2));
            ret = 1;
        }
    }

    return dp[i][prevLen] = ret;
}

void solve(ll caseno)
{
    ll i;

    cin >> s;
    n = s.size();

    for(i = 5; i < 8; i++)
    {
        memset(dp, -1, sizeof(dp));
        call(i, 0);
    }

    cout << st.size() << "\n";
    for(auto u : st)
        cout << u << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}