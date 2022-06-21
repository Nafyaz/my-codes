#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll n, i, j;
    bool flag;

    cin >> n;

    i = 1; j = n;

    flag = 0;
    while(i <= j)
    {
        cout << i*j << " ";

        if(!flag)
        {
            i++;
            flag = 1;
        }
        else
        {
            j--;
            flag = 0;
        }
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