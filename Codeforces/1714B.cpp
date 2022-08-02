#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

int arr[MAXN];
set<int> s;

void solve(int caseno)
{
    int n, i;

    cin >> n;

    s.clear();
    for(i = 0; i < n; i++)
        cin >> arr[i];

    for(i = n-1; i >= 0; i--)
    {
        if(s.find(arr[i]) != s.end())
            break;

        s.insert(arr[i]);
    }

    cout << i+1 << "\n";
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
