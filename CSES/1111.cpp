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

vector<LL> manacher(string s)
{
    LL k, n = s.size();
    vector<LL> pal(n);

    for(LL i = 0, l = 0, r = -1; i < n; i++)
    {
        if(i > r)
            k = 1;
        else
            k = min(pal[l+r-i], r-i+1);

        while(i-k >= 0 && i+k < n && s[i-k] == s[i+k])
            k++;

        pal[i] = k;
        k--;

        if(i+k > r)
        {
            l = i-k;
            r = i+k;
        }
    }

    return pal;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, stemp, ans;
    LL len = 0, mid;

    cin >> stemp;

    s = '#';
    for(LL i = 0; i < stemp.size(); i++)
    {
        s.push_back(stemp[i]);
        s.push_back('#');
    }

    vector<LL> pal = manacher(s);

    for(LL i = 0; i < pal.size(); i++)
    {
        if(pal[i]-1 > len)
        {
            len = pal[i] - 1;
            mid = i;
        }
    }

    for(LL i = mid-len+1; i < mid+len; i++)
    {
        if(s[i] != '#')
            ans.push_back(s[i]);
    }

    cout << ans << "\n";
}