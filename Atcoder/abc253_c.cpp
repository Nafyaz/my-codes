#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q, type, x, c;
    map<ll, ll> freq;
    set<ll> st;

    cin >> q;

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> x;
            st.insert(x);
            freq[x]++;
        }
        else if(type == 2)
        {
            cin >> x >> c;
            freq[x] -= min(freq[x], c);
            if(freq[x] == 0)
                st.erase(x);
        }
        else
        {
            cout << *(st.rbegin()) - *(st.begin()) << "\n";
        }
    }
}