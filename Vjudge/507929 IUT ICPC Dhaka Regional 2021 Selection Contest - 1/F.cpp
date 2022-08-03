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
    int n, i, a, bg, hasStarted = 0;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(hasStarted == 0)
        {
            bg = a;
            hasStarted = 1;
        }
        else if(a%bg == 0)
        {
            cout << a << "\n";
            hasStarted = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

