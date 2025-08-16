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

int a[MAXN];

void solve(int caseno)
{
    int n, x, i = 0, mx = 0;
    bool mxTaken = false;

    string s;
    getline(cin, s);
    stringstream ss(s);

    while(ss >> x)
    {
        a[i] = x;
        i++;
    }

    n = i-1;
    for (i = 0; i <= n; i++)
    {
        if (mxTaken || a[i] != n)
            mx = max(mx, a[i]);
        else 
            mxTaken = true;
    }
    cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;
    string s;

    cin >> T;
    getline(cin, s);

    while(T--)
    {
        solve(++caseno);
    }
}