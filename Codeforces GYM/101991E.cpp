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

struct AC
{
    LL id, pCnt;
    const LL sz = 26;
    vector<string> p;
    vector<vector<LL>> trie;
    vector<LL> failLink, outLink, len, order, joyLevel, popular;
    vector<vector<LL>> out;

    AC() : id(0), pCnt(0)
    {
        node();
    }

    LL node()
    {
        trie.emplace_back(sz, 0);
        failLink.emplace_back(0);
        outLink.emplace_back(0);
        len.emplace_back(0);
        out.emplace_back(0);
        joyLevel.emplace_back(0);
        popular.emplace_back(0);
        return id++;
    }

    inline LL get(char c)
    {
        return c - 'a';
    }

    LL add_pattern(string &s, vector<LL> &a)
    {
        LL r = 0, x = 0;
        for(LL i = 0; i < s.size(); i++)
        {
            if(!trie[r][get(s[i])])
                trie[r][get(s[i])] = node();
            r = trie[r][get(s[i])];
            len[r] = ++x;
            joyLevel[r] = max(joyLevel[r], a[i]);
            popular[r]++;
        }
        out[r].push_back(pCnt);
        return pCnt++;
    }

    void bfs()
    {
        queue<pLL> q;
        len[0] = 0;
        q.push({0, len[0]});
        order.push_back(0);
        while(!q.empty())
        {
            LL r = q.front().ff;
            LL l = q.front().ss;
            q.pop();
            for(LL c = 0; c < sz; c++)
            {
                LL r2 = trie[r][c];
                if(!r2)
                    trie[r][c] = trie[failLink[r]][c];
                else
                {
                    failLink[r2] = r ? trie[failLink[r]][c] : 0;
                    outLink[r2] = out[failLink[r2]].empty()? outLink[failLink[r2]] : failLink[r2];
                    len[r2] = l+1;
                    q.push({r2, len[r2]});
                    order.push_back(r2);
                }
            }
        }
    }

    void distA()
    {
        reverse(order.begin(), order.end());

        for(auto o : order)
            joyLevel[failLink[o]] = max(joyLevel[failLink[o]], joyLevel[o]);
    }

    LL calc()
    {
        LL ret = 0;
        for(auto o : order)
            ret = max(ret, popular[o]*joyLevel[o]*len[o]);
        return ret;
    }
};

void solve(int caseno)
{
    AC aho;
    LL n;

    cin >> n;

    vector<string> s(n);
    vector<vector<LL>> a(n, vector<LL>());

    for(LL i = 0; i < n; i++)
        cin >> s[i];

    for(LL i = 0; i < n; i++)
    {
        a[i].resize(s[i].size());
        for(LL j = 0; j < s[i].size(); j++)
            cin >> a[i][j];
    }

    for(LL i = 0; i < n; i++)
        aho.add_pattern(s[i], a[i]);

    aho.bfs();
    aho.distA();

    cout << aho.calc() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("exciting.in", "r", stdin);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}