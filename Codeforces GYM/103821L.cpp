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

void solve(int caseno)
{
    int n, k, i, j, arr, lastParity, ans;
    priority_queue<int> pq[2];

    cin >> n >> k;

    ans = 0;
    lastParity = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> arr;

        if(lastParity != -1 && lastParity != arr%2)
        {
            for(j = 1; j <= k && !pq[lastParity].empty(); j++)
            {
                ans += pq[lastParity].top();
                pq[lastParity].pop();
            }

            while(!pq[lastParity].empty())
                pq[lastParity].pop();
        }

        pq[arr%2].push(arr);
        lastParity = arr%2;
    }

    for(j = 1; j <= k && !pq[lastParity].empty(); j++)
    {
        ans += pq[lastParity].top();
        pq[lastParity].pop();
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
