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
    ll n, i, a, b, ans = 0;

    cin >> n;

    for(i = 1; i*i <= n; i++)
    {
        if((n-i)%i == 0)
        {
            a = i;
            b = n - a;
            if(a < b)
                ans += 2;
            else if(a == b)
                ans ++;
            
            if(i == n/i)
                continue;

            a = n/i;
            b = n - a;
            if(a < b)
                ans += 2;
            else if(a == b)
                ans ++;
        }
    }

    cout << ans << "\n";
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