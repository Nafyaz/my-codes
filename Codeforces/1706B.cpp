#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

vector<int> pos[MAXN];
int height[MAXN];

void solve(int caseno)
{
    int n, i, j, c, ans, newOdd, newEven;

    cin >> n;

    for(i = 1; i <= n; i++)
        pos[i].clear();

    for(i = 1; i <= n; i++)
    {
        cin >> c;
        pos[c].push_back(i);
    }

    for(i = 1; i <= n; i++)
    {
        if(pos[i].size() <= 1)
        {
            cout << pos[i].size() << " ";
            continue;
        }

        height[0] = ans = 1;

        newOdd = newEven = -1;
        if(pos[i][0]%2)
            newOdd = 0;
        else
            newEven = 0;

        for(j = 1; j < pos[i].size(); j++)
        {
            if(pos[i][j]%2)
            {
                if(newEven == -1)
                    height[j] = 1;
                else
                    height[j] = height[newEven] + 1;
            }
            else
            {
                if(newOdd == -1)
                    height[j] = 1;
                else
                    height[j] = height[newOdd] + 1;
            }

            if(pos[i][j]%2)
                newOdd = j;
            else
                newEven = j;

            ans = max(ans, height[j]);
        }

        cout << ans << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

