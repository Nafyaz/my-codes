#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll arr[MAXN], pref[MAXN];

ll getPhonetic(string s)
{
    ll i, ret = 0;

    for(i = 0; i < s.size();)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            ret++;
            while(i < s.size() && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'))
                i++;
        }
        else
            i++;
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, i, bg, ed, ans;
    string s;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> s;

        arr[i] = getPhonetic(s);
        pref[i] = pref[i-1] + arr[i];
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        bg = i;
        for(ed = bg; ed <= n && pref[ed] - pref[bg-1] < 5; ed++);

        if(ed > n || pref[ed] - pref[bg-1] != 5)
            continue;

        bg = ed + 1;
        for(ed = bg; ed <= n && pref[ed] - pref[bg-1] < 7; ed++);

        if(ed > n || pref[ed] - pref[bg-1] != 7)
            continue;

        bg = ed + 1;
        for(ed = bg; ed <= n && pref[ed] - pref[bg-1] < 5; ed++);

        if(ed > n || pref[ed] - pref[bg-1] != 5)
            continue;

        ans++;
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