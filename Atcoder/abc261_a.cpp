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
    int L1, R1, L2, R2, l, r;

    cin >> L1 >> R1 >> L2 >> R2;

    R1--;
    R2--;

    l = max(L1, L2);
    r = min(R1, R2);

    cout << max(0, r-l+1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
