#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006
#define prime 10007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j, hash, underscores, minUnder, maxUnder, total;
    bool isOk;
    string S[8], T, temp;
    set<int> Hash;
    map<string, int> revS;

    cin >> n >> m;

    total = 0;
    for(i = 0; i < n; i++)
    {
        cin >> S[i];
        revS[S[i]] = i;

        total += S[i].size();
    }

    minUnder = max(0, 3 - total);
    maxUnder = max(0, 16 - total);

    for(i = 0; i < m; i++)
    {
        cin >> T;

        if(T[0] == '_' || T.back() == '_')
            continue;

        isOk = 1;
        temp = "";
        hash = 0;
        for(j = 0; j < T.size(); j++)
        {
            if(T[j] == '_')
            {
                underscores++;
                continue;
            }
            else if(underscores != 0)
            {
                hash = (hash*primes + underscores) % MOD;
                underscores = 0;
            }

            while(j < T.size() && T[j] != '_')
            {
                temp.push_back(T[j]);
                j++;
            }

            if(revS.find(temp) == revS.end())
            {
                isOk = 0;
                break;
            }
            else
            {
                hash = (hash*prime + revS[temp]) % MOD;
                temp = "";
                underscores = 1;
            }

        }

        if(isOk)
        {
            Hash.insert(hash);
        }
    }

    sort(s, s+n);

    do
    {
        
    }while(next_permutation(s, s+n));
}