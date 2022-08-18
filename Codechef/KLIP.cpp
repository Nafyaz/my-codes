#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

int pref[MAXN];

void solve(int caseno)
{
    int n, k, i;
    string s;

    cin >> n >> k >> s;

//    show(n);
//    show(k);
//    show(s);
//    cout << "\n";

    fill(pref, pref+n+1, 0);

    for(i = 0; i+k-1 < n; i++)
    {
        pref[i+1] += pref[i];

//        show(i);
//        show(pref[i+1]);
//        cout << "\n";

        if((pref[i+1] % 2 == 0 && s[i] == '1') || (pref[i+1]%2 == 1 && s[i] == '0'))
        {
//            cout << "lol\n";
            pref[i+1] ++;
            pref[i+1+k] --;
        }
        s[i] = '0';

//        show(pref[i+1]);
    }

    for(; i < n; i++)
    {
        pref[i+1] += pref[i];

        if(pref[i+1]%2 == 1)
        {
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
    }

    cout << s << "\n";
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

