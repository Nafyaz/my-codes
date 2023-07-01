#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

LL m;
vector<vector<LL>> adj, adj_t;
vector<bool> used;
vector<LL> order, comp;
vector<bool> assignment;

void dfs1(LL v)
{
    used[v] = true;
    for(auto u : adj[v])
    {
        if(!used[u])
            dfs1(u);
    }

    order.push_back(v);
}

void dfs2(LL v, LL c1)
{
    comp[v] = c1;
    for(LL u : adj_t[v])
    {
        if(comp[u] == -1)
            dfs2(u, c1);
    }
}

bool solve_2SAT()
{
    order.clear();
    used.assign(2*m+2, false);
    for(LL i = 2; i <= 2*m+1; i++)
    {
        if(!used[i])
            dfs1(i);
    }

    // for(auto u : order)
    //     cout << u << " ";
    // cout << "\n";

    comp.assign(2*m+2, -1);
    for(LL i = 2*m-1, j = 1; i >= 0; i--)
    {
        LL v = order[i];
        if(comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(m+1, false);
    for(LL i = 2; i <= 2*m+1; i += 2)
    {
        if(comp[i] == comp[i+1])
            return false;
        assignment[i/2] = comp[i] > comp[i+1];
    }

    return true;
}

void add_disjunction(LL a, bool na, LL b, bool nb) 
{
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    LL neg_a = a ^ 1;
    LL neg_b = b ^ 1;

    // show(a);
    // show(neg_a);
    // show(b);
    // show(neg_b) << "\n";

    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n;

    cin >> n >> m;

    adj.resize(2*m+2);
    adj_t.resize(2*m+2);

    for(LL i = 1; i <= n; i++)
    {
        char likeA, likeB;
        LL valA, valB;
        cin >> likeA >> valA >> likeB >> valB;

        // cout << likeA << "; " << valA << "; " << likeB << "; " << valB << "\n";

        add_disjunction(valA, (likeA == '-'), valB, (likeB == '-'));
    }

    // return 0;

    if(!solve_2SAT())
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(LL i = 1; i <= m; i++)
        cout << (assignment[i]? "+ " : "- ");
}