#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll x, y;

    cin >> x >> y;

    if((x+y) % 2)
    {
        cout << "-1 -1\n";
        return;
    }

    for(ll cx = 0; cx <= (x+y)/2; cx++)
    {
        ll cy = (x+y)/2 - cx;

        if(abs(x-cx) + abs(y-cy) == (x+y)/2)
        {
            cout << cx << " " << cy << "\n";
            return;
        }
    }

    cout << "-1 -1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}