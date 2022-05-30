#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;

void solve()
{
    ll n;
    cin >> n;
    cout << upper_bound(v.begin(), v.end(), n) - v.begin() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, a, b, c;

    for(a = 1; (a*a + 1) / 2 <= 1000000009; a += 2)
    {
        b = (a*a - 1)/2;
        c = b + 1;

        if(a <= b && b <= c && a*a + b*b == c*c && a*a == b + c)
            v.push_back(c);
    }

    // cout << is_sorted(v.begin(), v.end()) << "\n";

    // for(int i = 0; i < 10; i++)
    //     cout << v[i] << " ";
    // cout << "\n";

    cin >> T;
    
    while(T--)
    {
        solve();
    }
}