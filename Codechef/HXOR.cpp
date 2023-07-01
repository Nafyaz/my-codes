#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll arr[MAXN];
deque<ll> dq[32];

void solve(int caseno)
{
    ll n, x, i, j;

    for(i = 0; i < 32; i++)
        dq[i].clear();

    cin >> n >> x;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        for(j = 0; j < 32; j++)
        {
            if(arr[i] & (1LL << j))
                dq[j].push_back(i);
        }
    }

    // for(i = 0; i < 32; i++)
    // {
    //     cout << i << ": ";
    //     for(auto u : dq[i])
    //         cout << u << " ";
    //     cout << "\n";
    // }

    for(i = 0; i+1 < n && x; i++)
    {
        for(j = 31; j >= 0 && x; j--)
        {
            if((arr[i] & (1LL << j)) == 0)
                continue;

            arr[i] ^= (1LL << j);
            dq[j].pop_front();

            if(dq[j].empty())
            {
                arr[n-1] ^= (1LL << j);
                dq[j].push_back(n-1);
                x--;
            }
            else
            {
                arr[dq[j].front()] ^= (1LL << j);
                dq[j].pop_front();
                x--;
            }
        }
    }

    if(x == 1 || (x%2 == 1 && n == 2))
    {
        arr[n-2] ^= 1;
        arr[n-1] ^= 1;
    }

    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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