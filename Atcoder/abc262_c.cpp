#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 500005

ll a[MAXN];

void solve(int caseno)
{
    ll n, i, ans, cnt;

    cin >> n;

    ans = cnt = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == i)
            cnt++;
        else if(a[i] < i && a[a[i]] == i)
            ans++;
    }

    cout << ans + cnt*(cnt-1)/2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
