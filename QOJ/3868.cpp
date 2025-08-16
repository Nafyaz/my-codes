#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

set<int> st;

void getDivisors(int x)
{
    int i;
    for(i = 1; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            st.insert(i);
            st.insert(x/i);
        }
    }
}

void solve(int caseno)
{
    int w, l, g;
    st.clear();

    cin >> w >> l;

    g = __gcd(w-1, l-1);
    getDivisors(g);

    g = __gcd(w, l-2);
    getDivisors(g);

    g = __gcd(w-2, l);
    getDivisors(g);

    g = __gcd(__gcd(w-2, w), l-1);
    getDivisors(g);

    g = __gcd(__gcd(l-2, l), w-1);
    getDivisors(g);

    cout << st.size() << " ";
    for(auto u : st)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}