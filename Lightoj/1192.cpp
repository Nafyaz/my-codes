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
    LL k, i, g, w, x;

    cin >> k;

    x = 0;
    for(i = 0; i < k; i++)
    {
        cin >> g >> w;

        x ^= (w-g-1);
    }

    cout << "Case " << caseno << ": " << (x? "Alice\n" : "Bob\n");
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