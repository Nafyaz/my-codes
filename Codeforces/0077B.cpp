#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    LL a, b;

    cin >> a >> b;

    if(b == 0)
    {
        cout << "1\n";
        return;
    }
    else if(a == 0)
    {
        cout << "0.5\n";
        return;
    }

    if(a <= 4*b)
        cout << fixed << setprecision(10) << (a*b + a*a/8.0) / (2.0*a*b) << "\n";
    else
        cout << fixed << setprecision(10) << (a + a - 2*b)*b / (2.0*a*b) << "\n";
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