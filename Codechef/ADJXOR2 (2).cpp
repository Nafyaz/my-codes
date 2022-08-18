#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll x;
ll arr[MAXN];

struct st
{
    ll v[2][2];

    ll getMax()
    {
        return max({v[0][0], v[0][1], v[1][0], v[1][1]});
    }
};

st call(ll bg, ll ed)
{
    st ret;

    ret.v[0][0] = 0;    ret.v[0][1] = 0;
    ret.v[1][0] = 0;    ret.v[1][1] = 0;

    if(bg == ed)
        return ret;

    if(bg+1 == ed)
    {
        ret.v[0][0] = arr[bg]^arr[ed];  ret.v[0][1] = arr[bg]^(arr[ed]+x);
        ret.v[1][0] = (arr[bg]+x)^arr[ed];  ret.v[1][1] = (arr[bg]+x)^(arr[ed]+x);

        return ret;
    }

    ll mid = (bg+ed)/2;

    st ret1 = call(bg, mid);
    st ret2 = call(mid+1, ed);

    ret.v[0][0] = max(ret1.v[0][0] + (arr[mid]^arr[mid+1]) + ret2.v[0][0], ret1.v[0][1] + ((arr[mid]+x)^(arr[mid+1]+x)) + ret2.v[1][0]);
    ret.v[0][1] = max(ret1.v[0][0] + (arr[mid]^arr[mid+1]) + ret2.v[0][1], ret1.v[0][1] + ((arr[mid]+x)^(arr[mid+1]+x)) + ret2.v[1][1]);
    ret.v[1][0] = max(ret1.v[1][0] + (arr[mid]^arr[mid+1]) + ret2.v[0][0], ret1.v[1][1] + ((arr[mid]+x)^(arr[mid+1]+x)) + ret2.v[1][0]);
    ret.v[1][1] = max(ret1.v[1][0] + (arr[mid]^arr[mid+1]) + ret2.v[0][1], ret1.v[1][1] + ((arr[mid]+x)^(arr[mid+1]+x)) + ret2.v[1][1]);

    return ret;
}

void solve(int caseno)
{
    ll n, i;

    cin >> n >> x;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    cout << call(1, n).getMax() << "\n";
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


