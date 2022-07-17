#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r, i;

    cin >> n >> l >> r;

    vector<int> ans;
    for(i = 1; i <= n; i++)
    {
        if((l-1)/i == r/i)
        {
            cout << "NO\n";
            return;
        }

        ans.push_back(r/i*i);
    }

    cout << "YES\n";
    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
