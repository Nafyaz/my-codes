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
    ll n, m, i, x, p;
    ll val, prevPos, prevSlope, low, high;
    vector<pll> rain;
    map<ll, ll> slopes;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> x >> p;

        rain.push_back({x, p});

        slopes[x-p] += 1;
        slopes[x] -= 2;
        slopes[x+p] += 1;
    }

    low = INT_MAX;
    high = INT_MIN;

    val = prevPos = prevSlope = 0;
    for(auto [pos, slope] : slopes)
    {
        val += (pos - prevPos)*prevSlope;

        if(val > m)
        {
            low = min(low, pos - (val - m));
            high = max(high, pos + (val - m));
        }

        prevPos = pos;
        prevSlope += slope;
    }

    for(auto [x, p] : rain)
    {
        if(x-p <= low && high <= x+p)
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
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