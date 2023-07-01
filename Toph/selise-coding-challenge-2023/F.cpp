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

    LL n, i, p;
    string s;
    vector<pair<LL, string>> v;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s >> p;

        v.push_back({p, s});
    }

    sort(v.begin(), v.end());

    cout << "Selise Coding Challenge 2023 Winners\n";
    cout << "Winner: " << v[0].ss << " => " << v[0].ff << "\n";
    cout << "1st Runner Up: " << v[1].ss << " => " << v[1].ff << "\n";
    cout << "2nd Runner Up: " << v[2].ss << " => " << v[2].ff << "\n";
}