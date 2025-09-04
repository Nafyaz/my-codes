#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, x, p;

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        st.insert({p, i});
    }

    // for (auto &u : st)
    // {
    //     cout << u.first << " " << u.second << "\n";
    // }
    // cout << "\n";

    int rem, ans = 0;
    while (1)
    {
        rem = x;
        ans++;

        auto it = --st.lower_bound({rem+1, -1});
        rem -= it->first;
        st.erase(it);
        if (st.empty())
            break;

        it = st.lower_bound({rem+1, -1});
        if (it == st.begin())
            continue;
        else
            --it;

        rem -= it->first;
        st.erase(it);
        if (st.empty())
            break;
    }

    cout << ans << "\n";
}