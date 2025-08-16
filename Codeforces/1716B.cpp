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
    int n, i;

    cin >> n;

    cout << n << "\n";
    vector<int> v;

    for(i = 1; i <= n; i++)
    {
        v.push_back(i);
        cout << i << " ";
    }
    cout << "\n";

    for(i = 2; i <= n; i++)
    {
        swap(v[i-2], v[i-1]);

        for(auto u : v)
            cout << u << " ";
        cout << "\n";
    }
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