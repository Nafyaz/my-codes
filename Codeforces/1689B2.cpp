#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1003

ll p[maxN];

void solve(ll caseno)
{    
    ll n, i, j, secondLast, last;
    set<ll> st;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> p[i];
        st.insert(i);
    }

    if(n == 1)
    {
        cout << "-1\n";
        return;
    }

    for(i = 1; i <= n-2; i++)
    {
        for(auto u : st)
        {
            if(p[i] != u)
            {
                cout << u << " ";
                st.erase(u);
                break;
            }
        }
    }

    secondLast = *st.begin();
    st.erase(secondLast);
    last = *st.begin();
    st.erase(last);

    if(p[n-1] != secondLast && p[n] != last)
        cout << secondLast << " " << last << "\n";
    else
        cout << last << " " << secondLast << "\n";
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