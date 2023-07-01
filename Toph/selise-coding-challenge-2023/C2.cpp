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

bool query(LL x)
{
    string s;
    cout << "? " << (1ULL << x) << endl;
    cin >> s;

    return (s == "yes");
}

void out(LL x)
{
    cout << "! " << (1ULL << x) << endl;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL ed = 60;
    for(LL i = 15; i < 60; i += 15)
    {
        if(!query(i))
        {
            ed = i;
            break;
        }
    }

    for(LL i = ed-12; i < ed; i += 4)
    {
        if(!query(i))
        {
            ed = i
            break;
        }
    }

    for(LL i = ed-4; i < ed; i ++)
    {
        if(!query(i))
        {
            out(i-1);
            return 0;
        }
    }
}