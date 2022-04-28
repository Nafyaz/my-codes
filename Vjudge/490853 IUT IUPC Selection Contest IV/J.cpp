#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, k, ans;
    string s, temp;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        ans = 0;

        for(i = 0; i+1 < n; i++)
        {
            temp = "";
            vector<string> v;

            for(j = i; j < n; j++)
            {
                temp.push_back(s[j]);
                v.push_back(temp);
            }

            sort(v.begin(), v.end());

//            cout << "i: " << i << "\n";
//            for(auto u : v)
//                cout << u << " ";
//            cout << "\n";

            for(j = i+1; j < n; j++)
            {
                temp = "";
                for(k = j; k < n; k++)
                {
                    temp.push_back(s[k]);
                    ans += v.size() - (upper_bound(v.begin(), v.end(), temp) - v.begin());
                    ans %= mod;
                }
            }
        }

        cout << ans << "\n";
    }
}
