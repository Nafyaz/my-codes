#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 100005

pii arr[MAXN];

bool cmp(pii x, pii y)
{
    if(x.ff != y.ff)
        return x.ff < y.ff;
    return x.ss > y.ss;
}

bool isPossible(int ones, int q)
{
    int i;
    vector<pii> v;

    for(i = 0; i < ones; i++)
        v.push_back({arr[i].ss, arr[i].ff});

    sort(v.begin(), v.end());

    for(i = 0; i < ones; i++)
    {
        if(v[i].ss > q)
        {
            if(q == 0)
                return 0;
            q--;
        }
    }

    return 1;
}

void solve()
{
    int n, q, i, low, high, mid, ones;
    string ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i].ff;
        arr[i].ss = i;
    }

    if(q >= n)
    {
        cout << string(n, '1') << "\n";
        return;
    }

    sort(arr, arr + n, cmp);

    ones = 0;
    low = 1;
    high = n;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(isPossible(mid, q))
        {
            ones = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    ans = string(n, '0');

    for(i = 0; i < ones; i++)
        ans[arr[i].ss] = '1';

    cout << ans << "\n";
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
/*
2
5 2
2 3 2 3 1
5 3
5 3 4 6 7
*/
