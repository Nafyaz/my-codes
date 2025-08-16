#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

void FWHT(vector< LL >&p, bool inverse)
{
    LL n = p.size();
    assert((n&(n-1))==0);

    for (LL len = 1; 2*len <= n; len <<= 1) {
        for (LL i = 0; i < n; i += len+len) {
            for (LL j = 0; j < len; j++) {
                LL u = p[i+j];
                LL v = p[i+len+j];

                #ifdef bitwiseXOR
                p[i+j] = (u+v)%MOD;
                p[i+len+j] = (u-v+MOD)%MOD;
                #endif // bitwiseXOR

                #ifdef bitwiseAND
                if (!inverse) {
                    p[i+j] = v % MOD;
                    p[i+len+j] = (u+v) % MOD;
                } else {
                    p[i+j] = (-u+v) % MOD;
                    p[i+len+j] = u % MOD;
                }
                #endif // bitwiseAND

                #ifdef bitwiseOR
                if (!inverse) {
                    p[i+j] = u+v;
                    p[i+len+j] = u;
                } else {
                    p[i+j] = v;
                    p[i+len+j] = u-v;
                }
                #endif // bitwiseOR
            }
        }
    }

    #ifdef bitwiseXOR
    if (inverse) {
        LL val=BigMod(n,MOD-2); //Option 2: Exclude
        for (LL i = 0; i < n; i++) {
            //assert(p[i]%n==0); //Option 2: Include
            p[i] = (p[i]*val)%MOD; //Option 2: p[i]/=n;
        }
    }
    #endif // bitwiseXOR
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;
    vector<int> vS, vT;
    string S, T;

    cin >> S;

    T = S;
    reverse(T.begin(), T.end());

    for(i = 0; i < S.size(); i++)
    {
        vS.push_back(S[i] == 'A');
        vT.push_back(T[i] == 'A');
    }

    
}
