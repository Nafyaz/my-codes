#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, i, low, high, mid, fI, from, to, dist, ans;
    string s;
    vector<int> packmen, food;

    cin >> n >> s;

    for(i = 0; i < n; i++)
    {
        if(s[i] == '*')
            food.push_back(i);
        if(s[i] == 'P')
            packmen.push_back(i);
    }

    low = 1;
    high = 3*n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        fI = 0;

        for(auto p : packmen)
        {
            from = to = p;

            while(fI < food.size())
            {
                from = min(from, food[fI]);
                to = max(to, food[fI]);

                dist = min(to-p+to-from, p-from+to-from);

                if(dist > mid)
                    break;

                fI++;
            }
        }

        if(fI == food.size())
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

