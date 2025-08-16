#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

double x, t;

double getWork(double s)
{
    double m, c;
    if(6*s <= t)
    {
        m = 6*x/t;
        c = 0;
    }
    else if(3*s <= t)
    {
        m = (100 - x) / (t/3 - t/6);
        c = 100 - m*t/3;
    }
    else
        return (t-s) * 100;

    return (t - s) * (m*s + c);
}

void solve(ll caseno)
{
    ll i;
    double low, high, mid1, mid2, v1, v2, ans;

    cin >> x >> t;

    // cout << getWork(t/6) << "\n";

    ans = 0;
    low = 0;
    high = t/6;
    for(i = 0; i < 100; i ++)
    {
        mid1 = (2*low + high) / 3;
        mid2 = (low + 2*high) / 3;

        v1 = getWork(mid1);
        v2 = getWork(mid2);

        if(v1 < v2)
        {
            ans = max(ans, v2);
            low = v1;
        }
        else
        {
            ans = max(ans, v1);
            high = v2;
        }
    }

    low = t/6;
    high = t/3;
    for(i = 0; i < 100; i ++)
    {
        mid1 = (2*low + high) / 3;
        mid2 = (low + 2*high) / 3;

        v1 = getWork(mid1);
        v2 = getWork(mid2);

        if(v1 < v2)
        {
            ans = max(ans, v2);
            low = mid1;
        }
        else
        {
            ans = max(ans, v1);
            high = mid2;
        }
    }

    ans = max(ans, getWork(t/3));

    cout << fixed << setprecision(8) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}