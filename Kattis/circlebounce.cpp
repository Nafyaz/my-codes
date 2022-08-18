#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a%MOD;

    ll res = bigmod(a, p/2);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

ll invmod(ll a)
{
    return bigmod(a, MOD-2);
}

typedef vector<vector<ll>> Mat;

Mat Mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k]*B[k][j])%MOD)%MOD;
        }
    }

    return ret;
}

Mat Pow(Mat A, ll p)
{
    Mat ret(A.size(), vector<ll>(A[0].size()));

    for(ll i = 0; i < ret.size(); i++)
        ret[i][i] = 1;

    while(p)
    {
        if(p&1)
            ret = Mul(ret, A);
        A = Mul(A, A);
        p >>= 1;
    }
    return ret;
}

void solve(int caseno)
{
    ll a, b, n, x, y, z, ans, left, COS, SIN;

    cin >> a >> b >> n;
    n++;

    x = (2*a*b) % MOD;
    y = ((b*b - a*a)%MOD + MOD)%MOD;
    z = (a*a + b*b)%MOD;

    Mat R(2, vector<ll>(2));
    Mat A(2, vector<ll>(1));

    COS = ((-y*invmod(z)) %MOD + MOD) %MOD;
    SIN = (x*invmod(z)) % MOD;

    R[0][0] = COS;  R[0][1] = MOD-SIN;
    R[1][0] = SIN;  R[1][1] = COS;

    A[0][0] = MOD-1;
    A[1][0] = 0;

    R = Pow(R, n);
    A = Mul(R, A);

    cout << A[0][0] << "\n";
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
