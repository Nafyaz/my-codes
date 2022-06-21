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
    arr[1] = arr[2] = arr[3] = 0;
    ll bit, or123, and123;

    or123 = or12 | or23;
    and123 = and12 & and23;

    // show(or123);
    // show(and123);
    // cout << "\n";

    for(bit = 1; bit < INT_MAX; bit *= 2)
    {
        if((or123 & bit) == 0)
            continue;
        else if((and123 & bit) != 0)
        {
            arr[1] += bit;
            arr[2] += bit;
            arr[3] += bit;
        }

        else if((or12 & bit) == 0)
            arr[3] += bit;
        else if((or13 & bit) == 0)
            arr[2] += bit;
        else if((or23 & bit) == 0)
            arr[1] += bit;

        else if((and23 & bit) != 0)
        {
            arr[2] += bit;
            arr[3] += bit;
        }
        else if((and13 & bit) != 0)
        {
            arr[1] += bit;
            arr[3] += bit;
        }
        else
        {
            arr[1] += bit;
            arr[2] += bit;
        }
    }
}

ll get(ll x, ll or12, ll and12)
{
    ll bit, ret = 0;

    for(bit = 1; bit < INT_MAX; bit *= 2)
    {
        if((x & bit) == 0)
            ret += (or12 & bit);
        else
            ret += (and12 & bit);
    }

    return ret;
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

    // show(arr[1]);
    // show(arr[2]);
    // show(arr[3]);
    // cout << "\n";

    for(i = 4; i <= n; i++)
    {
        cout << "or " << i-1 << " " << i << "\n";  cin >> or12;
        cout << "and " << i-1 << " " << i << "\n"; cin >> and12;

        arr[i] = get(arr[i-1], or12, and12);
        // show(arr[i]);
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

/*
7 6
7
6
5
0
4
0
6
0
3
2
7
1
5
4
*/