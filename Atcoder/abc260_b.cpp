#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1003

pair<pii, int> arr[MAXN];

bool cmp1(pair<pii, int> a, pair<pii, int> b)
{    
    if(a.ff.ff != b.ff.ff)
        return a.ff.ff > b.ff.ff;
    return a.ss < b.ss;
}

bool cmp2(pair<pii, int> a, pair<pii, int> b)
{   
    if(a.ff.ss != b.ff.ss) 
        return a.ff.ss > b.ff.ss;
    return a.ss < b.ss;
}

bool cmp3(pair<pii, int> a, pair<pii, int> b)
{    
    if(a.ff.ff+a.ff.ss != b.ff.ff+b.ff.ss)
        return a.ff.ff+a.ff.ss > b.ff.ff+b.ff.ss;
    return a.ss < b.ss;
}

void solve(int caseno)
{
    int n, x, y, z, i;
    vector<int> ans;

    cin >> n >> x >> y >> z;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i].ff.ff;
        arr[i].ss = i+1;
    }
    for(i = 0; i < n; i++)
        cin >> arr[i].ff.ss;

    sort(arr, arr+n, cmp1);
    for(i = 0; i < x; i++)
        ans.push_back(arr[i].ss);

    sort(arr+x, arr+n, cmp2);
    for(i = x; i < x+y; i++)
        ans.push_back(arr[i].ss);

    sort(arr+x+y, arr+n, cmp3);    
    for(i = x+y; i < x+y+z; i++)
        ans.push_back(arr[i].ss);

    sort(ans.begin(), ans.end());
    for(auto u : ans)
        cout << u << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}