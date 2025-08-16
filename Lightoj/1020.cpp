#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool willFirstPlayerWin(int n)
{
    if (n%3 == 0)
        return false;
    return true;
}

void solve(int caseno)
{
    int n;
    string name;

    cin >> n >> name;

    if (name == "Alice")
        cout << "Case " << caseno << ": " << (willFirstPlayerWin(n-1)? "Alice" : "Bob") << "\n";
    else
        cout << "Case " << caseno << ": " << (willFirstPlayerWin(n)? "Bob" : "Alice") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}