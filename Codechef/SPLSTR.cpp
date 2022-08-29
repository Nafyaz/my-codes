#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, k, i, c0, c1;
    string s;

    cin >> n >> k >> s;

    c0 = c1 = 0;
    for(i = 0; i < n; i++)
    {
        c0 += (s[i] == '0');
        c1 += (s[i] == '1');
    }

    cout << (abs(c0 - c1) + k - 1) / k << "\n";
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