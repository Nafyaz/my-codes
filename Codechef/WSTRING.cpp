#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll freq[10004][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j, ans, mx[4];
    string s;
    vector<ll> hashIdx;

    cin >> T;

    while(T--)
    {
        cin >> s;

        s = '*' + s;

        hashIdx.clear();
        for(i = 1; i < s.size(); i++)
        {
            if(s[i] == '#')
                hashIdx.push_back(i);

            for(j = 0; j < 26; j++)                
                freq[i][j] = freq[i-1][j] + (s[i] == 'a'+j);                    
        }

        // for(i = 1; i < s.size(); i++)
        // {
        //     for(j = 0; j < 4; j++)
        //         cout << freq[i][j] << ' ';
        //     cout << "\n";
        // }
        // for(i = 0; i < hashIdx.size(); i++)
        //     cout << hashIdx[i] << ' ';
        // cout << '\n';
        
        ans = 0;
        for(i = 0; i+2 < hashIdx.size(); i++)
        {
            mx[0] = 0;
            for(j = 0; j < 26; j++)            
                mx[0] = max(mx[0], freq[hashIdx[i]-1][j]);
            
            mx[1] = 0;
            for(j = 0; j < 26; j++) 
                mx[1] = max(mx[1], freq[hashIdx[i+1]-1][j] - freq[hashIdx[i]][j]);

            mx[2] = 0;
            for(j = 0; j < 26; j++) 
                mx[2] = max(mx[2], freq[hashIdx[i+2]-1][j] - freq[hashIdx[i+1]][j]);

            mx[3] = 0;
            for(j = 0; j < 26; j++) 
                mx[3] = max(mx[3], freq[s.size() - 1][j] - freq[hashIdx[i+2]][j]);

            if(mx[0] && mx[1] && mx[2] && mx[3])
                ans = max(ans, mx[0] + mx[1] + mx[2] + mx[3] + 3);
        }

        cout << ans<< "\n";
    }
}