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

vector<LL> z_function(string s)
{
    LL n = s.size();
    vector<LL> Z(n);

    Z[0] = 0;
    for(LL i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[i+Z[i]] == s[Z[i]])
            Z[i]++;

        if(i+Z[i]-1 > r)
        {
            l = i;
            r = i+Z[i]-1;
        }
    }

    return Z;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    vector<LL> Z = z_function(s);

    vector<LL> ans;
    for(LL i = 1; i < s.size(); i++)
    {
        if(i+Z[i] == s.size())
            ans.push_back(Z[i]);
    }

    reverse(ans.begin(), ans.end());

    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
}