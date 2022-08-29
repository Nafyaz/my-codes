#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 102

int LCS[MAXN][MAXN], LCSRev[MAXN][MAXN], temp[MAXN][MAXN];
int cEndInA[MAXN], cEndInB[MAXN];

int getC(string s, int idx, string c)
{
    int i;
    for(i = 0; i < c.size(); i++)
    {
        while(idx < s.size() && s[idx] != c[i])
            idx++;
        if(idx == s.size())
            return -1;
        idx++;
    }

    return idx;
}

void getLCS(string a, string b)
{
    int i, j, n, m;

    n = a.size();
    m = b.size();

    for(i = 0; i <= n; i++)
        LCS[i][0] = 0;
    for(i = 0; i <= m; i++)
        LCS[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
}

void getLCSRev(string a, string b)
{
    int i, j, n, m;

    n = a.size();
    m = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(i = 0; i <= n; i++)
        temp[i][0] = 0;
    for(i = 0; i <= m; i++)
        temp[0][i] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
                temp[i][j] = temp[i-1][j-1] + 1;
            else
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
        }
    }

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
            LCSRev[i][j] = temp[n-i][m-j];
    }
}

void solve(int caseno)
{
    string a, b, c;
    int i, j, k, n, m, ans, left, right;

    cin >> a >> b >> c;

    n = a.size();
    m = b.size();
    getLCS(a, b);
    getLCSRev(a, b);

    // for(i = 0; i <= 2; i++)
    // {
    //     for(j = 0; j <= 2; j++)
    //         cout << LCS[i][j] << " ";
    //     cout << "\n";
    // }

    memset(cEndInA, -1, sizeof cEndInA);
    memset(cEndInB, -1, sizeof cEndInB);

    for(i = 0; i < a.size(); i++)
        cEndInA[i] = getC(a, i, c);
    for(i = 0; i < b.size(); i++)
        cEndInB[i] = getC(b, i, c);

    // for(i = 0; i < a.size(); i++)
    //     cout << cEndInB[i] << " ";
    // cout << "\n";

    ans = 0;
    for(i = 0; i < a.size(); i++)
    {
        for(j = 0; j < b.size(); j++)
        {
            if(cEndInA[i] == -1 || cEndInB[j] == -1)
                continue;

            left = LCS[i][j];
            right = LCSRev[cEndInA[i]][cEndInB[j]];

            // show(i);
            // show(j);
            // show(left);
            // show(right);
            // cout << "\n";

            ans = max(ans, int(left + c.size() + right));
        }
    }

    cout << "Case " << caseno << ": " << ans << "\n";
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