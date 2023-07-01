#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool parity(ll N)
{
    ll sum = 0;

    while(N)
    {
        sum += N%10;
        N /= 10;
    }

    return (sum & 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, N;

    cin >> T;

    while(T--)
    {
        cin >> N;

        bool p = parity(N);
        while(parity(N) == p)
            N++;

        cout << N << "\n";
    }
}
