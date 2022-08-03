#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

int arr[MAXN];
int pref[MAXN];

void solve(int caseno)
{
    int n, q, x, i, flag;
    set<int> st;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }

    while(q--)
    {
        st.clear();

        cin >> x;

        if(x == 0 || x == pref[n])
        {
            cout << "Yes\n";
            continue;
        }

        flag = 0;
        for(i = 1; i <= n; i++)
        {
            if(pref[i] == x || pref[n] - pref[i] == x)
            {
                flag = 1;
                break;
            }

            if(st.find(pref[i] - pref[n] + x) != st.end())
            {
                flag = 1;
                break;
            }

            st.insert(pref[i]);
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
