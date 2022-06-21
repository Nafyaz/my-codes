#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1003

ll n;
ll p[maxN], q[maxN];
bool taken[maxN];

ll call(ll pos)
{
    ll i;

    if(pos > n)
        return 1;

    for(i = 1; i <= n; i++)
    {
        if(taken[i] == 0 && p[pos] != i)
        {
            taken[i] = 1;
            q[pos] = i;

            if(call(pos+1))
                return 1;
            
            q[pos] = 0;
            taken[i] = 0;
        }
    }

    return 0;
}

void solve(ll caseno)
{
    ll i;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        taken[i] = 0;
    }

    if(call(1) == 0)
    {
        cout << "-1\n";
        return;
    }
    
    for(i = 1; i <= n; i++)
        cout << q[i] << " ";
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