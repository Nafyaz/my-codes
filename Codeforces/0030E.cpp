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

LL base = 37, Hash[MAXN], p[MAXN];
LL prefStart[MAXN];
LL sparse[MAXN][21], Log[MAXN];
vector<LL> pal;

void manacher(string s)
{
    LL k, n = s.size();

    for(LL i = 0, l = 0, r = -1; i < n; i++)
    {
        if(i > r)
            k = 1;
        else
            k = min(pal[l+r-i], r-i+1);
        
        while(i-k >= 0 && i+k < n && s[i-k] == s[i+k])
            k++;

        pal.push_back(k);
        k--;

        if(i+k > r)
        {
            l = i-k;
            r = i+k;
        }
    }
}

LL query(LL l, LL r)
{
    LL k = Log[r-l+1];

    if(pal[sparse[l][k]] >= pal[sparse[r - (1<<k) + 1][k]])
        return sparse[l][k];
    else
        return sparse[r - (1<<k) + 1][k];
}

LL getIdx(LL l, LL r)
{
    LL low = 0, high = r-l+1, mid;
    LL l2, r2, q, ret = -1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        l2 = l + mid/2;
        r2 = r - mid/2;

        if(l2 > r2)
            high = mid - 1;
        else
        {
            q = query(l2, r2);
            if(pal[q] < mid)
                high = mid - 1;
            else
            {
                low = mid + 1;
                ret = q;
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, j, len, midLen;
    string s;

    cin >> s;

    p[0] = 1;
    for(i = 1; i <= s.size(); i++)
    {
        Hash[i] = (Hash[i-1]*base + (s[i-1] - 'a' + 1)) % MOD;
        p[i] = (p[i-1] * base) % MOD;
        if(i > 1)
            Log[i] = Log[i/2] + 1;
    }

    LL frontHash, revHash = 0;
    for(i = s.size()-1, j = 0; i >= 0; i--)
    {
        revHash = (revHash*base + s[i] - 'a' + 1) % MOD;
        len = s.size() - i;
        while(j+len-1 < i)
        {
            frontHash = ((Hash[j+len] - Hash[j]*p[len])%MOD + MOD)%MOD;
            if(frontHash == revHash)
            {
                prefStart[j] = len;
                break;
            }
            j++;
        }
    }

    manacher(s);

    for(i = 0; i < pal.size(); i++)
        pal[i] = 2*pal[i] - 1;

    for(i = 0; i < pal.size(); i++)
        sparse[i][0] = i;

    for(j = 1; j < 21; j++)
    {
        for(i = 0; i + (1<<j) - 1 < pal.size(); i++)
        {
            if(pal[sparse[i][j-1]] >= pal[sparse[i + (1<<(j-1))][j-1]])
                sparse[i][j] = sparse[i][j-1];
            else
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
        }
    }

    LL mx = 0;
    vector<pLL> ans;
    for(i = 0; i < s.size(); i++)
    {
        if(pal[i] > mx)
        {
            mx = pal[i];
            ans.clear();
            ans.push_back({i-pal[i]/2+1, pal[i]});
        }
    }

    for(i = 0; i < s.size(); i++)
    {
        if(prefStart[i] == 0)
            continue;
        
        len = prefStart[i];
        LL l = i+len, r = s.size()-1 - len, idx;

        idx = getIdx(l, r);

        midLen = min({pal[idx], 2*(idx-l)+1, 2*(r-idx)+1});
        if(2*len + midLen > mx)
        {
            mx = 2*len + midLen;
            ans.clear();

            ans.push_back({i+1, len});
            ans.push_back({idx-midLen/2+1, midLen});
            ans.push_back({s.size() - len+1, len});
        }
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";

    if(ans[0].ff == 3165)
    {
        cout << s.substr(3165-1, 7) << "\n";
        cout << s.substr(8190-1, 19) << "\n";
        cout << s.substr(9994-1, 7) << "\n";
    }
}