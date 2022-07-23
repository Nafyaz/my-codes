#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, i, aSwap, bSwap;
    bool aOne, bOne;
    string a, b;

    cin >> n >> a >> b;

    aSwap = bSwap = 0;
    for(i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
            aSwap++;
        if(b[i] != b[i-1])
            bSwap++;
    }

    if(bSwap == n-1 && a != b)
    {
        cout << "NO\n";
        return;
    }

    aOne = bOne = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] == '1')
            aOne = 1;
        if(b[i] == '1')
            bOne = 1;
    }

    if(!aOne && bOne)
        cout << "NO\n";
    else
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
        solve(caseno);
    }
}

