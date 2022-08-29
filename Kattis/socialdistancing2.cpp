#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

int arr[1003];

void solve(int caseno)
{
    int s, n, i, seat, ans;

    cin >> s >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ans = 0;
    for(i = 1; i < n; i++)
    {
        seat = arr[i] - arr[i-1] - 1;
        ans += (seat-1)/2;
    }

    seat = s-arr[n-1]+arr[0]-1;
    ans += (seat-1)/2;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
