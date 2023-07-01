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
    LL i, l, r, k, n = s.size();
    vector<LL> pal(n);

    for(i = 0, l = 0, r = -1; i < n; i++)
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

void solve(int caseno)
{
    string s, sTemp;
    LL i, mx, n;

    cin >> s;

    sTemp = '#';
    for(i = 0; i < s.size(); i++)
    {
        sTemp.push_back(s[i]);
        sTemp.push_back('#');
    }
    n = sTemp.size();

    vector<LL> pal = manacher(sTemp);

    // for(i = 0; i < n; i++)
    //     cout << pal[i] << " ";
    // cout << "\n";

    mx = 0;
    for(i = n-1; i >= 1; i--)
    {
        if(i + pal[i] - 1 == n-1)
        {
            if(i&1)
                mx = max(mx, pal[i]/2*2-1);
            else
                mx = max(mx, pal[i]/2*2);
        }
    }
    
    cout << "Case " << caseno << ": " << 2*s.size() - mx << "\n";
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