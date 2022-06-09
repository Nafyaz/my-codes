#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

string vals[7] = {"1869", "1896", "1986", "1698", "6198", "1689", "1968"};

void solve(ll caseno)
{
    ll i, cnt[10] = {0}, p, total;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++)
        cnt[s[i] - '0']++;

    p = 10000%7;
    total = 0;
    stack<ll> stk;
    for(i = 9; i > 0; i--)
    {
        while(cnt[i] > (i == 1 || i == 6 || i == 8 || i == 9))
        {
            stk.push(i);
            cnt[i]--;

            total = (total + p*i)%7;
            p = (p*10)%7;
        }
    }

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

    cout << vals[total];

    while(cnt[0])
    {
        cout << 0;
        cnt[0]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}