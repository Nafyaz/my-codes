#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll n)
{
    ll i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return (n >= 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;

    cin >> n;

    if(isPrime(n-2))
        cout << "2 " << n-2;
    else
        cout << "-1\n";
}