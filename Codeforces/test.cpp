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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, k, N = 4;
    vector<int> perm = vector<int> (N, 0);
    for (k = 1; k < N; k <<= 1) 
    {
        for (i = 0; i < k; i++) 
        {
            perm[i] <<= 1;
            perm[i+k] = 1 + perm[i];
        }
    }

    for(i = 0; i < perm.size(); i++)
        cout << perm[i] << " ";
}