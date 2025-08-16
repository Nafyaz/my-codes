#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
bool vis[100005][10];

string call(ll i, ll last, vector<ll> v, string s)
{
    ll j;
    string ret = "";

    if(i == n)
        return s;

    if(vis[i][last])
        return "";

    vis[i][last] = 1;

    for(j = 0; j < 10; j++)
    {
        if(i == 0 && j == 0)
            continue;

        if(j != last && v[j])
        {
            v[j]--;
            ret = call(i+1, j, v, s+char('0'+j));

            if(ret != "")
                return ret;

            v[j]++;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j, a[10];
    string ans;

    cin >> T;

    while(T--)
    {
        n = 0;

        for(i = 0; i < 10; i++)
        {
            cin >> a[i];

            n += a[i];
        }

        if(n == 1 && a[0] == 1)
        {
            cout << "0\n";
            continue;
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 10; j++)
                vis[i][j] = 0;
        }

        ans = call(0, -1, vector<ll>(a, a+10), "");

        if(ans == "")
            cout << "-1\n";
        else
        {
//            if(ans.size() >= 2 && ans[0] == '0')
//                swap(ans[0], ans[1]);
            cout << ans << "\n";
        }
    }
}
