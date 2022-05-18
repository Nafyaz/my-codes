#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans[1000006];
bool isPrime(ll n)
{
    ll i;

    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i;

    for(i = 5; i < 1000006; i++)
    {
        ans[i] = ans[i-1];
        if(isPrime(i) && isPrime(i-2))
            ans[i]++;
    }

    cin >> T;

    while(T--)
    {
        cin >> n;
        cout << ans[n] << "\n";
    }
}