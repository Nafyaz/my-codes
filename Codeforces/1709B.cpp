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

ll arr[MAXN];
ll pref[MAXN], suff[MAXN];

void solve(ll caseno)
{
    ll n, m, i, j;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];

        if(i > 1)
            pref[i] = pref[i-1] + (arr[i-1] > arr[i]? arr[i-1]-arr[i] : 0);
        else
            pref[i] = 0;
    }

    for(i = n; i >= 1; i--)
    {
        if(i < n)
            suff[i] = suff[i+1] + (arr[i+1] > arr[i]? arr[i+1]-arr[i] : 0);
        else
            suff[i] = 0;
    }

    while(m--)
    {
        cin >> i >> j;

        if(i < j)
            cout << pref[j] - pref[i] << "\n";
        else
            cout << suff[j] - suff[i] << "\n";
    }
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


