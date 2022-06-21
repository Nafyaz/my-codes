#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, a, i;
    set<ll> st;
    queue<ll> q;

    cin >> n;

    st.insert(0);
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        for(auto u : st)
            q.push(u + a);
        
        while(!q.empty())
        {
            st.insert(q.front());
            q.pop();
        }
    }

    st.erase(0);

    cout << st.size() << "\n";
    for(auto u : st)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}