#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, prev, op;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;
        n = s.size();

        vector<ll> v;

        for(i = 0; i < n; i++)
        {
            if(!v.empty() && s[v.back()] == '(' && s[i] == ')')
                v.pop_back();
            else
                v.push_back(i);

            // for(ll j = 0; j < v.size(); j++)
            //     cout << v[j] << " ";
            // cout << "\n";
        }


        cout << v.size() << " ";
        if(v.size() == 0)
        {
            cout << "1\n";
            continue;
        }
        
        prev = op = 0;
        for(i = 0; i < v.size(); i++)
        {
            op += (v[i] - prev > 1);
            prev = v[i];  
        }

        op += (n - prev > 1);

        cout << op << "\n";
    }
}