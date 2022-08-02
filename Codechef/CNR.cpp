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

const int sz = 111;
int nCr[355][355][sz];
int m[sz];

bool isGE(int a[], int b[])     // a >= b ?
{
    int i;

    for(i = sz-1; i >= 0; i--)
    {
        if(a[i] > b[i])
            return 1;
        if(a[i] < b[i])
            return 0;
    }

    return 1;
}

void subtract(int a[])      // m -= a
{
    int i;

    for(i = 0; i < sz; i++)
    {
        m[i] -= a[i];

        if(m[i] < 0)
        {
            m[i] += 10;
            a[i+1]++;
        }
    }
}

void calc(int n, int k)
{
    if(n == 0)
    {
        cout << "\n";
        return;
    }

    if(k == 0)
    {
        while(n--)
            cout << "0";
        cout << "\n";
        return;
    }

    int i;
    if(isGE(nCr[n-1][k], m))
    {
        cout << "0";
        calc(n-1, k);
    }
    else
    {
        cout << "1";
        subtract(nCr[n-1][k]);
        calc(n-1, k-1);
    }
}

void solve(int caseno)
{    
    int n, k, i;
    string s;

    cin >> n >> k >> s;

    reverse(s.begin(), s.end());

    for(i = 0; i < s.size(); i++)
        m[i] = s[i] - '0';

    if(!isGE(nCr[n][k], m))
        cout << "-1\n";
    else
        calc(n, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0, i, j, k;

    nCr[0][0][0] = 1;
    for(i = 1; i < 355; i++)
    {
        for(j = 0; j <= i; j++)
        {
            for(k = 0; k < sz; k++)
            {
                nCr[i][j][k] += nCr[i-1][j][k];

                if(j)
                    nCr[i][j][k] += nCr[i-1][j-1][k];

                if(nCr[i][j][k] >= 10)
                {
                    nCr[i][j][k] -= 10;
                    nCr[i][j][k+1] ++;
                }
            }
        }
    }

    // for(i = 0; i <= 6; i++)
    // {
    //     for(j = 0; j <= i; j++)
    //     {
    //         show(i);
    //         show(j);

    //         cout << nCr[i][j][1] << nCr[i][j][0] << "\n";
    //     }
    // }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}