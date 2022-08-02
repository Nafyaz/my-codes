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

bool solve(int& x, int& y, int& z, int xy, int xz, int yz)
{
    if((xy+xz+yz)%2 == 1)
        return 0;

    int xyz = (xy+xz+yz)/2;

    x = xyz - yz;
    y = xyz - xz;
    z = xyz - xy;

    return (x > 0 && y > 0 && z > 0);
}

void solve(int caseno)
{
    int n, d12, d23, d31, x, y, z, i, junction, last;

    cin >> n >> d12 >> d23 >> d31;

//  Case 1
    if(solve(&x, &y, &z, d12, d31, d23))
    {
        if(x+y+z+1 <= n)
        {
            cout << "YES\n";

            cout << "1 4\n";
            last = 4;
            for(i = 2; i <= x; i++)
            {
                cout << last << " " << last+1 << "\n";
                last++;
                junction = last;
            }

            for(i = 1; i < y; i++)
            {
                cout << last << " " << last+1 << "\n";
                last++;
            }
            cout << "2 " << last << "\n";


            cout << junction << " " <<
            for(i = 1; i < z; i++)
            {
                cout << last << " "
            }

            return;
        }
    }
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
