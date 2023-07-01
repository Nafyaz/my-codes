#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

vector<ll> ones;    

ll getGroups(ll x)
{
    ll i, j, sum, avg, cost1, cost2, ret = 0;
    for(i = 0; i < ones.size(); i += x)
    {
        cost1 = cost2 = 0;
        for(j = i; j < i+x; j++)
        {
            cost1 += abs(ones[i+x/2] - ones[j]);
            cost2 += abs(ones[i+x/2+1] - ones[j]);
        }

        ret += min(cost1, cost2);
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, i, a, sum, ans;

    cin >> n;

    ones.clear();
    sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(a)
        {
            sum++;
            ones.push_back(i);
        }
    }

    if(sum < 2)
    {
        cout << "-1\n";
        return;
    }

    ans = getGroups(sum);
    for(i = 2; i*i <= sum; i++)
    {
        if(sum%i == 0)
        {
            ans = min(ans, getGroups(i));
            ans = min(ans, getGroups(sum/i));
        }   
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