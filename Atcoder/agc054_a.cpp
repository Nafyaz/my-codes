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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i;
    string s;

    cin >> n >> s;

    if(s[0] != s.back())
    {
        cout << "1\n";
        return 0;
    }

    for(i = 1; i+1 < n; i++)
    {
        if(s[0] != s[i] && s[i+1] != s.back())
        {
            cout << "2\n";
            return 0;
        }
    }

    cout << "-1\n";
}