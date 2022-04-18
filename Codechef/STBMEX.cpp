#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, temp, mex, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        set<ll> st;

        for(i = 1; i <= n; i++)
        {
            cin >> temp;
            st.insert(temp);
        }

        n = st.size();

        i = 1;
        for(auto u : st)
        {
            a[i] = u;
            i++;
        }

//        cout << "a:\n";
//        for(i = 0; i <= n; i++)
//            cout << a[i] << " ";
//        cout << "\n";

        mex = 0;
        for(i = 1; i <= n; i++)
        {
            if(a[i] == mex)
                mex++;
        }

//        cout << "mex: " << mex << "\n";

        if(mex == 0)
        {
            cout << a[1]-1 << "\n";
            continue;
        }

        if(mex == 1)
        {
            cout << "-1\n";
            continue;
        }

        ans = 0;
        for(i = mex+1; i+mex-2 <= n; i++)
        {
            j = i+mex-2;

            if(a[i]+mex-2 == a[j] && (j == n || a[j]+1 < a[j+1]))
                ans++;
        }

        cout << ans << "\n";
    }
}
