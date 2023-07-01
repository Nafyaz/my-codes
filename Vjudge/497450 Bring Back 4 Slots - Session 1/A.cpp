#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000007
#define ff first
#define ss second

ll sod[N];
vector<pair<ll, ll>> amicable;

void allSOD()
{
    ll i, j;

    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j += i)
            sod[j] += i;
    }
}

void solve()
{
    ll a, b;

    cin >> a >> b;


}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T, i, s;

    allSOD();

    for(i = 1; i < N; i++)
        sod[i] -= i;

    // cout << sod[220];

    for(i = 1; i < N; i++)
    {
        s = sod[i];
        if(i < s && s < N && sod[s] == i)
            amicable.push_back({i, s});
    }

    cout << "{";
    for(i = 0; i < amicable.size(); i++)
        cout << amicable[i].ss << ",}"[i+1 == amicable.size()];

    // cin >> T;

    // while(T--)
    // {
    //     solve();
    // }
}