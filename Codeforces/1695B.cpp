#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[55];

void solve(ll caseno)
{
    ll n, i, mnIdx, mn;

    cin >> n;

    mn = INT_MAX;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];

        if(mn > arr[i])
        {
            mn = arr[i];
            mnIdx = i;
        }
    }

    if(n%2 == 1)
    {
        cout << "Mike\n";
        return;
    }

    if(mnIdx%2)
        cout << "Mike\n";
    else
        cout << "Joe\n";
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