#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int arr[MAXN];

void solve(int caseno)
{
    int n, i, x, ans;
    deque<int> dq;

    cin >> n;

    ans = 0;
    for(i = 0; i < n; i++)
        cin >> arr[i];

    for(i = 0; i < n; i++)
    {
        // cout << i << ":\n";
        // for(auto u : dq)
        //     cout << u << " ";
        // cout << "\n";

        if(dq.empty())
            dq.push_back(arr[i]);
        
        else if(dq.size() == 4)
        {
            dq.clear();
            i--;
        }

        else
        {
            if(arr[i] <= dq.back())
            {
                ans += (4 - dq.size());
                dq.clear();
                i--;
            }
            else if(arr[i] - dq.back() <= 10)
                dq.push_back(arr[i]);
            else
            {
                dq.push_back(dq.back() + 10);
                ans++;
                i--;
            }
        }
    }

    if(dq.size() >= 1 && dq.size() < 4)
    {
        ans += (4 - dq.size());
        dq.clear();
    }

    cout << "Case #" << caseno << ": " << ans << "\n";
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