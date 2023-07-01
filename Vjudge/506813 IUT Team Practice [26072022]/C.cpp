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

void solve(int caseno)
{
    ll n, a, i, pos, sum, ans;

    cin >> n;

    ans = pos = sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(a >= 0)
        {
            pos++;
            sum += a;
        }
        else
        {
            ans += pos*sum;
            pos = 0;
            sum = 0;

            ans += a;
        }
    }

    if(pos)
        ans += pos*sum;

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