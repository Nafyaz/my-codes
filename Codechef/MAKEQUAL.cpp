#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll a, b, c, aBit, bBit, cBit;

    cin >> a >> b >> c;
    
    for(; a || b || c; a /= 2, b /= 2, c /= 2)
    {
        if(a == b && b == c)
        {
            cout << "YES\n";
            return;
        }

        if(a + b + c == 1)
        {
            cout << "NO\n";
            return;
        }

        aBit = a%2;
        bBit = b%2;
        cBit = c%2;

        if(aBit == bBit && bBit == cBit)
        {
            cout << "NO\n";
            return;
        }

        if(aBit == 0 && bBit == 0 && cBit == 1)
            c += 1;
        else if(aBit == 0 && bBit == 1 && cBit == 0)
            b += 1;
        else if(aBit == 0 && bBit == 1 && cBit == 1)
            a += 1;
        else if(aBit == 1 && bBit == 0 && cBit == 0)
            a += 1;
        else if(aBit == 1 && bBit == 0 && cBit == 1)
            b += 1;
        else if(aBit == 1 && bBit == 1 && cBit == 0)
            c += 1;        
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}