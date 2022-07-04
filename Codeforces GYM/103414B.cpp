#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll arr[MAXN], pref[MAXN];
set<pll> st;

void solve(ll caseno)
{
    ll n, left, right, s, l, r, i;

    cin >> n;

    for(right = 1; right <= n; right++)
    {
        for(left = right; left >= 1; left--)
        {
            if(st.find({left, right}) == st.end())
            {
                cout << "? " << left << " " << right << "\n";
                cin >> s >> l >> r;
                
                arr[right] = s - (pref[right-1] - pref[left-1]);
                pref[right] = pref[right-1] + arr[right];

                st.insert({l, r});

                break;
            }
        }
    }

    cout << "!\n";
    for(i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}