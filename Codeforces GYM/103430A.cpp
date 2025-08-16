#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

set<pair<ll, ll>> st;
map<pair<ll, ll>, ll> depth;
ll n, m;

ll getPower(ll a, ll b)
{
    if(st.find({a, b}) != st.end())
        return a+b+1;
    else
        return a+b;
}

ll bfs()
{    
    ll a, b, d, power, mxPower;
    queue<pair<ll, ll>> Q, Qtemp;

    Q.push({1, 1});
    depth[{1, 1}] = d = 0;

    while(++d)
    {
        mxPower = 0;
        while(!Q.empty())
        {
            a = Q.front().ff;
            b = Q.front().ss;
            Qtemp.push(Q.front());
            Q.pop();

            // cout << d << "; " << a << " " << b << "\n";

            if(a == n && b == m)
                return depth[{a, b}];

            power = getPower(a, b);
            mxPower = max(mxPower, power);
        }

        while(!Qtemp.empty())
        {
            a = Qtemp.front().ff;
            b = Qtemp.front().ss;
            Qtemp.pop();

            power = getPower(a, b);
            if(power + 1 >= mxPower)
            {
                Q.push({a, min(m, power)});
                Q.push({min(n, power), b});
                
                depth[{a, min(m, power)}] = d;
                depth[{min(n, power), b}] = d;
            }
        }

        // cout << "mxPower: " << mxPower << "\n";

    }

    return -1;
}

void solve()
{
    ll q, i, a, b, ans = 0, power;

    cin >> n >> m;

    st.clear();
    depth.clear();

    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        st.insert({a, b});
    }

    cout << bfs() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}