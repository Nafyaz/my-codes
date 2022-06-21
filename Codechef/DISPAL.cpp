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
    ll i, n, x;

    cin >> n >> x;

    if(x > (n+1)/2)
    {
        cout << "-1\n";
        return;
    }

    stack<char> stk;
    for(i = 0; i < n/2; i++)
    {
        cout << (char)('a' + i%x);
        stk.push((char)('a' + i%x));
    }

    if(n%2)
        cout << (char)('a' + x-1);

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

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