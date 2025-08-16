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

int duval(string s)
{
    s = s + s;
    int n = s.size();
    int i = 0, ret;
    
    while(i < n/2)
    {
        ret = i;
        int j = i+1, k = i;;

        while(j < n && s[k] <= s[j])
        {
            if(s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }

        while(i <= k)
            i += j - k;
    }

    return ret;
}

void solve(int caseno)
{
    string s;

    cin >> s;

    rotate(s.begin(), s.begin()+duval(s), s.end());

    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}