#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define DBG         pf("Hi\n")
#define pf          printf
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define PI          acos(-1.00)
#define sz          size()
#define xx          first
#define yy          second
#define eps         1e-9

typedef long long int LL;
typedef double db;

/* Min Priority queue
   priority_queue<int, vector<int>, greater <int> > q;
*/

//int dx[] = {+0,+1,+0,-1};
//int dy[] = {+1,+0,-1,+0};
//int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
//int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
//bool check(int n, int pos) {return (bool) (n & (1<<pos));}
//int on(int n, int pos) {return n | (1<<pos); }
//int off(int n, int pos) {return n & ~(1<<pos); }
#define MAX     100000
vector<int> E[MAX+10], V;
bool vis[MAX+10], adj[MAX+10];

void dfs(int nd)
{
    vis[nd] = 1;
    V.pb(nd);
    for(int i = 0; i<E[nd].sz; i++)
    {
        if(!vis[E[nd][i]])
            return dfs(E[nd][i]);
    }
    for(int i = 0; i<E[nd].sz; i++)
            adj[E[nd][i]] = 1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k, cs, t, n, m;
    sfff(n,m,k);
    FRE(i,1,m)
    {
        sff(j,k);
        E[j].pb(k);
        E[k].pb(j);
    }
    dfs(1);
    for(i = 0; ; i++)
    {
        if(adj[V[i]] == 1)
        {
            pf("%d\n",V.sz - i);
            pf("%d",V[i]);
            for(i++; i<V.sz; i++)
                pf(" %d",V[i]);
            break;
        }
    }
    return 0;
}

