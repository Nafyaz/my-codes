#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, i, ans, temp;
    ll k[MAXN];
    stack<ll> stk;

    cin >> n;

    k[0] = -1;
    stk.push(0);

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> k[i];

        while(k[stk.top()] >= k[i])        
        {
            temp = stk.top();
            stk.pop();   

            ans = max(ans, (i - stk.top() - 1)*k[temp]);
        }   

        stk.push(i);
    }

    while(k[stk.top()] >= 0)        
    {
        temp = stk.top();
        stk.pop();   

        ans = max(ans, (i - stk.top() - 1)*k[temp]);
    }   

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

/*
1
1
*/