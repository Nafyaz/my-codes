#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

string ans[MAXN];
int cons[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k, st, ed, i, x;
    string s;

    cin >> n >> l >> k;
    cin >> s;

    sort(s.begin(), s.end());

    for(i = 0; i < s.size(); i++)
    {
        if (i == 0 || s[i] != s[i-1])
            cons[i] = 1;
        else
            cons[i] = cons[i-1]+1;
    }

    // cout << s << "\n";

    x = 0;
    st = 0;
    ed = k-1;
    for(int len = 0; len < l && st < ed; len++)
    {
        for(i = st; i <= ed; i++)
        {
            ans[i].push_back(s[x]);
            x++;
        }

        st = max(st, ed - cons[x-1] + 1);

        // for(i = 0; i < n; i++)
        //     cout << ans[i] << "\n";
        // show(s[x-1]);
        // show(st);
        // cout << "----------\n\n";
    }

    while(ans[k-1].size() < l)
    {
        ans[k-1].push_back(s[x]);
        x++;
    }

    for (i = 0; i < n; i++)
    {
        while(ans[i].size() < l)
        {
            ans[i].push_back(s[x]);
            x++;
        }

        cout << ans[i] << "\n";
    }
}