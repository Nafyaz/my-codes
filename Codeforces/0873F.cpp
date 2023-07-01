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
            if(i + len/2 >= n)
                curr.push_back({{prev[i], -1}, i});
            else
                curr.push_back({{prev[i], prev[i+len/2]}, i});
        }

        sort(curr.begin(), curr.end());

        for(i = 0, cnt = 0; i < n; i++)
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

    LL n, l, r, ans;
    string s, t;

    cin >> n >> s >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    vector<LL> sa = get_SA(s);
    vector<LL> lcp = get_LCP(s, sa);

    vector<LL> pref;
    pref.push_back(t[sa[0]] == '0');
    for(LL i = 1; i < n; i++)
        pref.push_back(pref.back() + (t[sa[i]] == '0'));

    ans = 0;
    for(LL i = 0; i < n; i++)
        ans = max(ans, (t[i] == '0')*(n-i));

    stack<LL> stk;
    for(r = 0; r < n-1; r++)
    {
        while(!stk.empty() && lcp[stk.top()] >= lcp[r])
        {
            LL mid = stk.top();
            stk.pop();

            if(!stk.empty())
                l = stk.top();
            else
                l = -1;

            if(l == -1)
                ans = max(ans, lcp[mid]*pref[r]);
            else
                ans = max(ans, lcp[mid]*(pref[r] - pref[l]));
        }

        stk.push(r);
    }

    while(!stk.empty())
    {
        LL mid = stk.top();
        stk.pop();

        if(!stk.empty())
            l = stk.top();
        else
            l = -1;

        if(l == -1)
            ans = max(ans, lcp[mid]*pref[n-1]);
        else
        {
            // if(mid >= lcp.size() || mid < 0)
            //     show(mid);
            // if(n-1 >= pref.size() || n-1 < 0)
            //     show(n-1);
            // if(l >= pref.size() || l < 0)
            //     show(l) << "\n";
            ans = max(ans, lcp[mid]*(pref[n-1] - pref[l]));
        }
    }

    cout << ans << "\n";
}