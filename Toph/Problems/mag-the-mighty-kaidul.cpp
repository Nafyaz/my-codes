#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1717171769

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
                ret[i][j] = (ret[i][j] + (A[i][k]*B[k][j])%mod)%mod;
        }
    }

    return ret;
}

Mat power(Mat A, ll p)
{
    Mat ret(A.size(), vector<ll>(A[0].size()));

    for(ll i = 0; i < ret.size(); i++)
        ret[i][i] = 1;

    while(p)
    {
        if(p&1)
            ret = mul(ret, A);
        A = mul(A, A);
        p >>= 1;
    }
    return ret;
}

void solve()
{
    ll L, N, i, j, sum = 0;

    cin >> L >> N;
    
    Mat A(N, vector<ll>(N));

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            cin >> A[i][j];
    }

    A = power(A, L-1);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            sum = (sum + A[i][j]) % mod;
    }

    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}