#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i;
    string a, b;

    cin >> T;
    getline(cin, a);

    while(T--)
    {
        getline(cin, a);
        getline(cin, b);

        map<char, ll> freqA, freqB;

        for(i = 0; i < a.size(); i++)
        {
            if(isalpha(a[i]))
                freqA[tolower(a[i])]++;
        }
        for(i = 0; i < b.size(); i++)
        {
            if(isalpha(b[i]))
                freqB[tolower(b[i])]++;
        }

        cout << "Case " << ++caseno << ": " << (freqA == freqB? "Yes\n" : "No\n");
    }
}
