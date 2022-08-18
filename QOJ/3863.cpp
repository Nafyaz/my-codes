#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int i, j;
    bool uB, vB;
    string u, v;
    stack<char> uStk, vStk;

    cin >> u >> v;

    uB = 0;
    for(i = 0; i < u.size(); i++)
    {
        if(u[i] == 'B')
            uB ^= 1;
        else
        {
            if(uStk.empty() || uStk.top() != u[i])
                uStk.push(u[i]);
            else
                uStk.pop();
        }
    }

    vB = 0;
    for(i = 0; i < v.size(); i++)
    {
        if(v[i] == 'B')
            vB ^= 1;
        else
        {
            if(vStk.empty() || vStk.top() != v[i])
                vStk.push(v[i]);
            else
                vStk.pop();
        }
    }

    // show(u);
    // show(v);
    // cout << "\n";

    if(uB != vB || uStk.size() != vStk.size())
    {
        cout << "NO\n";
        return;
    }

    while(!uStk.empty())
    {
        if(uStk.top() != vStk.top())
        {
            cout << "NO\n";
            return;
        }

        uStk.pop();
        vStk.pop();
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}