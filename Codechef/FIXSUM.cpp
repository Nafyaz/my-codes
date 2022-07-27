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

ll getSum(ll n, ll a)
{
    ll bit, ret = 0, aSum = 0;

    for(bit = (1LL << 32); bit > 0; bit /= 2)
    {
        if(n == 1)
        {
            ret += aSum;
            n--;
        }
        else if(n > 1 && (a & bit))
        {
            ret += aSum;
            ret += bit-1;

            aSum += bit;
            n--;
        }
    }

    if(n == 1)
        ret += aSum;
    else
        ret += n*a;

    return ret;
}

void solve(int caseno)
{
     ll n, s, low, high, mid, ans, sum, last;

     cin >> n >> s;

    //  cout << getSum(2, 5) << "\n";

     low = 0;
     high = s;
     while(low <= high)
     {
        mid = (low + high) / 2;
        
        // show(low);
        // show(high);
        // show(mid);
        // cout << "\n";

        sum = getSum(n, mid);

        if(sum >= s)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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
2 136
*/
