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

typedef vector<vector<LL>> Mat;

Mat Mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<LL>(B[0].size()));

    LL i, j;

    for(i = 0; i < A.size(); i++)
    {
        for(j = 0; j < B[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
            {
                ret[i][j] += (A[i][k] * B[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
}

Mat Pow(Mat A, LL p)
{
    Mat ret(A.size(), vector<LL>(A[0].size()));

    LL i, j;
    for(i = 0; i < A.size(); i++)
        ret[i][i] = 1;

    while(p)
    {
        if(p%2)
            ret = Mul(ret, A);
        
        A = Mul(A, A);
        p /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, k, i, j;

    cin >> n >> k;
    Mat A(n, vector<LL>(n));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> A[i][j];
    }

    A = Pow(A, k-1);


}