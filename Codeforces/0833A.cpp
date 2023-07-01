#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000006
map<ll, ll> mp;

void findCubes()
{
    ll i;
    for(i = 0; i <= N; i++)
        mp[i*i*i] = i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    findCubes();

    ll n, i, a, b;

    cin >> n;

    while(n--)
    {
        cin >> a >> b;

        if(mp.find(a*b) != mp.end() && a%mp[a*b] == 0 && b%mp[a*b] == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
