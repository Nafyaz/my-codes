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

int cmp(string &s, int idx,  string &t)
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, low, mid, high, sign;
    string s, t;
    bool found;

    cin >> s >> k;
    n = s.size();

    vector<int> sa = get_SA(s);

    // for(auto u : sa)
    //     cout << u << " ";

    while(k--)
    {
        cin >> t;

        low = 0;
        high = n-1;
        found = 0;
        while(low <= high)
        {
            mid = (low + high)/2;

            sign = cmp(s, sa[mid], t);

            // show(low);
            // show(high);
            // show(mid);
            // show(sa[mid]);
            // show(sign) << "\n";

            if(sign == 0)
            {
                found = 1;
                break;
            }

            if(sign == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout << (found? "YES\n" : "NO\n");
    }
}