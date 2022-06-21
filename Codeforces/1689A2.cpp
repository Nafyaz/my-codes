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
    ll n, m, k, i, j, cnt[2];
    string a[2];

    cin >> n >> m >> k;
    cin >> a[0] >> a[1];

    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());

    i = j = cnt[0] = cnt[1] = 0;
    while(i < n && j < m)
    {
        if(cnt[0] == k || (cnt[1] != k && a[0][i] > a[1][j]))
        {
            cout << a[1][j];
            j++;
            cnt[0] = 0;
            cnt[1]++;
        }
        else
        {
            cout << a[0][i];
            i++;
            cnt[0]++;
            cnt[1] = 0;
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
