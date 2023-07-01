#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;


bool check(string g, string f, string s)
{
    int i, j;
    string f2 = "-----";

    for(i = 0; i < 5; i++)
    {
        if(g[i] == s[i])
        {
            f2[i] = 'G';
            g[i] = '1';
            s[i] = '2';
        }
    }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(g[i] == s[j])
            {
                f2[i] = 'Y';
                g[i] = '1';
                s[j] = '2';
            }
        }
    }

    return (f == f2);
}

void solve(int caseno)
{
    int n, w, cnt, i, j;
    string g[12], f[12];
    string s;

    cin >> n >> w;

    for(i = 0; i < n; i++)
        cin >> g[i] >> f[i];

    for(i = 0; i < w; i++)
    {
        cin >> s;

        cnt = 0;
        for(j = 0; j < n; j++)
            cnt += check(g[j], f[j], s);

//        show(s);
//        show(cnt);
//        cout << "\n";

        if(cnt == n)
            cout << s << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
