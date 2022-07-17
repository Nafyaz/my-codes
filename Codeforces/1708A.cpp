#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, i, a, a1;
    bool flag = 1;

    cin >> n;

    cin >> a1;
    for(i = 2; i <= n; i++)
    {
        cin >> a;
        if(a%a1 != 0)
            flag = 0;
    }

    cout << (flag? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
