#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, i, cnt, ans;
    string s;

    cin >> n >> s;

    ans = 0;
    for(i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1])        
            ans += i;
    }

    cout << n*(n+1)/2 - ans << "\n";
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