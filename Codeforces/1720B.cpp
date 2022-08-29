#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 200005;

int arr[MAXN];

void solve(int caseno)
{
    int n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    cout << arr[n-1] + arr[n-2] - arr[0] - arr[1] << "\n";
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

