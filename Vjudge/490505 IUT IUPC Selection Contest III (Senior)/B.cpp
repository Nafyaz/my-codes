#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second

ll pref[100005];
ll birdCnt[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, b, c, d, i, open;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        birdCnt[a]++;
        birdCnt[b+1]--;
    }

    for(i = 1, open = 0; i < 100005; i++)
    {
        open += birdCnt[i];
        pref[i] = pref[i-1] + open;
    }

    for(i = 0; i < m; i++)
    {
        cin >> c >> d;

        cout << pref[d] - pref[c-1] << "\n";
    }
}
