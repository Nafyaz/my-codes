#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

//string s[46] = {"", "1", "2", "3", "4", "5", "6", "7", "8", "9", "19", "29", "39", "49", "59", "69", "79", "89", "189", "289", }

void solve(int caseno)
{
    int sum, i, lastDigit;
    string ans;

    cin >> sum;

    lastDigit = 9;
    while(sum)
    {
        if(sum >= lastDigit)
        {
            ans.push_back('0' + lastDigit);
            sum -= lastDigit;
            lastDigit--;
        }
        else
        {
            ans.push_back('0' + sum);
            sum = 0;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

