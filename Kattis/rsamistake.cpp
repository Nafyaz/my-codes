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

map<LL, LL> factorize(LL n)
{
    LL i;
    map<LL, LL> ret;

    for(i = 2; i*i <= n; i++)
    {
        while(n%i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }

    if(n > 1)
        ret[n]++;

    return ret;
}

void solve(int caseno)
{
    LL A, B;

    cin >> A >> B;

    if(A == B)
    {
        cout << "no credit\n";
        return;
    }

    map<LL, LL> freqA, freqB;

    freqA = factorize(A);
    freqB = factorize(B);

    if(freqA.size() == 1 && freqB.size() == 1 && (*freqA.begin()).ss == 1 && (*freqB.begin()).ss == 1)
    {
        cout << "full credit\n";
        return;
    }

    for(auto u : freqA)
    {
        if(u.ss > 1 || freqB.find(u.ff) != freqB.end())
        {
            cout << "no credit\n";
            return;
        }
    }

    for(auto u : freqB)
    {
        if(u.ss > 1 || freqA.find(u.ff) != freqA.end())
        {
            cout << "no credit\n";
            return;
        }
    }

    cout << "partial credit\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
