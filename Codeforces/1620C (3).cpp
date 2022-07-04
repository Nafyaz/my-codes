#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, k, x, cnt;
    string s, ans;

    cin >> n >> k >> x >> s;

    reverse(s.begin(), s.end());

    x--;
    ans = "";
    for(auto c : s)
    {
        if(c == 'a')
        {
            ans += string(x%(k*cnt+1), 'b');
            ans.push_back('a');
            x /= (k*cnt+1);
            cnt = 0;
        }
        else
            cnt++;
    }

    ans += string(x%(k*cnt+1), 'b');
    x /= (k*cnt+1);
    cnt = 0;

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
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