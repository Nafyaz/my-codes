#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

vector<ll> delicious;

void solve()
{
    ll L, R, ans;

    cin >> L >> R;

    if(L > 9876543210LL)
    {
        cout << "0\n";
        return;
    }

    R = min(R, 9876543210LL);

    cout << upper_bound(delicious.begin(), delicious.end(), R) - lower_bound(delicious.begin(), delicious.end(), L) << "\n";
}

void bfs()
{
    ll i, val, mask, cnt;
    queue<pair<ll, pair<ll, ll>>> q;

    for(i = 1; i <= 9; i++)
        q.push({i, {1LL << i, 1}});

    while(!q.empty())
    {
        val = q.front().ff;
        mask = q.front().ss.ff;
        cnt = q.front().ss.ss;

        q.pop();
        delicious.push_back(val);

        if(cnt == 10)
            continue;

        for(i = 0; i <= 9; i++)
        {
            if(!(mask & (1LL << i)))                        
                q.push({val*10+i, {mask | (1LL << i), cnt+1}});                   
        }     
    }
    
    sort(delicious.begin(), delicious.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    bfs();

    // for(ll i = 0; i < 20; i++)
    //     cout << delicious[i] << " ";
    // cout << "\n";

    cin >> T;

    while(T--)
    {
        solve();
    }
}