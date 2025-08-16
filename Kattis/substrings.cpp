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
    vector<LL> prev(n), sa(n);
    vector<pair<pLL, LL>> curr(n);

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
        sa[prev[i]] = i;

    return sa;
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

void solve(int caseno)
{
    LL single, distinct, n;
    string s;

    cin >> s;
    n = s.size();

    if(n == 1)
    {
        cout << "0\n";
        return;
    }

    vector<LL> sa = get_SA(s);
    vector<LL> lcp = get_LCP(s, sa);

    // for(LL i = 0; i < n; i++)
    //     cout << sa[i] << " ";
    // cout << "\n";
    // for(LL i = 0; i+1 < n; i++)
    //     cout << lcp[i] << " ";
    // cout << "\n";

    single = distinct = 0;
    single += n-sa[0] - lcp[0];
    distinct += lcp[0];
    // cerr << single << " ";
    for(LL i = 1; i+1 < n; i++)
    {
        single += n-sa[i] - max(lcp[i-1], lcp[i]);
        distinct += lcp[i];
        // cerr << single << " ";
    }
    single += n-sa[n-1] - lcp[n-2];
    // cerr << single << " \n";

    distinct = n*(n+1)/2 - distinct;

    // show(single);
    // show(distinct) << "\n";
    cout << distinct - single << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}