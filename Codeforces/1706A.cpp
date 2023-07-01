#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, m, i, a, mn, mx;

    cin >> n >> m;
    string s(m, 'B');

    for(i = 0; i < n; i++)
    {
        cin >> a;

        mn = min(a-1, m-a);
        mx = max(a-1, m-a);

        if(s[mn] == 'B')
            s[mn] = 'A';
        else
            s[mx] = 'A';
    }

    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
