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
#define MAXN 200005

vector<int> get_SA(string &s)
{
    int i, len, cnt, n = s.size();
    vector<int> prev(n), ret(n);
    vector<pair<pii, int>> curr;

    for(i = 0; i < n; i++)
        prev[i] = s[i];

    for(len = 2; len <= 2*n; len *= 2)
    {
        curr.clear();
        for(i = 0; i < n; i++)
        {
            if(i+len/2 >= n)
                curr.push_back({{prev[i], -1}, i});
            else
                curr.push_back({{prev[i], prev[i+len/2]}, i});
        }

        sort(curr.begin(), curr.end());

        for(i = cnt = 0; i < n; i++)
        {
            if(i == 0 || curr[i].ff == curr[i-1].ff)
                prev[curr[i].ss] = cnt;
            else
                prev[curr[i].ss] = ++cnt;
        }
    }

    for(i = 0; i < n; i++)
        ret[prev[i]] = i;

    return ret;
}

vector<int> get_LCP(string &s, vector<int> &sa)
{
    int i, j, k, n = s.size();

    vector<int> lcp(n-1, 0), rank(n, 0);

    for(i = 0; i < n; i++)
        rank[sa[i]] = i;

    for(i = 0, k = 0; i < n; i++)
    {
        if(rank[i] == n-1)
        {
            k = 0;
            continue;
        }

        j = sa[rank[i] + 1];
        while(i+k < n && j+k < n && s[i+k] == s[j+k])
            k++;

        lcp[rank[i]] = k;

        k = max(k-1, 0);
    }

    return lcp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n, len, idx;

    cin >> s;
    n = s.size();

    vector<int> sa = get_SA(s);
    vector<int> lcp = get_LCP(s, sa);

    len = 0;
    for(int i = 0; i+1 < n; i++)
    {
        if(lcp[i] > len)
        {
            len = lcp[i];
            idx = sa[i];
        }
    }

    if(len == 0)
        cout << "-1\n";
    else
        cout << s.substr(idx, len) << "\n";
}