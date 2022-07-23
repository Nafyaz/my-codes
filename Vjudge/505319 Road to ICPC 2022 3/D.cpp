#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

pair<long double, long double> bottle[MAXN];
pair<long double, int> a2bottle[MAXN], b2bottle[MAXN];

long double getDist(pair<long double, long double> x, pair<long double, long double> y)
{
    return sqrt((x.ff - y.ff)*(x.ff - y.ff) + (x.ss - y.ss)*(x.ss - y.ss));
}

void solve(int caseno)
{
    int n, i;
    pair<long double, long double> a, b, t;
    long double total, ans;

    cin >> a.ff >> a.ss;
    cin >> b.ff >> b.ss;
    cin >> t.ff >> t.ss;

    cin >> n;

    total = 0;
    for(i = 0; i < n; i++)
    {
        cin >> bottle[i].ff >> bottle[i].ss;

        total += 2*getDist(bottle[i], t);

        a2bottle[i].ff = getDist(a, bottle[i]) - getDist(bottle[i], t);
        b2bottle[i].ff = getDist(b, bottle[i]) - getDist(bottle[i], t);

        a2bottle[i].ss = b2bottle[i].ss = i;
    }

    sort(a2bottle, a2bottle+n);
    sort(b2bottle, b2bottle+n);

    ans = total + min(a2bottle[0].ff, b2bottle[0].ff);

    if(n == 1)
    {
        cout << fixed << setprecision(8) << ans << "\n";
        return;
    }

    if(a2bottle[0].ss != b2bottle[0].ss)
        ans = min(ans, total + a2bottle[0].ff + b2bottle[0].ff);
    else
        ans = min(ans, total + min(a2bottle[0].ff + b2bottle[1].ff, a2bottle[1].ff + b2bottle[0].ff));

    cout << fixed << setprecision(8) << ans << "\n";
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
