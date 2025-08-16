#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
ll Log[200005];
ll sparseMin[200005][20];
ll sparseMax[200005][20];

ll findMin(ll i, ll j)
{
    ll len = j-i+1;
    ll h = Log[len];

    return min(sparseMin[i][h], sparseMin[j - (1LL << h) + 1][h]);
}

ll findMax(ll i, ll j)
{
    ll len = j-i+1;
    ll h = Log[len];

    return max(sparseMax[i][h], sparseMax[j - (1LL << h) + 1][h]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, y, i, j, st, ed, cnt1, cnt2, ans, mn, mx;

    for(i = 2; i < 200005; i++)
        Log[i] = Log[i/2] + 1;

    cin >> n >> x >> y;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        sparseMin[i][0] = a[i];
        sparseMax[i][0] = a[i];
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1LL << j) - 1 < n; i++)
        {
            sparseMin[i][j] = min(sparseMin[i][j-1], sparseMin[i + (1LL << (j-1))][j-1]);
            sparseMax[i][j] = max(sparseMax[i][j-1], sparseMax[i + (1LL << (j-1))][j-1]);
        }
    }

//    for(i = 0; i <= 32; i++)
//        cout << i << ": " << Log[i] << "\n";
//    cout << "\n";
//    for(i = 0; i < 4; i++)
//    {
//        for(j = 0; j < 3; j++)
//            cout << sparseMax[i][j] << " ";
//        cout << "\n";
//    }
//    cout << "\n";

    ans = 0;
    st = ed = -1;
    for(i = 0; i <= n; i++)
    {
        if(i < n && y <= a[i] && a[i] <= x)
        {
            if(st == -1)
                st = i;

            ed = i;
        }
        else
        {
            cout << "st:\n";
            for(j = 0; st+j <= ed && findMin(st+j, ed) == y && findMax(st+j, ed) == x; j++)
            {
                cnt1 = j+1;
                cout << j << " " << findMin(st+j, ed) << " " << findMax(st+j, ed) << "\n";
            }
            cout << "\n";

            cout << "ed:\n";
            for(j = 0; ed-j >= st && findMin(st, ed-j) == y && findMax(st, ed-j) == x; j++)
            {
                cnt2 = j+1;
                cout << j << " " << findMin(st, ed-j) << " " << findMax(st, ed-j) << "\n";
            }
            cout << "\n";

//            cout << "st: " << st << "; ed: " << ed << "\n";
//            cout << cnt1 << " " << cnt2 << "\n";
            ans += cnt1*cnt2;

            st = ed = -1;
        }
    }

    cout << ans;
}
