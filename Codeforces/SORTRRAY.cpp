#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

ll diff[maxN];

void solve(ll caseno)
{
    ll n, i, arr, bit;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> arr;
        diff[i] = maxN + i - arr;
    }

    ll Q = 0;
    queue<ll> q[20];

    for(bit = 0; bit < 20; bit ++)
    {
        for(i = 1; i <= n; i++)
        {
            if((diff[i] & (1LL << bit)) != 0)
                q[bit].push(i);
        }

        if(!q[bit].empty())
            Q++;
    }

    cout << Q << "\n";
    for(bit = 0; bit < 20; bit++)
    {
        if(!q[bit].empty())
        {
            cout << q[bit].size() << " " << (1LL << bit) << "\n";

            while(!q[bit].empty())
            {
                cout << q[bit].front() << " ";
                q[bit].pop();
            }

            cout << "\n";
        }
    }
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