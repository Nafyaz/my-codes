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

void radix_sort(vector<pair<pii, int>> &v, int cnt)
{
    int n = v.size();
    vector<pair<pii, int>> bucket[cnt+2];

    // for(int i = 0; i < MAXN; i++)
    //     bucket[i].clear();

    for(int i = 0; i < n; i++)
        bucket[v[i].ff.ss + 1].push_back(v[i]);

    v.clear();
    for(int i = 0; i < cnt+1; i++)
    {
        for(auto u : bucket[i])
            v.push_back(u);
        bucket[i].clear();
    }
    for(int i = 0; i < n; i++)
        bucket[v[i].ff.ff].push_back(v[i]);

    v.clear();
    for(int i = 0; i < cnt+1; i++)
    {
        for(auto u : bucket[i])
            v.push_back(u);
    }
}

vector<int> get_SA(string s)
{
    int i, len, cnt = 26, n = s.size();
    vector<int> prev(n), sa(n);
    vector<pair<pii, int>> curr;

    for(i = 0; i < n; i++)
        prev[i] = s[i] - 'a';

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

        radix_sort(curr, cnt);
        // sort(curr.begin(), curr.end());

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    vector<int> sa = get_SA(s);

    rotate(s.begin(), s.begin()+sa[0], s.end());

    cout << s << "\n";
}