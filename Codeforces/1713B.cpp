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

int a[MAXN];

void solve(int caseno)
{
    int n, i, mx = 0, mxIdx;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        if(mx < a[i])
        {
            mx = a[i];
            mxIdx = i;
        }
    }

    for(i = 1; i <= mxIdx; i++)
    {
        if(a[i-1] > a[i])
        {
            cout << "NO\n";
            return;
        }
    }

    for(i = mxIdx; i+1 < n; i++)
    {
        if(a[i] < a[i+1])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
 