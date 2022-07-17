#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll G, L;

    cin >> G >> L;

    if(L%G != 0)
        cout << "-1\n";
    else
        cout << G << " " << L << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
