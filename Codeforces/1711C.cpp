#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll a[MAXN];

void solve(int caseno)
{
    ll n, m, k, i, mn;

    cin >> n >> m >> k;

    for(i = 0; i < k; i++)
        cin >> a[i];

    sort(a, a+k, greater<ll>());

    if(n%2 && m%2)
    {
        if(n < m)
            swap(n, m);

        if(a[0] < 3*m)
        {
            cout << "No\n";
            return;
        }

        a[0] -= 3*m;
        n -= 3;
    }

    if(n%2 == 0 && m%2 == 0 && n < m)
        swap(n, m);
    if(n%2 == 1 && m%2 == 0)
        swap(n, m);

//    show(n);
//    show(m);

    for(i = 0; i < k; i++)
        n -= min(n, a[i]/2/m*2);

    cout << (n == 0? "Yes\n" : "No\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

/*
1
4 6 3
12 9 8
*/
/*
1
5 3 2
9 6
*/
