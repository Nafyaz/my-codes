#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, i, temp;
    vector<int> a, b;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    while(a.size() > 1)
    {
        for(auto u : a)
            cout << u << " ";
        cout << "\n";

        b.clear();
        for(i = 1; i < a.size(); i++)
        {
            if(a[i] != a[i-1])
                b.push_back(a[i] - a[i-1]);
        }

        sort(b.begin(), b.end());

        swap(a, b);
    }

    cout << a[0] << "\n";
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int T = 1;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
