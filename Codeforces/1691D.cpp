#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

ll a[200005];
ll cSum[200005];
vector<ll> positive;

void solve(ll caseno)
{
    ll n, i, lastPos, low, high, mid, leftMost, rightMost;
    bool flag = 1;

    cin >> n;

    lastPos = -1;
    positive.clear();
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];  
        cSum[i] = cSum[i-1] + a[i];      

        if(a[i] > 0)
        {
            positive.push_back(i);
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

    if(positive.size() <= 1)
    {
        cout << "YES\n";
        return;
    }

    for(i = 0; i+1 < positive.size(); i++)
    {
        if(a[positive[i]] > cSum[positive[i+1]] - cSum[positive[i]-1] || a[positive[i+1]] > cSum[positive[i+1]] - cSum[positive[i]-1])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}