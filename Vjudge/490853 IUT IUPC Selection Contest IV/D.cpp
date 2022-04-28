#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

class mirror
{
    bool type;
    ll x, y;
    ll L, R, U, D;
};

mirror m[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, q, i, x, y;
    string type;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        cin >> m[i].x >> m[i].y >> type;

        m[i].type = (type == "A");
    }

    for(i = 0; i < n; i++)
    {

    }
}
