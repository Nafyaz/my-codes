#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, m, sum, k;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        sum = n*(n+1)/2;
        k = n/2/m;

        sum -= 2*(k*m*(m+1)/2 + m*m*(k-1)*k);

        cout << "Case " << ++caseno << ": " << sum << "\n";
    }
}
