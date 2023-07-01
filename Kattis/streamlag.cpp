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

bool found[1003];

void solve(int caseno)
{
    ll n, t, i, j, currPacket, currTime;

    cin >> n;

    currPacket = currTime = 1;
    for(j = 0; j < n; j++)
    {
        cin >> t >> i;
        found[i] = 1;

        currTime = max(currTime, t);

        while(found[currPacket])
        {
            currPacket++;
            currTime++;
        }

//        show(currPacket);
//        show(currTime);
//        cout << "\n";
    }

    cout << currTime - n - 1<< "\n";
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
