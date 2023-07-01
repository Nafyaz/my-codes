#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 300005;

vector<LL> adj[MAXN];
LL b[MAXN], v[MAXN];

set<pLL> dfs(LL cur, LL routes)
{
    set<pLL> st, temp;

    if(routes == 0)
        return st;

    st.insert({v[cur], cur});

    for(auto nxt : adj[cur])
    {
        temp = dfs(nxt, min(routes, b[nxt]));

        if(temp.size() > st.size())
            swap(temp, st);

        for(auto u : temp)
        {
            st.insert(u);
            if(st.size() > routes)
                st.erase(st.begin());
        }
    }

    return st;
}

void solve(int caseno)
{
    LL n, i, p, total;

    cin >> n;

    for(i = 2; i <= n; i++)
    {
        cin >> p;
        adj[p].push_back(i);
    }

    for(i = 1; i <= n; i++)
        cin >> b[i];

    for(i = 1; i <= n; i++)
        cin >> v[i];

    set<pLL> st = dfs(1, b[1]);
    set<LL> ans;

    total = 0;
    for(auto u : st)
    {
        total += u.ff;
        ans.insert(u.ss);
    }

    cout << total << "\n" << ans.size() << " ";
    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

