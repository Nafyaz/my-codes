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

int arr[102];

void solve(int caseno)
{
    int n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 1)
    {
        cout << "Cook\n";
        return;
    }

    if(n == 2)
    {
        cout << (arr[0]%2 == 0? "Cook\n" : "Chef\n");
        return;
    }

    if(accumulate(arr, arr+n-2, 0) == 0 && arr[n-2]%2 == 0)
    {
        cout << "Cook\n";
        return;
    }

    cout << "Chef\n";
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

