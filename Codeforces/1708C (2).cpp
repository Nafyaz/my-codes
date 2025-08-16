#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 100005

int n;
int arr[MAXN];

void solve()
{
    int q, i, j, low, high, mid, ones;
    string ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    if(q >= n)
    {
        cout << string(n, '1') << "\n";
        return;
    }

    ans = string(n, '0');
    for(i = n-1, j = 0; i >= 0; i--)
    {
        if(arr[i] <= j)
            ans[i] = '1';
        else if(q > j)
        {
            ans[i] = '1';
            j++;
        }
    }

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

