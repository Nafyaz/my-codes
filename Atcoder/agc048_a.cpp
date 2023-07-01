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
    LL i;
    string s, t = "atcoder";

    cin >> s;

    if(t < s)
    {
        cout << "0\n";
        return;
    }

    for(i = 1; i < s.size(); i++)
    {
        if(s[i] != 'a')
        {
            if(s[i] <= 't')
                cout << i << "\n";
            else
                cout << i-1 << "\n";

            return;
        }
    }

    cout << "-1\n";
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