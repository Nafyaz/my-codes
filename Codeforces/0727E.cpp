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

int n, k;

struct AC
{
    int id, P;
    int sz = 26;
    vector<vector<int>> trie;
    vector<int> link, out_link;
    vector<vector<int>> out, pat_before;

    AC() : id(0), P(0)
    {
        node();
    }

    int node()
    {
        trie.emplace_back(sz, 0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        return id++;
    }

    inline int get(char c)
    {
        return c - 'a';
    }

    int add_pattern(const string T)
    {
        int r = 0;
        for(auto c : T)
        {
            if(!trie[r][get(c)])
                trie[r][get(c)] = node();
            r = trie[r][get(c)];
        }
        // show(T);
        // show(r);
        // show(P) << "\n";
        out[r].push_back(P);
        pat_before.emplace_back(0);
        return P++;
    }

    void compute()
    {
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int c = 0; c < sz; c++)
            {
                int v = trie[u][c];
                if(!v)
                    trie[u][c] = trie[link[u]][c];
                else
                {
                    link[v] = u? trie[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty()? out_link[link[v]] : link[v];
                    q.push(v);
                }
            }
        }
    }

    int advance(int r, char c)
    {
        while(r && !trie[r][get(c)])
            r = link[r];
        r = trie[r][get(c)];
        return r;
    }

    vector<int> match(string s)
    {
        s = s + s;
        vector<int> ret(s.size());
        int u = 0;

        for(int i = 0; i < s.size(); i++)
        {
            // show(i);
            // for(int x = 0; x < pat_before.size(); x++)
            // {
            //     cout << x << ": ";
            //     for(auto y : pat_before[x])
            //         cout << y << " ";
            //     cout << "; ";
            // }
            // cout << "\n";

            u = advance(u, s[i]);
            for(int v = u; v; v = out_link[v])
            {
                if(!out[v].empty())
                {
                    int pat = out[v][0];
                    if(pat_before[pat].empty() || pat_before[pat].back() != i%k)
                    {
                        ret[i-k+1] = pat+1;
                        pat_before[pat].push_back(i%k);
                    }
                }
            }
        }

        return ret;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    AC aho;

    cin >> n >> k;

    int g;
    string s, t;

    cin >> s >> g;

    while(g--)
    {
        cin >> t;
        aho.add_pattern(t);
    }

    aho.compute();

    vector<int> pattern_start = aho.match(s);

    for(int i = 0; i < k; i++)
    {
        bool found = true;
        for(int j = i; j < n*k+i && found; j += k)
            found &= (pattern_start[j] != 0);
        if(found)
        {
            cout << "YES\n";
            for(int j = i; j < n*k+i; j += k)
                cout << pattern_start[j] << " ";
            return 0;
        }
    }

    cout << "NO\n";
}