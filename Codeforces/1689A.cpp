#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll n, m, k, idx[2], cnt;
    string a[2];
    int lastTaken;

    cin >> n >> m >> k;
    cin >> a[0] >> a[1];

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    idx[0] = idx[1] = cnt = 0;
    lastTaken = -1;
    while(idx[0] < n && idx[1] < m)
    {
        // show(idx[0]);
        // show(idx[1]);
        // cout << "\n";

        if(cnt == k)
        {
            lastTaken = !lastTaken;
            cout << a[lastTaken][idx[lastTaken]];

            idx[lastTaken]++;
            cnt = 1;
        }
        else if(a[0][idx[0]] < a[1][idx[1]])
        {
            if(lastTaken != 0)
                cnt = 0;

            lastTaken = 0;
            cout << a[lastTaken][idx[lastTaken]];

            idx[lastTaken]++;
            cnt++;
        }
        else
        {
            if(lastTaken != 1)
                cnt = 0;

            lastTaken = 1;
            cout << a[lastTaken][idx[lastTaken]];

            idx[lastTaken]++;
            cnt++;
        }
    }

    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
