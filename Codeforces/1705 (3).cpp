#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int arr[MAXN];
int c[MAXN];
set<int> z{-1}, o{-1}, no{-1};

void Add(int x, int t)
{
    z.erase(x);
    o.erase(x);
    no.erase(x);

    c[x] += t;

    if (c[x] == -2) 
    {
        c[x] = 0;
        Add(x + 1, -1);
    }
    else if (c[x] == 2) 
    {
        c[x] = 0;
        Add(x + 1, 1);
    }
    
    if (c[x] == 0)
        z.insert(x);
    else if (c[x] == 1) 
        o.insert(x);
    else     
        no.insert(x);    
}

void solve(int caseno)
{
    int n, q, i, x, v, ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    for(i = 0; i < n; i++)
        z.insert(i);

    for(i = 0; i < n; i++)
        Add(a[i], 1);

    while(q--)
    {
        cin >> x >> v;

        x--;
        Add(a[x], -1);
        Add(a[x] = v, 1);

        ans = *o.rbegin();
        ans = std::max(*std::next(o.rbegin()), *std::prev(z.lower_bound(ans))) + 1;
        
        if (*std::prev(o.lower_bound(ans)) < *std::prev(no.lower_bound(ans)))
            ans--;
        
        std::cout << ans << "\n";
    }
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