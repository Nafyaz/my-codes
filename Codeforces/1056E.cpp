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

LL base = 31;
LL hashPref[MAXN];

LL bigmod(LL a, LL p)
{
    LL ret = 1;
    while(p)
    {
        if(p&1)
            ret = (ret * a) % MOD;

        a = (a*a) % MOD;
        p /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, z, o, zLen, oLen;
    LL sI, tI, zHash, oHash, tHash;
    LL ans = 0, found;
    string s, t;

    cin >> s >> t;

    z = o = 0;
    for(i = 0; i < s.size(); i++)
    {
        z += (s[i] == '0');
        o += (s[i] == '1');
    }

    for(i = 1; i <= t.size(); i++)
        hashPref[i] = (hashPref[i-1]*base + (t[i-1] - 'a' + 1)) % MOD;

    // show(z);
    // show(o) << "\n";

    for(zLen = 1; zLen < t.size(); zLen++)
    {
        if(t.size() <= z*zLen || (t.size() - z*zLen) % o != 0)
            continue;

        oLen = (t.size() - z*zLen) / o;
        found = 1;

        // show(zLen);
        // show(oLen);

        sI = 0;
        tI = 1;
        zHash = oHash = 0;
        while(tI <= t.size())
        {
            if(s[sI] == '0')
            {
                tHash = (hashPref[tI + zLen - 1] - (hashPref[tI-1]*bigmod(base, zLen))%MOD + MOD) % MOD;
                if(zHash == 0)
                    zHash = tHash;
                else if(zHash != tHash)
                {
                    found = 0;
                    break;
                }
                tI += zLen;
            }
            else
            {
                tHash = (hashPref[tI + oLen - 1] - (hashPref[tI-1]*bigmod(base, oLen))%MOD + MOD) % MOD;
                if(oHash == 0)
                    oHash = tHash;
                else if(oHash != tHash)
                {
                    found = 0;
                    break;
                }
                tI += oLen;
            }

            // show(sI);
            // show(tI);
            // show(tHash) << "\n";
            sI++;
        }

        // cout << "\n";

        // if(zLen == 3)
        // {
        //     cout << zHash << " " << oHash << "\n";
        // }

        if(zHash == oHash)
            found = 0;

        ans += found;
    }

    cout << ans << "\n";
}