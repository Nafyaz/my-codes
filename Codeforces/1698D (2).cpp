#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 10004

void solve(ll caseno)
{
    ll n, i, x, low, high, mid, correct, ans;

    cin >> n;

    low = 1;
    high = n;
    while(low <= high)
    {
        if(low == high)
        {
            ans = low;
            break;
        }

        mid = (low + high) / 2;

        cout << "? " << low << " " << mid << "\n";
        correct = 0;
        for(i = 1; i <= mid-low+1; i++)
        {
            cin >> x;
            if(low <= x && x <= mid)
                correct ++;
        }

        if(correct % 2 == 0)
            low = mid + 1;
        else
            high = mid;
    }

    cout << "! " << ans << "\n";
}

int main()
{
    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}