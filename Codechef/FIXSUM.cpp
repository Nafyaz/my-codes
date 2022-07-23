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

void solve(int caseno)
{
     ll n, s, low, high, mid, ans, sum, last;

     cin >> n >> s;

//     mid = 3;
//     last = ((1LL << (64 - __builtin_clzll(mid))) - 1) ^ mid;

//     show(mid);
//     show(last);
//     cout << "\n";
//     return;

     low = 0;
     high = s;
     while(low <= high)
     {
         mid = (low + high) / 2;

         last = ((1LL << (64 - __builtin_clzll(mid))) - 1) ^ mid;
         sum = (n-1)*mid + last;

//         show(low);
//         show(high);
//         show(mid);
//         show(last);
//         show(sum);
//         cout << "\n";

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
2 7
*/
