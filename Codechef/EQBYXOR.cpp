#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll a, b, n, Xor;

    cin >> a >> b >> n;

    Xor = a^b;

    if(a == b)    
        cout << "0\n";
    else if((Xor) < n)
        cout << "1\n";
    else if(__builtin_clz(Xor) < __builtin_clz(n))
        cout << "-1\n";
    else if((n&(n-1)) == 0) 
        cout << "-1\n";
    else
        cout << "2\n";
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