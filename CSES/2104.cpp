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

int Log[MAXN], rmq[MAXN][20];

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
            if(i + len/2 >= n)
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

void rmq_init()
{
    Log[1] = 0;
    for(int i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;
}

void build_RMQ(vector<int> &sa)
{
    int i, j, n = sa.size();

    for(i = 0; i < n; i++)
        rmq[i][0] = sa[i];

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1<<j) - 1 < n; i++)
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1<<(j-1))][j-1]);
    }
}

int rmq_query(int bg, int ed)
{
    int k = Log[ed-bg+1];
    return min(rmq[bg][k], rmq[ed - (1<<k) + 1][k]);
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

int get_Low(string &s, vector<int> &sa, string &t)
{
    int i, low, high, mid, sign, ret = -1;

    low = 0;
    high = s.size()-1;
    while(low <= high)
    {
        mid = (low + high) / 2;

        sign = cmp(s, sa[mid], t);

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

int get_High(string &s, vector<int> &sa, string &t)
{
    int i, low, high, mid, sign, ret = -1;

    low = 0;
    high = s.size()-1;;
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

    rmq_init();
    build_RMQ(sa);

    while(k--)
    {
        cin >> t;

        l = get_Low(s, sa, t);
        if(l == -1)
        {
            cout << "-1\n";
            continue;
        }
        r = get_High(s, sa, t);

        cout << rmq_query(l, r) + 1<< "\n";
    }
}