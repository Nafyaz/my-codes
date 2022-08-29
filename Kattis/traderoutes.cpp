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

vector<pLL> dfs(LL cur, LL routes)
{
    vector<pLL> ret, temp;

    if(routes == 0)
        return ret;

    ret.push_back({v[cur], cur});

    for(auto nxt : adj[cur])
    {
        temp = dfs(nxt, min(routes, b[nxt]));

        if(temp.size() > ret.size())
            swap(temp, ret);

        while(!temp.empty())
        {
            ret.push_back(temp.back());
            temp.pop_back();
        }
    }

    sort(ret.begin(), ret.end(), greater<pLL>());

    while(ret.size() > routes)
        ret.pop_back();

    return ret;
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

    vector<pLL> ans = dfs(1, b[1]);

    total = 0;
    set<LL> st;
    for(i = 0; i < ans.size(); i++)
    {
        total += ans[i].ff;
        st.insert(ans[i].ss);
    }

    cout << total << "\n" << st.size() << " ";
    for(auto u : st)
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

