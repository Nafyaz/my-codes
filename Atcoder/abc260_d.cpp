#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

map<int, stack<int>> mp;
set<int> st;
int ans[MAXN];

void solve(int caseno)
{
    int n, k, i, p, val;

    cin >> n >> k;

    memset(ans, -1, sizeof ans);
    for(i = 1; i <= n; i++)
    {
        cin >> p;

        if(st.empty() || (*st.rbegin()) < p)
        {
            st.insert(p);
            mp[p].push(p);
        }
        else
        {
            val = *st.lower_bound(p);
            mp[val].push(p);
            swap(mp[val], mp[p]);
            st.erase(val);
            st.insert(p);
        }

        if(mp[p].size() == k)
        {
            while(!mp[p].empty())
            {
                ans[mp[p].top()] = i;
                mp[p].pop();
            }
            st.erase(p);
        }
    }

    for(i = 1; i <= n; i++)
        cout << ans[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}