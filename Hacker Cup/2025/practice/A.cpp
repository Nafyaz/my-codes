#include <bits/stdc++.h>
using namespace std;

#define MAXN 50000007

int B[MAXN];
map<int, vector<int>> A;

void solve(int caseno)
{
    int n;
    cin >> n;

    A.clear();
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[a].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<pair<int, int>> ans;

    for (auto &[k, v] : A)
    {
        for (auto a_i : v)
        {
            if (B[a_i] < k || A.find(B[a_i]) == A.end())
            {
                cout << "Case #" << caseno << ": -1\n";
                return;
            }

            if (a_i != A[B[a_i]].front())
            {
                ans.push_back({a_i, A[B[a_i]].front()});
            }
        }
    }

    cout << "Case #" << caseno << ": " << ans.size() << "\n";

    for (auto [i1, i2] : ans)
    {
        cout << i1 + 1 << " " << i2 + 1 << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    freopen("practice-A_input.txt", "r", stdin);
    freopen("practice-A_output.txt", "w", stdout);

    int T, caseno = 0;
    cin >> T;

    while (T--)
    {
        solve(++caseno);
    }
}