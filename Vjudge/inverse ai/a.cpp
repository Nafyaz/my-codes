#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1003

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k, x, y;
    string s, ans;

    cin >> n >> l >> k;
    cin >> s;

    sort(s.begin(), s.end());

    x = k + l - 1;
    y = k*l;
    for (int i = 0; i < n; i++)
    {
        ans = "";
        if (i < k)
        {
            ans.push_back(s[i]);
            for(int j = 1; j < l; j++)
            {
                if (i == k-1)
                {
                    ans.push_back(s[k+j-1]);
                }
                else
                {
                    ans.push_back(s[x]);
                    x++;
                }
            }
        }
        else
        {
            for (int j = 0; j < l; j++)
            {
                ans.push_back(s[y]);
                y++;
            }
        }

        cout << ans << "\n";
    }
}