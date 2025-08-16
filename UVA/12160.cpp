#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; ";

void solve(ll L, ll U, ll R, ll caseno)
{
    ll i, v[11];
    for(i = 0; i < R; i++)    
        cin >> v[i]; 

    cout << "Case " << caseno << ": ";

    // show(L);
    // show(U);
    // show(R);
    // cout << "\n";
    
    ll node, newNode;
    queue<ll> q;
    map<ll, ll> dist;
    
    q.push(L);
    dist[L] = 0;

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(i = 0; i < R; i++)
        {
            newNode = (node + v[i])%10000;
            
            // show(newNode);
            // cout << "\n";

            if(newNode == U)
            {
                cout << dist[node] + 1 << "\n";
                return;
            }

            if(dist.find(newNode) == dist.end())
            {
                q.push(newNode);
                dist[newNode] = dist[node] + 1;
            }
        }
    }

    cout << "Permanently Locked\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll L, U, R, caseno = 0;
    while(cin >> L >> U >> R)
    {
        if(!L && !U && !R)
            break;

        solve(L, U, R, ++caseno);
    }
}