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

LL base = 31, Hash[MAXN], p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;

    p[0] = 1;
    for(LL i = 1; i < MAXN; i++)
        p[i] = (p[i-1]*base) % MOD;

    while(cin >> s)
    {
        if(s == ".")
            break;
            
        LL i, len, h1, h2;

        for(i = 1; i <= s.size(); i++)
            Hash[i] = (Hash[i-1]*base + (s[i-1] - 'a' + 1)) % MOD;
        
        for(len = 1; len <= s.size(); len++)
        {
            h1 = Hash[s.size()-len];
            h2 = ((Hash[s.size()] - Hash[len] * p[s.size() - len]) % MOD + MOD) % MOD;

            if(h1 == h2)
            {
                cout << s.size()/len << "\n";
                break;
            }
        }
    }
}