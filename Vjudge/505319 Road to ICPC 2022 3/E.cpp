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

    if(m < n | (m-n)%2)
    {
        cout << "NO\n";
        return;
    }

    for(i = 0, j = 0; i < n; i++, j++)
    {
        for(; j < m; j += 2)
        {
            if(s[i] == t[j])
                break;
        }

        if(j == m)
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
