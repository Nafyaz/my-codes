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
    ll i, j, n = rand()%100 + 1, v;
    bool taken[n+1] = {0};

    cout << n << "\n";
    for(i = 1; i <= n; i++)
    {
        // show(i);
        // cout << "\n";
        v = rand() % n + 1;
        if(!taken[v])
        {
            cout << v << " ";
            taken[v] = 1;
        }
        else
        {
            for(j = v%n+1; j != v; j = j%n+1)
            {
                if(!taken[j])
                {
                    cout << j << " ";
                    taken[j] = 1;
                    break;
                }
            }
        }        
    }

    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 50, caseno = 0;

    cout << T << "\n";

    while(T--)
    {
        solve(++caseno);
    }
}