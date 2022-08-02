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
    int n, i, H, M, Minutes, h, m, minutes, ans;

    cin >> n >> H >> M;
    Minutes = H*60 + M;

    ans = INT_MAX;
    for(i = 0; i < n; i++)
    {
        cin >> h >> m;
        minutes = h*60 + m;

        if(minutes < Minutes)
            minutes += 24*60;

        ans = min(ans, minutes - Minutes);
    }

    cout << ans/60 << " " << ans%60 << "\n";
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
