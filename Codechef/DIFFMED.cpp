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
    int n, i;

    cin >> n;

    stack<int> ans;
    stack<int> left;
    queue<int> right;

    if(n%2)
    {
        ans.push((n+1)/2);

        for(i = 1; i < (n+1)/2; i++)
            left.push(i);

        for(i = (n+1)/2+1; i <= n; i++)
            right.push(i);
    }
    else
    {
        for(i = 1; i <= n/2; i++)
            left.push(i);

        for(i = n/2+1; i <= n; i++)
            right.push(i);
    }

    while(!left.empty() && !right.empty())
    {
        ans.push(left.top());
        left.pop();

        ans.push(right.front());
        right.pop();
    }

    while(!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
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

