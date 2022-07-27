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
    int n, m, i, mxR, mxW;
    int r[102], w[102];

    cin >> n >> m;

    mxR = mxW = 0;
    for(i = 0; i < m; i++)
    {
        cin >> r[i] >> w[i];
        mxR = max(mxR, r[i]);
        mxW = max(mxW, w[i]);
    }

    if(mxR + mxW > n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(i = 0; i < n; i++)
    {
        if(i < mxR)
            cout << "R";
        else
            cout << "W";
    }

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

