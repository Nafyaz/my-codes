#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll freq[26][200005];
vector<ll> pos[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j, k;
    bool flag;
    string s;

    cin >> T;

    while(T--)
    {
        for(i = 0; i < 26; i++)
            pos[i].clear();

        cin >> s;

        for(i = 0; i < s.size(); i++)
        {
            for(j = 0; j < 26; j++)
                freq[j][i+1] = freq[j][i] + (s[i] - 'a' == j);

            pos[s[i] - 'a'].push_back(i);
        }

        // for(i = 0; i < 2; i++)
        // {
        //     // cout << i << ": ";

        //     // for(j = 0; j <= s.size(); j++)
        //     //     cout << freq[i][j] << " ";
        //     // cout << "\n";

        //     // for(auto p : pos[i])
        //     //     cout << p << " ";
        //     // cout << "\n";
        // }


        flag = 1;
        for(i = 0; i < 26 && flag; i++)
        {
            for(j = 1; j < pos[i].size() && flag; j++)
            {
                for(k = 0; k < 26 && flag; k++)
                {
                    if(i != k && !pos[k].empty() && freq[k][pos[i][j]+1] - freq[k][pos[i][j-1]] == 0)
                        flag = 0;
                }
            }
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}