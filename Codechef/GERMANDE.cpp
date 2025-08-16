#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool d[1000006];
ll Tree[4000006];

void build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        Tree[node] = d[bg];
        return;
    }

    ll left = 2*node + 1;
    ll right = 2*node + 2;
    ll mid = (bg + ed)/2;

    build(left, bg, mid);
    build(right, mid+1, ed);

    Tree[node] = Tree[left] + Tree[right];
}

ll query(ll node, ll bg, ll ed, ll l, ll r)
{
    if(l <= bg && ed <= r)
        return Tree[node];
    
    if(bg > r || ed < l)
        return 0;
    
    ll left = 2*node + 1;
    ll right = 2*node + 2;
    ll mid = (bg + ed)/2;

    ll p1 = query(left, bg, mid, l, r);
    ll p2 = query(right, mid+1, ed, l, r);

    return p1+p2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, o1, o2, n, i, j, winState, winDist, ans;

    cin >> T;

    while(T--)
    {
        cin >> o1 >> o2;
        n = o1 * o2;

        for(i = 0; i < n; i++)
            cin >> d[i];

        build(0, 0, n-1);

        // for(i = 0; i <= 4; i++)
        //     cout << "i: " << Tree[i] << "\n";
        // cout << "\n";        

        ans = 0;
        for(i = 0; i < o2; i++)
        {
            winState = 0;
            for(j = i; j+o2-1 < n; j += o2)
            {                
                winDist = query(0, 0, n-1, j, min(j+o2-1, n-1));

                if(2*winDist > o2)
                    winState ++;
                
                // cout << "j: " << j << "; winState: " << winState << "; winDist: " << winDist << "\n";
            }

            winDist = query(0, 0, n-1, j, n-1) + query(0, 0, n-1, 0, i-1);
            if(2*winDist > o2)
                winState ++;

            // cout << "winState: " << winState << "\n";
            if(2*winState > o1)
            {
                ans = 1;
                break;
            }
        }

        cout << ans << "\n";
    }
}