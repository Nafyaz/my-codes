#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN];

void solve(ll caseno)
{
    ll n, i, sum = 0, moves;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum != 0 || arr[n-1] > 0)
    {
        cout << "No\n";
        return;
    }

    moves = abs(arr[n-1]);
    for(i = n-2; i > 0; i--)
    {
        moves = moves - arr[i];

        if(moves < 0 || (moves == 0 && arr[i] != 0))
        {
            cout << "No\n";
            return;
        }

        // show(i);
        // show(moves);
        // cout << "\n";
    }

    cout << "Yes\n";
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