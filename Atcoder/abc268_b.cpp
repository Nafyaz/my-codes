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

    int i;
    string s, t;

    cin >> s >> t;

    for(i = 0; i < s.size(); i++)
    {
        if(i >= t.size() || s[i] != t[i])
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}