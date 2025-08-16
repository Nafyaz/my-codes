#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k, i, ans[30], len, sz;

    ans[0] = 1;
    ans[1] = 2;
    n = 2;
    for(len = 2; n <= 1000000000; len++)
    {
        ans[len] = n+1;
        n = n + len*(1LL << (len-1));
    }
    sz = len;

//    cout << "sz: " << sz << "\n";
//    for(i = 0; i < sz; i++)
//        cout << ans[i] << " ";

    cin >> T;

    while(T--)
    {
        cin >> k;
        cout << upper_bound(ans, ans+sz, k) - ans - 1 << "\n";
    }
}
