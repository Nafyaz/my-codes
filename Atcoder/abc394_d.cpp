#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    map<char, char> mp;
    mp[')'] = '(';
    mp[']'] = '[';
    mp['>'] = '<';

    stack<char> stk;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<')
            stk.push(s[i]);
        else if (!stk.empty() && stk.top() == mp[s[i]])
        {
            stk.pop();
        }
        else
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << (stk.empty() ? "Yes\n" : "No\n");
}