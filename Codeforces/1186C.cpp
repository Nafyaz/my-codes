#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 1000006

void solve(ll caseno)
{
    ll i, j, subLen, aOne, bOne, ans;
    string a, b;

    cin >> a >> b;

    aOne = 0;
    for(i = 0; i < b.size(); i++)
        aOne += (a[i] == '1');

    bOne = 0;
    for(i = 0; i < b.size(); i++)
        bOne += (b[i] == '1');    

    ans = ((aOne + bOne) % 2 == 0);

    subLen = a.size() - b.size() + 1;
    for(i = 1; i < subLen; i++)
    {
        aOne += (a[b.size() + i-1] == '1');
        aOne -= (a[i-1] == '1');

        ans += ((aOne + bOne) % 2 == 0);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}