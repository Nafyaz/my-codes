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
    int i, n = rand()%10+1;

    cout << n << "\n";

    for(i = 0; i < n; i++)
        cout << rand()%n+1 << " ";
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