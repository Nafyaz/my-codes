#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    double a, b, ans1, ans2;
    int n;

    cin >> a >> b;

    if(a < b)
    {
        cout << "-1\n";
        return;
    }

    if(a == b)
    {
        cout << fixed << setprecision(12) << a << "\n";
        return;
    }
    
    n = (a-b)/2/b;
    ans1 = (a-b)/2/n;
    
    n = (a+b)/2/b;
    ans2 = (a+b)/2/n;

    cout << fixed << setprecision(12) << min(ans1, ans2) << "\n";
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

