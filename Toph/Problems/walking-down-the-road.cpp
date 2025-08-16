#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

double a[MAXN];

void solve(int caseno)
{
    int i, n, m;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    cout << fixed << setprecision(6) << (a[n/2] - a[n/2-1]) / m << "\n"; 
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