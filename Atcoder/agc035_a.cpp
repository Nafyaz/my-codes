#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, a;
    map<LL, LL> freq;
    vector<LL> v;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
    }

    if(freq.size() > 3)
    {
        cout << "No\n";
        return 0;
    }

    for(auto [x, y] : freq)
        v.push_back(x);

    if(freq.size() == 1)
        cout << (v[0] == 0? "Yes\n" : "No\n");
    else if(freq.size() == 2)
    {
        if(v[0] == 0 && freq[v[1]] == 2*freq[v[0]])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        if((v[0]^v[1]) == v[2] && freq[v[0]] == freq[v[1]] && freq[v[1]] == freq[v[2]])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}