#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

string a;
int pref[MAXN], suff[MAXN];

void solve(int caseno)
{
    ll n, m, i, j, total, ans, x, y, sub, add;

    cin >> n >> m >> a;

    total = 0;
    for(i = 1; i <= n; i++)
    {
        total += (a[i-1] == '1');

        pref[i] = pref[i-1] + (a[i-1] == '1');
    }

    suff[n+1] = 0;
    for(i = n; i >= 1; i--)
        suff[i] = suff[i+1] + (a[i-1] == '1');

    if(total == 0)
    {
        cout << n*m << "\n";
        return;
    }

    ans = 0;
    if(m%2 == 0)
        ans++;

    for(i = 1; i < n; i++)
    {
        if((suff[i+1] - pref[i])%total != 0)
            continue;

        sub = (suff[i+1] - pref[i])/total;
        add = m-1;

        x = sub+add;

        if(x < 0 || x%2)
            continue;
        x /= 2;

        y = add-x;
        if(y < 0)
            continue;

        ans++;
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

