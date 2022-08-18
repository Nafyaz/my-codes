#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

const ll base1 = 31;
const ll base2 = 37;
ll p1[MAXN], p2[MAXN];

ll conv1(string s)
{
    ll i, ret = 0;

    for(i = 0; i < s.size(); i++)
        ret = (ret + (s[i] - 'a' + 1)*p1[i]) % MOD;

    return ret;
}

ll conv2(string s)
{
    ll i, ret = 0;

    for(i = 0; i < s.size(); i++)
        ret = (ret + (s[i] - 'a' + 1)*p2[i]) % MOD;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j, k, ans;
    ll sHash1, sHash2, tHash1, tHash2;

    unordered_map<string, ll> mp;
    set<ll> st1, st2;
    string s, t;

    p1[0] = p2[0] = 1;
    for(i = 1; i < MAXN; i++)
    {
        p1[i] = (p1[i-1] * base1)%MOD;
        p2[i] = (p2[i-1] * base2)%MOD;
    }

    cin >> n >> m;

    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> s;
        t = s;

        sHash1 = conv1(s);
        sHash2 = conv2(s);

        for(j = 0; j < m; j++)
        {
            for(k = 0; k < 26; k++)
            {
                if(s[j] != 'a' + k)
                {
                    t[j] = 'a' + k;

                    tHash1 = ((sHash1 - (s[j] - 'a' + 1)*p1[j] + (k+1)*p1[j]) % MOD + MOD) % MOD;
                    tHash2 = ((sHash2 - (s[j] - 'a' + 1)*p2[j] + (k+1)*p2[j]) % MOD + MOD) % MOD;

                    if(st1.find(tHash1) != st1.end() && st2.find(tHash2) != st2.end())
                        ans += mp[t];
                }
            }

            t[j] = s[j];
        }

        st1.insert(sHash1);
        st2.insert(sHash2);
        mp[s]++;
    }

    cout << ans << "\n";
}