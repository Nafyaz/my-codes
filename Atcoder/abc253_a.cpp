#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;

    cin >> a >> b >> c;

    if(a <= b && b <= c || a >= b && b >= c)
        cout << "Yes";
    else
        cout << "No";
}