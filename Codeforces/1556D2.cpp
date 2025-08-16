#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 10004

ll arr[10004];

void get(ll or12, ll or23, ll or13, ll and12, ll and23, ll and13)
{
    ll sum = (or12+and12 + or23+and23 + or13+and13)/2;
    arr[1] = sum - (or23+and23);
    arr[2] = sum - (or13+and13);
    arr[3] = sum - (or12+and12);
}

ll get(ll x, ll or12, ll and12)
{
    return or12+and12 - x;
}

void solve(ll caseno)
{    
    ll n, k, i;
    ll or12, or23, or13, and12, and23, and13;

    cin >> n >> k;

    cout << "or 1 2\n";  cin >> or12;

    cout << "or 2 3\n";  cin >> or23;

    cout << "or 1 3\n";  cin >> or13;

    cout << "and 1 2\n"; cin >> and12;

    cout << "and 2 3\n"; cin >> and23;

    cout << "and 1 3\n"; cin >> and13;

    get(or12, or23, or13, and12, and23, and13);

    for(i = 4; i <= n; i++)
    {
        cout << "or " << i-1 << " " << i << "\n";  cin >> or12;
        cout << "and " << i-1 << " " << i << "\n"; cin >> and12;

        arr[i] = get(arr[i-1], or12, and12);
    }

    sort(arr+1, arr+n+1);

    cout << "finish " << arr[k] << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}