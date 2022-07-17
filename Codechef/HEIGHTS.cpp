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
    int n, i, h, one, two, mx;
    map<int, int> freq;

    cin >> n;

    mx = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> h;
        freq[h]++;
        mx = max(mx, h);
    }

    one = two = 0;
    for(auto u : freq)
    {
        if(u.ss == 1)
            one++;
        else if(u.ss == 2)
            two += 2;
    }

    if(one == 1 && freq[mx] == 1 && two == n-1)
        cout << "2\n";
    else
        cout << (one + 1) / 2 << "\n";
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