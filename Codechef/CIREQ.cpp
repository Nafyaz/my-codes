#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

int arr[MAXN];

void solve(int caseno)
{
    int n, i, pos, ans;

    cin >> n;
    vector<int> v(n, 1);

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr+1, arr+n+1);

    for(i = 1; i <= n; i++)
    {
        pos = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
        v[pos-1]++;
    }

    ans = 0;
    for(i = n-1; i >= 0; i--)
    {
        if(v[i] != 1)
            ans++;
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

/*
1
4
1 1 2 2
*/
