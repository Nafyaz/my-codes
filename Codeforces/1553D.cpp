#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

string s, t;

void solve(int caseno)
{
    int i, j, m, n;

    cin >> s >> t;
    m = s.size();
    n = t.size();

    for(j = n-1, i = m-1; j >= 0; j--, i--)
    {
        while(i >= 0 && s[i] != t[j])
            i -= 2;

        if(i < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
