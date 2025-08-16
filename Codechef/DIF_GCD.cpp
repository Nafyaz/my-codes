#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, m, a, b, diff, ansA, ansB;

    cin >> n >> m;

    diff = -1;
    for(a = n; a <= 2*n && a <= m; a++)
    {
        b = m/a*a;

        if(b - a > diff)
        {
            diff = b - a;
            ansA = a;
            ansB = b;
        }
    }

    cout << ansA << " " << ansB << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}