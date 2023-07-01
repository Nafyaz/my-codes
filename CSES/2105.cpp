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

vector<LL> get_SA(string &s)
{
    LL i, len, cnt, n = s.size();

    vector<LL> prev(n), ret(n);
    vector<pair<pLL, LL>> curr;

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

vector<LL> get_LCP(string &s, vector<LL> &sa)
{
    LL i, j, k, n = s.size();

    vector<LL> lcp(n-1), rank(n);

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

        k = max(k-1, 0LL);
    }

    return lcp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, sum;
    string s;

    cin >> s;
    n = s.size();

    vector<LL> sa = get_SA(s);
    vector<LL> lcp = get_LCP(s, sa);

    sum = 0;
    for(auto u : lcp)
        sum += u;

    // cout << lcp[0] << " " << lcp[1] << " " << lcp[2] << "\n";

    cout << n*(n+1)/2 - sum << "\n";
}