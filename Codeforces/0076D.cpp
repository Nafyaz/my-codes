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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    unsigned long long a, b, x, y, Xor, And;
    int i;

    cin >> a >> b;

    if(a < b || (a-b)%2 == 1)
    {
        cout << "-1\n";
        return 0;
    }

    And = (a-b)/2;
    Xor = b;

    x = y = 0;
    for(i = 63; i >= 0; i--)
    {
        // show(i);

        if(And&(1ULL << i))
        {
            if(Xor&(1ULL << i))
            {
                cout << "-1\n";
                return 0;
            }

            x |= (1ULL << i);
            y |= (1ULL << i);
        }
        else
        {
            if(Xor&(1ULL << i))
                y |= (1ULL << i);
        }
    }

    if(x+y == a && (x^y) == b)
        cout << x << " " << y << "\n";
    else
        cout << "-1\n";
}