#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool vis[50][600];
string dp[50][600];
string mn[50];

string getMin(int rem, int mask)
{
    if(vis[])
}

void solve(int caseno)
{
    int i;

    memset(vis, 0, sizeof vis);
    for(i = 1; i <= 45; i++)
        mn = getMin(i, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}