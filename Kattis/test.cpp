#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, powers, evens;

    powers = evens = 0;
    for(i = 1; i < MAXN; i++)
    {
        if(i%2 == 0)
            evens++;
        if((i&(i-1)) == 0)
            powers++;

        if(i%10000 == 0)
            cout << i << ": " << (double)powers/evens*100 << "%\n";
    }
}