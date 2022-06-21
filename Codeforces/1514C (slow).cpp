#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll n;
vector<ll> v;
bool vis[100][100];

void call(ll pos, ll rem)
{
    if(rem == 1 && v.size() > 1)
    {
        cout << n << ":\n";
        for(auto u : v)
            cout << u << " ";
        cout << "\n";
    }

    if(pos == n+1)
        return;

    call(pos+1, rem);
    v.push_back(pos);
    call(pos+1, (rem*pos)%n);
    v.pop_back();
}

void solve(ll caseno)
{
    ll i;

    cin >> n;

    v.clear();
    v.push_back(1);
    call(2, 1);
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