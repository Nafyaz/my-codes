#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, k, i, rep;
    string s;

    cin >> n >> k >> s;

    rep = -1;
    for(i = 0; i+1 < n && k; i++)
    {
        if(s[i] == '4' && s[i+1] == '7')
        {
            if(i&1)
            {
                if(i > 0 && s[i-1] == '4')
                {
                    rep = i;
                    break;
                }
                else
                {
                    s[i] = '7';
                    k--;
                }
            }
            else
            {
                if(i+2 < n && s[i+2] == '7')
                {
                    rep = i+1;
                    break;
                }
                else
                {
                    s[i+1] = '4';
                    k--;
                }
            }
        }
    }

    if(rep != -1 && (k&1))
        s[rep] = (s[rep] == '4'? '7' : '4');

    cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
