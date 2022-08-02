#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int nCr[360][360] = {-1};

int getnCr(int n, int r)
{
    if(nCr[n][r] != -1)
        return nCr[n][r];

    if(r > n)
        return nCr[n][r] = 0;

    if(2*r > n)
        return nCr[n][r] = getnCr(n, r-1);

    if(r == 0)
        return nCr[n][r] = 1;

    return nCr[n][r] = getnCr(n-1, r-1) + getnCr(n-1, r);
}

pii call(int n, int k, int m)
{
    int pos;

    for(pos = n-k; pos >= 0; pos--)
    {
        if(getnCr(n-1-pos, k-1) <= m)
        {
            m -= getnCr(n-1-pos, k-1);
            if(m == 0)
                return {pos, m};
        }
        else
            return {pos, m};
    }

    return {pos, m};
}

void solve(int caseno)
{
    int n, k, m, pos, i;
    string s;

    cin >> n >> k >> m;

    while(k && m)
    {
        pii temp = call(n, k, m);

        pos = temp.ff;
        m = temp.ss;

        // show(pos);
        // show(m);
        // cout << "\n";

        if(pos == -1)
        {
            cout << "-1\n";
            return;
        }

        for(i = 0; i < pos; i++)
            cout << "0";
        cout << "1";

        n -= pos+1;
        k--;
    }

    if(m == 0)
    {
        for(i = 0; i < n; i++)
        {
            if(i < k)
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if(i < n-k)
                cout << "0";
            else
                cout << "1";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    memset(nCr, -1, sizeof nCr);

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}