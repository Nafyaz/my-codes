#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

string s;
unordered_map<char, string> morse;
LL base = 5, sHash[MAXN], dp[MAXN], Pow[102];
multiset<LL> adj[102];

LL call(LL bg)
{
    // show(bg) << "\n";

    if(bg == s.size()+1)
        return 1;

    if(dp[bg] != -1)
        return dp[bg];

    LL len, h, ret = 0, i;
    for(len = 1; len < 102 && bg+len-1 <= s.size(); len++)
    {
        h = ((sHash[bg+len-1] - sHash[bg-1]*Pow[len])%MOD + MOD) % MOD;

        // show(len);
        // show(h);
        // cout << "\n";
        
        if(adj[len].find(h) != adj[len].end())
            ret += adj[len].count(h) * call(bg+len);
    }

    return dp[bg] = ret;
}

void solve(int caseno)
{
    LL i, j, k, n, h, len;
    string t, u;

    for(i = 0; i < 102; i++)
        adj[i].clear();

    cin >> s >> n;

    for(i = 1; i <= s.size(); i++)
        sHash[i] = (base*sHash[i-1] + (s[i-1] == '-') + 1) % MOD;

    for(i = 0; i < n; i++)
    {
        cin >> t;

        h = len = 0;
        for(j = 0; j < t.size(); j++)
        {
            for(k = 0; k < morse[t[j]].size(); k++)
            {
                len++;
                h = (base*h + (morse[t[j]][k] == '-') + 1) % MOD;
            }
        }
        
        adj[len].insert(h);
    }

    // cout << *adj[3].begin() << "\n";

    fill(dp, dp+s.size()+1, -1);
    cout << call(1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    morse['A'] = ".-";
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";

    Pow[0] = 1;
    for(LL i = 1; i < 102; i++)
        Pow[i] = (base*Pow[i-1]) % MOD;

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}