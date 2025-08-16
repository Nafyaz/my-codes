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

    LL w, m, digit, carry;

    cin >> w >> m;

    if(w == 2)
    {
        cout << "YES\n";
        return 0;
    }

    carry = 0;
    while(m)
    {
        m += carry;
        carry = 0;

        digit = m%w;
        m /= w;
        
        if(digit == 0 || digit == 1)
            continue;

        if(digit + 1 == w)
            carry = 1;
        else
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}