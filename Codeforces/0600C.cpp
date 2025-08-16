#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;
    string s;
    char c;
    map<char, int> freq;
    vector<char> odds, evens;

    cin >> s;

    for(i = 0; i < s.size(); i++)    
        freq[s[i]]++;
    
    for(c = 'a'; c <= 'z'; c++)
    {
        if(freq[c] % 2)
            odds.push_back(c);
        else
            evens.push_back(c);
    }

    for(i = 0; 2*i < odds.size(); i++)
    {
        freq[odds[i]]++;
        freq[odds[odds.size()-i-1]]--;
    }

    string Lone, Pair;
    for(auto &[x, y] : freq)
    {
        if(y%2 == 1)        
        {
            Lone.push_back(x);
            y --;
        }
        
        while(y)
        {
            Pair.push_back(x);
            y -= 2;
        }
    }

    cout << Pair;
    cout << Lone;
    reverse(Pair.begin(), Pair.end());
    cout << Pair << "\n";
}