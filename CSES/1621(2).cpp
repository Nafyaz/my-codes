#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, x;
    unordered_set<int> st;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
    }

    cout << st.size() << "\n";
}