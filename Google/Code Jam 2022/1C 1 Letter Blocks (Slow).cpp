#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s[102], S;
ll seq[102];

bool isPossible(string s)
{
    ll i;
    map<char, ll> freq;

    for(i = 0; i < s.size(); i++)
    {
        if(i == 0)
            freq[s[i]]++;
        else if(s[i] != s[i-1])
        {
            freq[s[i]]++;

            if(freq[s[i]] > 1)
                return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, i, flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)        
        {
            cin >> s[i];
            seq[i] = i;
        }
        
        flag = 0;
        do
        {
            S = "";
            for(i = 0; i < n; i++)
                S += s[seq[i]];
            if(isPossible(S))
            {
                flag = 1;
                break;
            }
        }while(next_permutation(seq, seq+n));

        cout << "Case #" << ++caseno << ": " << (flag? S : "IMPOSSIBLE") << "\n";
    }
}