#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 5003

void solve(ll caseno)
{
    ll n, i, j, lcm;
    bool flag;

    cin >> n;

    for(i = n; i >= 4; i -= 4)    
        cout << (i-3)*i << " " << (i-3)*(i-1) << " " << (i-2)*(i-1) << " " << (i-2)*i << " ";
    
    if(i == 3)
        cout << "2 3 6";
    else if(i == 2)
        cout << "1 2";
    else if(i == 1)
        cout << "1";

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