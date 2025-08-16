#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define LL long long
#define pLL pair<LL, LL>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

map<int, int> freq;

void solve(int caseno)
{
    int n, i, a, mx, mx2;

    freq.clear();

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        
        freq[a]++;
    }

    mx = mx2 = -1;
    for(auto u : freq)
    {
        if(mx == -1 || u.ss > mx)
        {
            mx2 = mx;
            mx = u.ss;
        }
        else if(mx2 == -1 || u.ss > mx2)
        {
            mx2 = u.ss;
        }
    }

    cout << max(mx2, (mx+1)/2) << "\n";
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