#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n = 5, parent[100];

ll Find(ll a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);

    if(a == b)
        return;

    parent[max(a,b)] = min(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, i;

    for(i = 1; i <= n; i++)
        parent[i] = i;

    cout << n << "\n";
    for(i = 0; i < 100; i++)
    {
        a = rand()%5 + 1;
        b = rand()%5 + 1;

        if(Find(a) != Find(b))
        {
            cout << a << " " << b << "\n";
            Union(a, b);
        }
    }
}