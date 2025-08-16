#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MAXN 100005

void solve()
{
    int n, i, j, a;
    ll ans = 0;
    int freq[MAXN] = {0};

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        for(j = 0; j <= (a-1)/2; j++)        
            ans += (ll)freq[j] * freq[a-j];

        if(a%2 == 0)
            ans += (ll)freq[a/2]*(freq[a/2] - 1)/2;

        freq[a]++;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}