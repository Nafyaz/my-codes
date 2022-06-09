#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

ll a[200005];
ll cSum[200005], nextBig[200005], prevBig[200005];
ll sparse[200005][20];

void solve(ll caseno)
{
    ll n, i, lastPos;
    bool flag;

    cin >> n;

    flag = 1;
    lastPos = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];  
        cSum[i] = cSum[i-1] + a[i];      
 
        if(a[i] > 0)
        {
            if(lastPos == -1)
                lastPos = i;
            else
            {
                if(cSum[i] - cSum[lastPos-1] > max(a[lastPos], a[i]))
                    flag = 0;
 
                lastPos = i;
            }
        }
    }
    
    if(!flag)
    {
        cout << "NO\n";
        return;
    }

    // show(flag);
    
    stack<ll> stk;
    for(i = 1; i <= n; i++)
    {
        while(!stk.empty() && a[stk.top()] < a[i])
            stk.pop();

        if(!stk.empty())
            prevBig[i] = stk.top();
        else
            prevBig[i] = i;

        stk.push(i);
    }

    // show(stk.size());
    // cout << "\n";

    while(!stk.empty())
        stk.pop();

    for(i = n; i >= 1; i--)
    {
        while(!stk.empty() && a[stk.top()] < a[i])
            stk.pop();

        if(!stk.empty())
            nextBig[i] = stk.top();
        else
            nextBig[i] = i;
        
        stk.push(i);
    }

    // for(i = 1; i <= n; i++)
    // {
    //     show(a[i]);
    //     show(prevBig[i]);
    //     show(nextBig[i]);
    //     cout << "\n";
    // }

    for(i = 1; i <= n; i++)
    {
        if(a[i] > 0 && (cSum[i] - cSum[prevBig[i]-1] > a[i] || cSum[nextBig[i] + 1] - cSum[i-1] > a[i]))
            flag = 0;
        
        // show(i);
        // show(flag);
        // cout << "\n";
    }

    cout << (flag? "YES\n" : "NO\n") ;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}