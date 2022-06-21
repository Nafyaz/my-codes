#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

ll n;
bool mask[maxN];
deque<ll> dq;

bool call(ll pos)
{
    ll i;

    if(pos == n+1)
        return 1;
    
    for(i = 1; i <= n; i++)
    {
        if(!mask[i] && (pos&i) == 0)
        {
            // show(pos);
            // show(i);
            // cout << "\n";

            dq.push_back(i);    
            mask[i] = 1;

            if(call(pos + 1))
                return 1;

            dq.pop_back();
            mask[i] = 0;
        }
    }

    return 0;
}

void solve(ll caseno)
{
    ll i;

    cin >> n;

    if(n == 1)
    {
        cout << "1\n1\n";
        return;
    }

    if(n % 2)
    {
        cout << "-1\n";
        return;
    }

    call(1);

    for(i = 1; i <= n; i++)
        cout << i << " ";
    cout << "\n";

    while(!dq.empty())
    {
        cout << dq.front() << " ";
        mask[dq.front()] = 0;
        dq.pop_front();
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}