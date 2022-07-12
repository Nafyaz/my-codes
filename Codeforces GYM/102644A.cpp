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

typedef vector<vector<double>> Mat;

Mat Mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<double>(B[0].size()));
    ll i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] = (ret[i][j] + (A[i][k]*B[k][j]));
        }
    }

    return ret;
}

Mat Pow(Mat A, ll p)
{
    Mat ret(A.size(), vector<double>(A[0].size()));

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
    int n;
    double p;

    cin >> n >> p;

    Mat A(2, vector<double>(1));
    A[0][0] = 1;
    A[1][0] = 0;

    Mat B(2, vector<double>(2));
    B[0][0] = 1-p;  B[0][1] = p;
    B[1][0] = p;    B[1][1] = 1-p;

    A = Mul(Pow(B, n), A);

    cout << fixed << setprecision(10) << A[0][0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}