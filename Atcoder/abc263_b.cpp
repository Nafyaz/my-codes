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

int p[55];

void solve(int caseno)
{
    int n, i, ans;

    cin >> n;

    for(i = 2; i <= n; i++)
        cin >> p[i];

    ans = 0;
    while(n > 1)
    {
        ans++;
        n = p[n];
    }

    cout << ans << "\n";
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

