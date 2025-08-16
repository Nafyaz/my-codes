#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll a[MAXN], gaps[MAXN];

void solve(int caseno)
{
    ll n, m, i, j, ans, days;

    cin >> n >> m;

    for(i = 0; i < m; i++)
        cin >> a[i];

    sort(a, a+m);

    for(i = 0; i+1 < m; i++)
        gaps[i] = a[(i+1)%m] - a[i] -1;
    gaps[m-1] = a[0]-1 + n - a[m-1];

//    cout << "gaps: ";
//    for(i = 0; i < m; i++)
//        cout << gaps[i] << " ";
//    cout << "\n";

    sort(gaps, gaps+m, greater<ll>());

    ans = days = 0;
    for(i = 0; i < m; i++)
    {
        if(gaps[i] - 2*days >= 2)
        {
            ans += gaps[i] - 2*days - 1;
            days += 2;
        }
        else if(gaps[i] -2*days == 1)
        {
            ans ++;
            days ++;
        }
    }

    cout << n - ans << "\n";
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
