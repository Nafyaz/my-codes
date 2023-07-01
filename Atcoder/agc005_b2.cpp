#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

LL a[MAXN], l[MAXN], r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, ans;
    stack<LL> left, right;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        while(!left.empty() && a[left.top()] > a[i])
            left.pop();

        if(!left.empty())
            l[i] = left.top() + 1;
        else
            l[i] = 0;

        left.push(i);
    }

    for(i = n-1; i >= 0; i--)
    {
        while(!right.empty() && a[right.top()] > a[i])
            right.pop();

        if(!right.empty())
            r[i] = right.top()-1;
        else
            r[i] = n-1;

        right.push(i);
    }

    // for(i = 0; i < 3; i++)
    //     cout << l[i] << " ";
    // cout << "\n";
    // for(i = 0; i < 3; i++)
    //     cout << r[i] << " ";
    // cout << "\n";
    
    ans = 0;
    for(i = 0; i < n; i++)
        ans += a[i]*(i-l[i]+1)*(r[i]-i+1);
    
    cout << ans << "\n";
}