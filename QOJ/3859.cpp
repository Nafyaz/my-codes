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
    int beauty[102] = {0};
    int n, i, b, d, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> b >> d;

        beauty[d] = max(beauty[d], b);
    }

    ans = 0;
    for(i = 1; i <= 10; i++)
    {
        if(beauty[i] != 0)
            ans += beauty[i];
        else
        {
            cout << "MOREPROBLEMS\n";
            return;
        }
    }

    cout << ans << "\n";
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
