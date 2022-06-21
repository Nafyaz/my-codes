#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll ans[maxN];
bool taken[maxN]; 

void solve(ll caseno)
{
    ll n, i, val, bit;

    cin >> n;

    if(n == 1)
    {
        cout << "1\n1\n";
        return;
    }

    if(n % 2)
    {
        cout << "-1\n";
        return;
    }

    fill(taken+1, taken+n+1, 0);

    for(i = n; i >= 1; i--)
    {
        val = 0;
        
        for(bit = 1; bit <= i; bit *= 2)
        {
            if((i&bit) == 0)
                val += bit;
        }

        // show(i);
        // show(val);
        // cout << "\n";

        if(!taken[val] && !taken[i])
        {
            ans[i] = val;
            ans[val] = i;

            taken[i] = taken[val] = 1;
        }
    }

    for(i = 1; i <= n; i++)
        cout << i << " ";
    cout << "\n";
    
    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
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