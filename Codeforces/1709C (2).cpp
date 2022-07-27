#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int n;
map<pii, int> mp;
string s;

int call(int pos, int opening)
{
    if(opening < 0)
        return 0;

    if(pos == n)
        return (opening == 0);

    if(mp.find({pos, opening}) != mp.end())
        return mp[{pos, opening}];

    if(s[pos] == '(')
        return mp[{pos, opening}] = call(pos+1, opening+1);
    else if(s[pos] == ')')
        return mp[{pos, opening}] = call(pos+1, opening-1);

    int ret, r1, r2;

    r1 = call(pos+1, opening+1);
    if(r1 == -1)
        return mp[{pos, opening}] = -1;

    r2 = call(pos+1, opening-1);
    if(r2 == -1)
        ret = -1;
    else if(r1 && r2)
        ret = -1;
    else if(!r1 && !r2)
        ret = 0;
    else
        ret = 1;

    return mp[{pos, opening}] = ret;
}

void solve(int caseno)
{
    int ans;

    cin >> s;
    n = s.size();

    mp.clear();
    ans = call(0, 0);

    if(ans == -1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}


