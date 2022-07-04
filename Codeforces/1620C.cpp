#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, k, x, i, j, cnt;
    string s, ans;

    cin >> n >> k >> x >> s;

    reverse(s.begin(), s.end());

    vector<ll> div;
    queue<ll> bCnt;
    i = 0;
    while(i < n)
    {
        while(i < n && s[i] == 'a')
            i++;
        
        cnt = 0;
        while(i < n && s[i] == '*')
        {
            cnt++;
            i++;
        }
        div.push_back(cnt*k + 1);
    }

    x--;
    for(i = 0; i < div.size(); i++)
    {
        if(x)
        {
            bCnt.push(x%div[i]);
            x /= div[i];
        }
    }

    ans = "";
    i = 0;
    while(i < n)
    {
        while(i < n && s[i] == 'a')
        {
            i++;
            ans.push_back('a');
        }

        if(!bCnt.empty())
        {
            for(j = 0; j < bCnt.front(); j++)
                ans.push_back('b');
            bCnt.pop();
        }

        while(i < n && s[i] == '*')
            i++;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}