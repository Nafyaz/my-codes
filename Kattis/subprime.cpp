#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 1300006

ll N = MAXN;
bool flag[MAXN];
vector<string> primes;

void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < MAXN; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < MAXN; i++)
    {
        if(flag[i])
            primes.push_back(to_string(i));
    }
}

bool isIn(string s, string t)
{
    int i, j;

    for(i = 0; i + t.size() -1< s.size(); i++)
    {
        for(j = 0; j < t.size(); j++)
        {
            if(s[i+j] != t[j])
                break;
        }

        if(j == t.size())
            return 1;
    }

    return 0;
}

void solve(int caseno)
{
    int l, r, i,  ans;
    string p;

    cin >> l >> r >> p;

    l--;
    r--;

    ans = 0;
    for(i = l; i <= r; i++)
    {
        if(isIn(primes[i], p))
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    sieve();

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
