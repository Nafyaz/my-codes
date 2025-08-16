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
    int i, cntA, cntB;
    string s;

    cin >> s;

    cntA = cntB = 0;
    for(i = 0; i < s.size(); i++)
    {
        cntA += (s[i] == 'a');
        cntB += (s[i] == 'b');
    }

    cout << ((cntA == cntB)? "YES\n" : "NO\n");
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