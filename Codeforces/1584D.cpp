#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    ll n, i, low, high, mid, x;

    cin >> n;

    low = 1;
    high = n;
    while(low <= high)
    {
        if(low == high)
        {
            i = low;
            break;
        }

        mid = (low + high) / 2;

        cout << "? " << low << " " << mid << "\n";
        cin >> x;

        assert(x != -1);

        if(x == 0)
            low = mid + 1;
        else
            high = mid;
    }

    low = 1;
    high = n;
    
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