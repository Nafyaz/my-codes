#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100004

#define base 31

string a, b;
ll p[MAXN];
ll hashA[MAXN], hashB[MAXN];

ll calc(ll len)
{
    ll i, x, y, ret = 0;

    x = hashA[len];
    for(i = 1; i + len - 1 <= b.size(); i ++)
    {
        y = ((hashB[i + len - 1] - hashB[i-1] * p[len]) % MOD + MOD) % MOD;

        ret += (x == y);
    }

    return ret;
}

void solve(ll caseno)
{
    ll i, k, x, y, low, high, mid, ans;

    cin >> k >> a >> b;

    for(i = 1; i <= a.size(); i++)
    {
        hashA[i] = (hashA[i-1] * base) % MOD;
        hashA[i] = (hashA[i] + a[i-1] - 'a' + 1) % MOD;
    }

    for(i = 1; i <= b.size(); i++)
    {
        hashB[i] = (hashB[i-1] * base) % MOD;
        hashB[i] = (hashB[i] + b[i-1] - 'a' + 1) % MOD;
    }

    vector<ll> prefSuf;
    for(i = 1; i <= a.size(); i++)
    {
        x = hashA[i];
        y = ((hashA[a.size()] - hashA[a.size() - i] * p[i]) % MOD + MOD) % MOD;

        if(x == y)
            prefSuf.push_back(i);
    }

    if(prefSuf.empty())
    {
        cout << "No Plagiarism\n";
        return;
    }

    // for(auto u : prefSuf)
    //     cout << u << " ";
    // cout << "\n";
    // show(calc(3));
    // cout << "\n";

    low = 0;
    high = prefSuf.size() - 1;
    ans = -1;

    while(low <= high)
    {        
        mid = (low + high) / 2;

        if(calc(prefSuf[mid]) >= k)
        {
            ans = prefSuf[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    if(ans == -1)
        cout << "No Plagiarism\n";
    else
        cout << a.substr(0, ans) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0, i;

    p[0] = 1;
    for(i = 1; i < MAXN; i++)
        p[i] = (p[i-1] * base) % MOD;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}