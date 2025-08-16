#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 200005

ll pref[2][MAXN];

void solve(int caseno)
{
    ll n, x, i, t, a, bit;

    cin >> n >> x;

    pref[1][0] = INT_MAX;

    for(i = 1; i <= n; i++)
    {
        cin >> t >> a;

        if(t == 1)
        {
            pref[0][i] = pref[0][i-1] & a;
            pref[1][i] = pref[1][i-1] & a;
        }
        else if(t == 2)
        {
            pref[0][i] = pref[0][i-1] | a;
            pref[1][i] = pref[1][i-1] | a;
        }
        else
        {
            pref[0][i] = pref[0][i-1] ^ a;
            pref[1][i] = pref[1][i-1] ^ a;
        }

//        show(pref[0][1]);

//        cout << "pref:\n";
//        cout << (pref[0][1] & 1) << " " << (pref[0][1] & 2) << "\n";
//        cout << (pref[1][1] & 1) << " " << (pref[1][1] & 2) << "\n";
    }


    for(i = 1; i <= n; i++)
    {
        for(bit = 1; bit < (1LL << 32); bit *= 2)
        {
            if(x&bit)
            {
                x ^= bit;
                x |= pref[1][i]&bit;
            }
            else
                x |= pref[0][i]&bit;
        }

        cout << x << "\n";
    }
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


