#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[5003];

ll func(ll id)
{
    ll i, ret = 0, moves, prev;

    prev = 0;
    for(i = id-1; i >= 0; i--)
    {
        moves = prev / a[i] + 1;
        prev = a[i]*moves;
        ret += moves;
    }

    prev = 0;
    for(i = id + 1; i < n; i++)
    {
        moves = prev / a[i] + 1;
        prev = a[i]*moves;
        ret += moves;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

//    for(auto u : mnIdx)
//        cout << u << " ";
//    cout << "\n";

    ans = LLONG_MAX;
    for(i = 0; i < n; i++)
    {
        ans = min(ans, func(i));
    }

    cout << ans;
}
