#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10007

typedef vector<vector<ll>> Mat;

Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<ll>(B[0].size()));
    ll i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
            {
                ret[i][j] += A[i][k] * B[k][j];
                ret[i][j] %= mod;
            }
        }
    }

    return ret;
}

Mat power(Mat A, ll p)
{
    Mat ret(A.size(), vector<ll>(A[0].size()));
    ll i, j, k;

    for(i = 0; i < ret.size(); i++)
        ret[i][i] = 1;

    if(!p)
        return ret;
    
    ret = power(A, p/2);
    ret = mul(ret, ret);

    if(p%2)
        ret = mul(A, ret);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, a, b, c;
    Mat A(1, vector<ll>(4));
    Mat B(4, vector<ll>(4));

    A[0][0] = 0;    A[0][1] = 0;    A[0][2] = 0;    A[0][3] = 1;

    cin >> T;

    while(T--)
    {
        cin >> n >> a >> b >> c;

        cout << "Case " << ++caseno << ": ";

        if(n <= 2)
        {
            cout << A[0][n] << "\n";
            continue;
        }

        B[0][0] = 0;    B[0][1] = 0;    B[0][2] = b;    B[0][3] = 0;
        B[1][0] = 1;    B[1][1] = 0;    B[1][2] = 0;    B[1][3] = 0;
        B[2][0] = 0;    B[2][1] = 1;    B[2][2] = a;    B[2][3] = 0;
        B[3][0] = 0;    B[3][1] = 0;    B[3][2] = c;    B[3][3] = 1;

        cout << mul(A, power(B, n))[0][0] << "\n";
    }
}