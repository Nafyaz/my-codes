#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<vector<ll>> Mat;

ll mod;

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

    ll i;
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

    ll T, caseno = 0, a, b, n, m;
    Mat A(1, vector<ll>(2));
    Mat B(2, vector<ll>(2));

    cin >> T;

    while(T--)
    {
        cin >> a >> b >> n >> m;

        mod = 1;
        while(m--)
            mod *= 10;

        A[0][0] = a;    A[0][1] = b;

        B[0][0] = 0;    B[0][1] = 1;
        B[1][0] = 1;    B[1][1] = 1;

        cout << "Case " << ++caseno << ": " << mul(A, power(B, n))[0][0] << "\n";
    }
}