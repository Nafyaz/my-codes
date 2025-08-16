#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int i, j;
    bool flag;
    string s, t, s2;

    cin >> s;

    s2 = s + s;

    t = s;
    t.pop_back();
    reverse(t.begin(), t.end());

    for(i = 0; i + t.size() - 1 < s2.size(); i++)
    {
        flag = 1;
        for(j = 0; j < t.size(); j++)
        {
            if(s2[i+j] != t[j])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << "1\n";
            return;
        }
    }

    t = s.substr(1);
    reverse(t.begin(), t.end());

    for(i = 0; i + t.size() - 1 < s2.size(); i++)
    {
        flag = 1;
        for(j = 0; j < t.size(); j++)
        {
            if(s2[i+j] != t[j])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << "1\n";
            return;
        }
    }

    cout << "0\n";
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

