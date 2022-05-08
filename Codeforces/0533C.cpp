
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll xP, yP, xV, yV;

    cin >> xP >> yP >> xV >> yV;

    if(xP + yP <= max(xV, yV))
        cout << "Polycarp";
    else if(xP <= xV && yP <= yV)
        cout << "Polycarp";
    else
        cout << "Vasiliy";
}