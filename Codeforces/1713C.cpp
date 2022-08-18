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

int ans[MAXN];

void solve(int caseno)
{
    int n, m, i, sq;

    cin >> n;

    sq = INT_MAX;
    m = n-1;
    for(i = m; i >= 0; i--)
    {
        if(sq - i > m)
        {
            m = i;

            sq = sqrt(m);
            if(sq*sq == m)
                sq = sq*sq;
            else
                sq = (sq+1)*(sq+1);
        }

        ans[i] = sq - i;
    }

    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
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