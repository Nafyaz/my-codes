#include<bits/stdc++.h>
using namespace std;
#define ll long long

void call(ll n)
{
    if(n == 1)
    {
        cout << "1 ";
        return;
    }

    call(n-1);
    cout << n << " ";
    call(n-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;

    call(n);
}
