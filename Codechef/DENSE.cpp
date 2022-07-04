#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

ll front[MAXN], back[MAXN];

void solve(ll caseno)
{
    ll i, n, ans;
    string s;

    cin >> n >> s;

    front[0] = 0;
    for(i = 0; i < n; i++)
        front[i+1] = front[i] + (s[i] == '(');

    back[n+1] = 0;
    for(i = n-1; i >= 0; i--)
        back[i+1] = back[i+2] + (s[i] == ')');

    ans = 0;
    for(i = 1; i < n; i++)
        ans = max(ans, 2*min(front[i], back[i+1]));

    cout << n - ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}