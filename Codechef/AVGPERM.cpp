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
    int n, i;
    deque<int> dq;

    cin >> n;

    for(i = 1; i <= n-4; i++)
        dq.push_back(i);

    if(n-2 >= 1)
        dq.push_back(n-2);
    if(n >= 1)
        dq.push_back(n);
    if(n-3 >= 1)
        dq.push_front(n-3);
    if(n-1 >= 1)
        dq.push_front(n-1);

    for(auto u : dq)
        cout << u << " ";
    cout << "\n";
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
