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

set<int> usableSet{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void getUsable(ll n)
{
    while(n)
    {
        usableSet.erase(n%10);
        n /= 10;
    }
}

void solve(int caseno)
{
    ll n, low, high, i;
    string s;

    cin >> s;

    n = stoll(s);

    getUsable(n);

    vector<int> usable(usableSet.begin(), usableSet.end());

    if(usable.size() == 0)
    {
        cout << "Impossible\n";
        return;
    }

    if(usable.size() == 1)
    {
        if(usable[0] == 0)
            cout << "0\n";
        else
        {
            high = 0;
            while(high <= n)
                high = high*10 + usable[0];

            low = high/10;

            if(n - low > high - n)
                cout << high << "\n";
            else if(n - low < high - n)
                cout << low << "\n";
            else
                cout << low << " " << high << "\n";
        }

        return;
    }

    high = 0;
    if(usable.back() > s[0] - '0')
    {
        for(auto u : usable)
        {
            if(u > s[0] - '0')
            {
                high = u;
                break;
            }
        }
    }

    while(high <= n)
    {
        high = 10*high + usable[0];
    }

    low = 0;
    if(usable[0] < s[0] - '0')
    {
        for(auto u : usable)
        {
            if(u < s[0] - '0')
                low = u;
        }
    }

    while(10*low + usable.back() <= n)
        low = 10*low + usable.back();

//    show(n);
//    show(low);
//    show(high);
//    show(n - low);
//    show(high - n);
//    cout << "\n";

    if(n - low > high - n)
        cout << high << "\n";
    else if(n - low < high - n)
        cout << low << "\n";
    else
        cout << low << " " << high << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
