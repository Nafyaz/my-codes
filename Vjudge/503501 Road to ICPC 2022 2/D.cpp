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
    int n, m, q, i, x, cnt;
    string s;
    bool flag;
    bool isIn[10004];

    cin >> n >> m >> q;

    memset(isIn, 0, sizeof isIn);

    flag = 1;
    cnt = 0;
    for(i = 0; i < q; i++)
    {
        cin >> s >> x;

        if(!flag)
            continue;

        // show(s);
        // show(x);
        // show(isIn[x]);
        // show(cnt);

        if(s == "+")
        {
            if(isIn[x] || cnt >= m)
                flag = 0;

            cnt++;
            isIn[x] = 1;
        }

        else
        {
            if(!isIn[x])
                flag = 0;

            cnt--;
            isIn[x] = 0;
        }

        // show(flag);
        // cout << "\n";
    }

    cout << (flag? "Consistent\n" : "Inconsistent\n");
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