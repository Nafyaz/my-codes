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

int n;
long long a[12], sum[12];
unordered_set<long long> st;

void func(int pos)
{
    if (pos == n)
    {
        long long Xor = 0;
        for (int i = 0; i < n; i++)
            Xor ^= sum[i];

        st.insert(Xor);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        sum[i] += a[pos];
        func(pos + 1);
        sum[i] -= a[pos];

        if (sum[i] == 0)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    func(0);

    cout << st.size() << "\n";
}