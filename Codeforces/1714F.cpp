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

bool solve(int& x, int& y, int& z, int xy, int yz, int xz)
{
    if((xy+xz+yz)%2 == 1)
        return 0;

    int xyz = (xy+xz+yz)/2;

    x = xyz - yz;
    y = xyz - xz;
    z = xyz - xy;

    if(x < 0 || y < 0 || z < 0)
        return 0;
    if((x|y) == 0 || (y|z) == 0 || (x|z) == 0)
        return 0;

    return 1;
}

void solve(int caseno)
{
    int n, d12, d23, d13, x, y, z, i, junction, prev, nxt;

    cin >> n >> d12 >> d23 >> d13;

    if(!solve(x, y, z, d12, d23, d13))
    {
        cout << "NO\n";
        return;
    }

    if(x&&y&&z)
    {
        if(x+y+z+1 > n)
        {
            cout << "NO\n";
            return;
        }

        junction = 4;
        nxt = 5;
    }

    else
    {
        if(x == 0)
            junction = 1;
        else if(y == 0)
            junction = 2;
        else
            junction = 3;
        nxt = 4;
    }

    // show(x);
    // show(y);
    // show(z);
    // show(junction);
    // show(nxt);
    // cout << "\n";

    cout << "YES\n";
    prev = 1;
    for(i = 1; i < x; i++)        
    {
        cout << prev << " " << nxt << "\n";
        prev = nxt;
        nxt++;
    }
    if(junction != 1)
        cout << prev << " " << junction << "\n";

    prev = 2;
    for(i = 1; i < y; i++)
    {
        cout << prev << " " << nxt << "\n";
        prev = nxt;
        nxt++;
    }
    if(junction != 2)
        cout << prev << " " << junction << "\n";

    prev = 3;
    for(i = 1; i < z; i++)
    {
        cout << prev << " " << nxt << "\n";
        prev = nxt;
        nxt++;
    }
    if(junction != 3)
        cout << prev << " " << junction << "\n";

    for(; nxt <= n; nxt++)
        cout << junction << " " << nxt << "\n";
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