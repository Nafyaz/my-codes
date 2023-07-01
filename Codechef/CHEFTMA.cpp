#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

pll arr[MAXN];
ll diff[MAXN];

void solve(ll caseno)
{
    ll n, w, b, i, j, k, ans;
    ll W, B;

    cin >> n >> w >> b;

    for(i = 0; i < n; i++)
        cin >> arr[i].ff;
    for(i = 0; i < n; i++)
        cin >> arr[i].ss;

    for(i = 0; i < n; i++)
        diff[i] = arr[i].ff - arr[i].ss;

    vector<ll> buttons;
    for(i = 0; i < w; i++)
    {
        cin >> W;
        buttons.push_back(W);
    }
    for(i = 0; i < b; i++)
    {
        cin >> B;
        buttons.push_back(B);
    }

    sort(diff, diff+n, greater<ll>());
    sort(buttons.begin(), buttons.end(), greater<ll>());

    // for(i = 0; i < n; i++)
    //     cout << diff[i] << " ";
    // cout << "\n";
    // for(auto u : buttons)
    //     cout << u << " ";
    // cout << "\n";

    for(i = 0, j = 0; i < n; i++)
    {
        while(j < buttons.size() && buttons[j] > diff[i])
            j++;

        if(j < buttons.size())
        {
            diff[i] -= buttons[j];
            j++;
        }
    }

    ans = 0;
    for(i = 0; i < n; i++)    
        ans += max(0LL, diff[i]);
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}