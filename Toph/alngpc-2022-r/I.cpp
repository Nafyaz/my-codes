#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 1000006;

LL P[MAXN], T[MAXN];

void solve(int caseno)
{
    LL n, i, more;

    cin >> n;

    more = 0;
    for(i = 0; i < n; i++)
    {
        cin >> P[i] >> T[i];

        if(P[i] >= T[i])
            more++;
    }

    if(more == 0)
    {
        cout << "NO\n";
        return;
    }

    if(more == n)
    {
        cout << "YES\n";
        return;
    }


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

