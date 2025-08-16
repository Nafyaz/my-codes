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

int cmp(string &s, int idx, string &t)
{
    int i;
    for(i = idx; i < s.size() && i-idx < t.size(); i++)
    {
        if(t[i-idx] < s[i])
            return -1;
        if(t[i-idx] > s[i])
            return 1;
    }

    if(i-idx == t.size())
        return 0;
    return 1;
}

int get_low(string &s, vector<int> &sa, string &t)
{
    int low, high, mid, ret, sign;

    ret = -1;
    low = 0;
    high = s.size() - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;

        sign = cmp(s, sa[mid], t);

        // show(low);
        // show(high);
        // show(mid);
        // show(sign) << "\n";

        if(sign <= 0)
        {
            high = mid - 1;
            if(sign == 0)
                ret = mid;
        }
        else
            low = mid + 1;
    }

    return ret;
}

int get_high(string &s, vector<int> &sa, string &t)
{
    int low, high, mid, ret, sign;

    ret = -1;
    low = 0;
    high = s.size() - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;

        sign = cmp(s, sa[mid], t);

        if(sign < 0)
            high = mid - 1;
        else
        {
            low = mid + 1;
            if(sign == 0)
                ret = mid;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l, r;
    string s, t;

    cin >> s >> k;
    n = s.size();

    vector<int> sa = get_SA(s);

    while(k--)
    {
        cin >> t;

        l = get_low(s, sa, t);
        r = get_high(s, sa, t);

        // show(l);
        // show(r) << "\n";

        if(r != -1)
            cout << r-l+1 << "\n";
        else
            cout << "0\n";
    }
}