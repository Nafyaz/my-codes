#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN], brr[MAXN];

void solve(ll caseno)
{
    ll n, i, all = 0;
    ll flag;

    cin >> n;

    for(i = 0; i <= n; i++)
    {
        cin >> brr[i];
        all ^= brr[i];
    }

    if(n%2)
    {
        flag = 0;
        for(i = 0; i <= n; i++)
        {
            if(all != brr[i] || flag)        
                cout << (all ^ brr[i]) << " ";
            else
                flag = 1;
        }

        cout << "\n";
    }
    else
    {
        for(i = 0; i < n; i++)
            cout << (brr[i] ^ brr[n]) << " ";
        cout << "\n";
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