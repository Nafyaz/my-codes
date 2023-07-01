#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll fact[21];
map<char, ll> freq;
ll len;

ll countPermutations()
{
    ll total = 0, denom = 1;
    for(auto u : freq)
    {
        total += u.ss;
        denom *= fact[u.ss];
    }

    return fact[total] / denom;
}

string call(ll pos, ll n)
{
    if(pos == len)
        return "";

    char a, b;
    ll cnt;

    for(a = 'a'; a <= 'z'; a++)
    {
        if(freq[a] == 0)
            continue;
        
        freq[a]--;
        cnt = countPermutations();
        if(cnt < n)
        {
            freq[a]++;
            n -= cnt;
            continue;
        }

        return a + call(pos+1, n);        
    }

    return "";
}

void solve(ll caseno)
{
    string s, ans;
    ll i, n;

    cin >> s >> n;
    len = s.size();

    freq.clear();
    for(i = 0; i < len; i++)
        freq[s[i]]++;

    ans = call(0, n);
    cout << "Case " << caseno << ": " << (ans.empty()? "Impossible" : ans) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i;

    fact[0] = 1;
    for(i = 1; i <= 20; i++)
        fact[i] = fact[i-1] * i;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}