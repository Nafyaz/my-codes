#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000009
#define MAXN 100005

void solve(int caseno)
{
    ll n, i, x, ans = 1;

    cin >> n; 

    for(i = 0; i < n; i++)
    {
        cin >> x;
        ans = (ans * (1 + 2*x)) % MOD;
    }

    ans--;

    if(ans%2)
        ans = ((ans + MOD)/2) % MOD;
    else
        ans = ans / 2;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}