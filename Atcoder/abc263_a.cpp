#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int a[5];

    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    sort(a, a+5);

    if(a[0] == a[1] && a[1] == a[2] && a[3] == a[4])
        cout << "Yes\n";
    else if(a[0] == a[1] && a[2] == a[3] && a[3] == a[4])
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
