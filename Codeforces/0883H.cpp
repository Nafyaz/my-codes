#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006


void solve(int caseno)
{
    int n, i, j, sz;
    string s, t, pair, lone;
    map<char, int> mp;

    cin >> n >> s;

    for(i = 0; i < n; i++)
        mp[s[i]]++;

    for(auto [c, cnt] : mp)
    {
        pair = pair + string(cnt/2, c);
        
        if(cnt%2)
            lone.push_back(c);
    }

    if(lone.size() <= 1)
    {
        cout << "1\n";
        cout << pair;

        cout << lone;

        reverse(pair.begin(), pair.end());
        cout << pair << "\n";

        return;
    }

    for(i = 1; i <= n; i++)
    {
        if(n%i == 0 && (n/i)%2 == 1 && lone.size() <= i)
        {
            cout << i << "\n";

            for(j = 0; j < i; j++)
            {
                sz = (n/i)/2;

                t = string(pair.end() - sz, pair.end());
                pair.erase(pair.end() - sz, pair.end());            

                cout << t;
            
                if(lone.empty())
                {
                    lone.push_back(pair.back()); 
                    lone.push_back(pair.back());
                    pair.pop_back();
                }

                cout << lone.back();
                lone.pop_back();

                reverse(t.begin(), t.end());
                cout << t << " ";
            }

            cout << "\n";

            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}