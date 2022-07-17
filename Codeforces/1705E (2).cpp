#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200025

unsigned ll block = 64, bs[3200];
ll arr[MAXN];

void Add(ll x)
{
    // show(x);

    if(bs[x/block] > (-1ull - (1ull << (x%block))))
    {
        bs[x/block] += (1ull << (x%block));
        Add((x+block-1)/block);
    }
    else
        bs[x/block] += (1ull << (x%block));
}

void Sub(ll x)
{
    if((bs[x/block] < (1ull << (x%block))))
    {
        bs[x/block] = (-1ull - (1ull << (x%block))) + 1 + bs[x/block];
        Sub((x+block-1)/block);
    }
    else
        bs[x/block] -= (1ull << (x%block));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, k, l, i, ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];

        // show(i);

        Add(arr[i]);

        // cout << "\n";
    }

    while(q--)
    {
        cin >> k >> l;

        Sub(arr[k-1]);

        arr[k-1] = l;
        Add(arr[k-1]);

        ans = 0;
        for(i = 3199; i >= 0; i--)
        {
            if(bs[i] & (1ull << (i%block)))
                ans = i;
        }

        cout << ans << "\n";
    }
}