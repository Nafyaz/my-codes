#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, ans1, ans2;

    cin >> n;

    ans1 = ans2 = INT_MAX;

    ans1 = n/3;
    if(n%3 == 1)
        ans1 += 2;
    else if(n%3 == 2)
        ans1 += 1;

    if(n >= 3)
    {
        ans2 = n/3-1;

        n -= ans2*3;

        if(n == 1 || n == 4 || n == 5)
            ans2 += 2;
        if(n == 2 || n == 3)
            ans2 += 1;
    }

    cout << min(ans1, ans2) << "\n";
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