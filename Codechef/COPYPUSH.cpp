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
    int n, i, j, half;
    bool flag = 1;
    string s;

    cin >> n >> s;

    for(i = n-1; i >= 0; i--)
    {
        if(i&1)
        {
            half = (i+1)/2;
            for(j = i; j > i-half; j--)
            {
                if(s[j-half] != s[j])
                {
                    cout << "NO\n";
                    return;
                }
            }

            i = j+1;
        }
    }

    cout << "YES\n";
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

/*
1
14
ddjddjddjddjdd
*/