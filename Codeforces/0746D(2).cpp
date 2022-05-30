#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k, a, b, mn, mx, bCnt;
    char chA = 'G', chB = 'B';
    string ans;

    cin >> n >> k >> a >> b;

    if(a > b)
    {
        swap(a, b);
        swap(chA, chB);
    }

    bCnt = 0;
    while(a || b)
    {
        // cout << a << " " << b << "\n";
        if(b >= a && bCnt+1 <= k)
        {
            cout << chB;
            bCnt++;
            b--;
        }
        else if()
        {
            swap(a, b);
            swap(chA, chB);
            bCnt = 0;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}