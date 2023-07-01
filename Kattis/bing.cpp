#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

LL trie[MAXN][26], cnt[MAXN];
LL id;

LL calc(string s)
{
    LL r = 0;
    for(LL i = 0; i < s.size(); i++)
    {
        if(trie[r][s[i] - 'a'] == 0)
            return 0;
        
        r = trie[r][s[i] - 'a'];
    }

    return cnt[r];
}

void add(string s)
{
    LL r = 0;
    for(LL i = 0; i < s.size(); i++)
    {
        if(trie[r][s[i] - 'a'] == 0)
            trie[r][s[i] - 'a'] = ++id;

        r = trie[r][s[i] - 'a'];
        cnt[r]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n;
    string s;

    cin >> n;

    while(n--)
    {
        cin >> s;

        cout << calc(s) << "\n";
        add(s);
    }
}