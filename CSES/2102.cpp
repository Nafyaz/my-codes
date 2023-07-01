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
#define MAXN 100005

LL base = 31, HashPref[MAXN];
set<LL> HashSet[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL szS, szT, k, tHash, sHash, PowT;
    string s, t;

    cin >> s;
    szS = s.size();

    for(LL i = 1; i <= szS; i++)
        HashPref[i] = (HashPref[i-1]*base + (s[i-1] - 'a' + 1)) % MOD;
    
    cin >> k;

    while(k--)
    {
        cin >> t;
        szT = t.size();

        if(szT > szS)
        {
            cout << "NO\n";
            continue;
        }

        tHash = 0;
        PowT = 1;
        for(LL i = 1; i <= szT; i++)
        {
            tHash = (tHash*base + (t[i-1] - 'a' + 1)) % MOD;
            PowT = (PowT*base) % MOD;
        }

        if(HashSet[szT].empty())
        {
            for(LL i = szT; i <= szS; i++)
            {
                sHash = (HashPref[i] - (HashPref[i-szT] * PowT)%MOD + MOD) % MOD;
                HashSet[szT].insert(sHash);
            }
        }

        cout << (HashSet[szT].find(tHash) != HashSet[szT].end()? "YES\n" : "NO\n");
    }
}