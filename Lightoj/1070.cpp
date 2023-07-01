#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long
typedef vector<vector<llu>> Mat;

Mat mul(Mat A, Mat B)
{
    Mat ret(A.size(), vector<llu>(B[0].size()));
    llu i, j, k;

    for(i = 0; i < ret.size(); i++)
    {
        for(j = 0; j < ret[0].size(); j++)
        {
            for(k = 0; k < A[0].size(); k++)
                ret[i][j] += A[i][k] * B[k][j];
        }
    }

    return ret;
}

Mat power(Mat A, llu p)
{
    Mat ret(A.size(), vector<llu>(A[0].size()));
    llu i, j, k;

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

    Mat A(1, vector<llu>(2)), B(2, vector<llu>(2));
    llu T, caseno = 0, p, q, n;

    cin >> T;

    while(T--)
    {
        cin >> p >> q >> n;

        A[0][0] = 2;
        A[0][1] = p;

        B[0][1] = -q;
        B[1][0] = 1;
        B[1][1] = p;

        cout << "Case " << ++caseno << ": " << mul(A, power(B, n))[0][0] << "\n";
    }
}