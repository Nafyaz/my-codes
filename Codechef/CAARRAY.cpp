#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 5003

ll arr[maxN];

ll getLCM(ll x, ll y)
{
    return x/__gcd(x, y)*y;
}

void solve(ll caseno)
{
    ll n, i, j, lcm;
    bool flag;

    cin >> n;

    for(i = 0; i+1 < n; i++)
    {
        if(i%2 == 1)
            arr[i] = i+2;
        else
            arr[i] = getLCM(i+1, i+2);
    }

    lcm = 1;
    for(i = 0; i+1 < n; i++)
    {
        flag = 0;
        for(j = i+1; j+1 < n; j++)
        {
            if(__gcd(arr[i], arr[j]) == arr[i])
            {
                flag = 1;
                break;
            }
        }

        if(!flag)
            lcm = lcm/__gcd(lcm, arr[i])*arr[i];
    }

    arr[n-1] = lcm;

    cout << lcm << "\n";

    // for(i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << "\n";
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