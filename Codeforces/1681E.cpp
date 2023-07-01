#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define show(x) cout << #x << ": " << x << "; "

ll n, LOG[100005], POWER[20];
pair<ll, ll> door[100005][2];
ll dp[100005][20][2][2];
map<pair<pair<ll, bool>, pair<ll, bool>>, ll> queryDP;

ll manhattan(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

ll door2door(pair<ll, ll> d1, pair<ll, ll> d2, bool right)
{
    if(right)
        d1.y++;
    else
        d1.x++;
    
    return 1 + manhattan(d1, d2);
}

ll query(ll bgL, bool d1, ll edL, bool d2)
{
    if(queryDP.find({{bgL, d1}, {edL, d2}}) != queryDP.end())
        return queryDP[{{bgL, d1}, {edL, d2}}];

    if(bgL == edL)
        return queryDP[{{bgL, d1}, {edL, d2}}] = manhattan(door[bgL][d1], door[edL][d2]);

    ll dist = LOG[edL - bgL];
    if(POWER[dist] == edL - bgL)
        return queryDP[{{bgL, d1}, {edL, d2}}] = dp[bgL][dist][d1][d2];

    ll ret = LLONG_MAX;
    ret = min(ret, dp[bgL][dist][d1][0] + query(bgL + POWER[dist], 0, edL, d2));
    ret = min(ret, dp[bgL][dist][d1][1] + query(bgL + POWER[dist], 1, edL, d2));

    return queryDP[{{bgL, d1}, {edL, d2}}] = ret;
}

void solve()
{
    ll i, j, m, ans, bgL, edL;
    pair<ll, ll> bg, ed;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < 2; j++)
            cin >> door[i][j].x >> door[i][j].y;
    }
    // door[n][0] = door[n-1][0];
    // door[n][0].x++;

    // door[n][1] = door[n-1][1];
    // door[n][1].y++;

    for(i = 1; i+1 < n; i++)
    {
        dp[i][0][0][0] = door2door(door[i][0], door[i+1][0], 0);
        dp[i][0][0][1] = door2door(door[i][0], door[i+1][1], 0);
        dp[i][0][1][0] = door2door(door[i][1], door[i+1][0], 1);
        dp[i][0][1][1] = door2door(door[i][1], door[i+1][1], 1);
    }


    for(j = 1; j < 20; j++)
    {
        for(i = 1; i + (1LL << j) < n; i++)
        {
            dp[i][j][0][0] = LLONG_MAX;
            dp[i][j][0][0] = min(dp[i][j][0][0], dp[i][j-1][0][0] + dp[i+POWER[j-1]][j-1][0][0]);
            dp[i][j][0][0] = min(dp[i][j][0][0], dp[i][j-1][0][0] + (door2door(door[i+POWER[j-1] - 1][0], door[i+POWER[j-1]][1], 0) - 1) + dp[i+POWER[j-1]][j-1][1][0]);
            dp[i][j][0][0] = min(dp[i][j][0][0], dp[i][j-1][0][1] + (door2door(door[i+POWER[j-1] - 1][1], door[i+POWER[j-1]][0], 1) - 1) + dp[i+POWER[j-1]][j-1][0][0]);
            dp[i][j][0][0] = min(dp[i][j][0][0], dp[i][j-1][0][1] + dp[i+POWER[j-1]][j-1][1][0]);

            dp[i][j][0][1] = LLONG_MAX;
            dp[i][j][0][1] = min(dp[i][j][0][1], dp[i][j-1][0][0] + dp[i+POWER[j-1]][j-1][0][1]);
            dp[i][j][0][1] = min(dp[i][j][0][1], dp[i][j-1][0][0] + (door2door(door[i+POWER[j-1] - 1][0], door[i+POWER[j-1]][1], 0) - 1) + dp[i+POWER[j-1]][j-1][1][1]);
            dp[i][j][0][1] = min(dp[i][j][0][1], dp[i][j-1][0][1] + (door2door(door[i+POWER[j-1] - 1][1], door[i+POWER[j-1]][0], 1) - 1) + dp[i+POWER[j-1]][j-1][0][1]);
            dp[i][j][0][1] = min(dp[i][j][0][1], dp[i][j-1][0][1] + dp[i+POWER[j-1]][j-1][1][1]);

            dp[i][j][1][0] = LLONG_MAX;
            dp[i][j][1][0] = min(dp[i][j][1][0], dp[i][j-1][1][0] + dp[i+POWER[j-1]][j-1][0][0]);
            dp[i][j][1][0] = min(dp[i][j][1][0], dp[i][j-1][1][0] + (door2door(door[i+POWER[j-1] - 1][0], door[i+POWER[j-1]][1], 0) - 1) + dp[i+POWER[j-1]][j-1][1][0]);
            dp[i][j][1][0] = min(dp[i][j][1][0], dp[i][j-1][1][1] + (door2door(door[i+POWER[j-1] - 1][1], door[i+POWER[j-1]][0], 1) - 1) + dp[i+POWER[j-1]][j-1][0][0]);
            dp[i][j][1][0] = min(dp[i][j][1][0], dp[i][j-1][1][1] + dp[i+POWER[j-1]][j-1][1][0]);

            dp[i][j][1][1] = LLONG_MAX;
            dp[i][j][1][1] = min(dp[i][j][1][1], dp[i][j-1][1][0] + dp[i+POWER[j-1]][j-1][0][1]);
            dp[i][j][1][1] = min(dp[i][j][1][1], dp[i][j-1][1][0] + (door2door(door[i+POWER[j-1] - 1][0], door[i+POWER[j-1]][1], 0) - 1) + dp[i+POWER[j-1]][j-1][1][1]);
            dp[i][j][1][1] = min(dp[i][j][1][1], dp[i][j-1][1][1] + (door2door(door[i+POWER[j-1] - 1][1], door[i+POWER[j-1]][0], 1) - 1) + dp[i+POWER[j-1]][j-1][0][1]);
            dp[i][j][1][1] = min(dp[i][j][1][1], dp[i][j-1][1][1] + dp[i+POWER[j-1]][j-1][1][1]);
        }
    }

    // cout << "1 to 3:" << endl;
    // cout << dp[1][1][0][0] << " " << dp[1][1][0][1] << "\n";
    // cout << dp[1][1][1][0] << " " << dp[1][1][1][1] << "\n";

    cin >> m;

    queryDP.clear();
    while(m--)
    {
        cin >> bg.x >> bg.y;
        cin >> ed.x >> ed.y;

        if(max(bg.x, bg.y) > max(ed.x, ed.y))
            swap(bg, ed);

        bgL = max(bg.x, bg.y);
        edL = max(ed.x, ed.y);

        // show(m);

        if(bgL == edL)
        {
            cout << manhattan(bg, ed) << "\n";
            continue;
        }

        // cout << "1st: " << manhattan(bg, door[bgL][1]) << "\n";

        ans = LLONG_MAX;
        ans = min(ans, manhattan(bg, door[bgL][0]) + query(bgL, 0, edL-1, 0) + door2door(door[edL-1][0], ed, 0));
        ans = min(ans, manhattan(bg, door[bgL][0]) + query(bgL, 0, edL-1, 1) + door2door(door[edL-1][1], ed, 1));
        ans = min(ans, manhattan(bg, door[bgL][1]) + query(bgL, 1, edL-1, 0) + door2door(door[edL-1][0], ed, 0));
        ans = min(ans, manhattan(bg, door[bgL][1]) + query(bgL, 1, edL-1, 1) + door2door(door[edL-1][1], ed, 1));

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i;

    for(i = 2; i < 100005; i++)
        LOG[i] = LOG[i/2] + 1;

    POWER[0] = 1;
    for(i = 1; i < 20; i++)
        POWER[i] = POWER[i-1] * 2;

    T = 1;

    while(T--)
    {
        solve();
    }
}