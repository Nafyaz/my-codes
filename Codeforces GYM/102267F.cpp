#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define PI acos(-1)
#define EPS 0.000000001

ll n;
pair<double, double> position[3003];
double a[3003], r[3003];

vector<ll> adj[3003];
stack<ll> stk;
ll color[3003];

bool isInView(ll i, ll j)
{
    double m;
    double dx = position[j].ff - position[i].ff;
    double dy = position[j].ss - position[i].ss;

    if(dx == 0)
    {
        if(dy > 0)
            m = PI/2;
        else
            m = 3*PI/2;
    }

    else if(dx > 0)
    {
        if(dy >= 0)
            m = atan(abs(dy/dx));
        else
            m = 2*PI - atan(abs(dy/dx));
    }

    else
    {
        if(dy >= 0)
            m = PI - atan(abs(dy/dx));
        else
            m = PI + atan(abs(dy/dx));
    }

    double diff = abs(m - a[i]);
    if(diff + EPS >= PI)
        diff = 2*PI - diff;

    // cout << dx << " " << dy << " " << m << " " << diff << "\n";

    return diff <= r[i] + EPS;
}

bool dfs(ll node)
{
    ll ret = 1;
    color[node] = 1;

    for(auto u : adj[node])
    {
        if(color[u] == 0)
            ret = ret & dfs(u);
        else if(color[u] == 1)
            return 0;
    }

    stk.push(node+1);
    color[node] = 2;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j;

    cin >> n;
    for(i = 0; i < n; i++)    
    {
        cin >> position[i].ff >> position[i].ss >> a[i] >> r[i];
        a[i] = a[i] * PI / 180;
        r[i] = r[i] * PI / 180;

        // cout << i << ": " << a[i] << " " << r[i] << "\n";
    }

    // cout << isInView(0, 2);
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i != j && isInView(i, j))
                adj[i].push_back(j);
            // cout << inView[i][j] << " ";
        }
        // cout << "\n";
    }

    for(i = 0; i < n; i++)
    {
        if(color[i] == 0 && dfs(i) == 0)
        {
            cout << "-1";
            return 0;
        }
    }

    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}