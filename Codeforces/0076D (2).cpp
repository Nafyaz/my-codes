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

    unsigned long long a, b;

    cin >> a >> b;

    if(a < b || (a-b)%2 == 1)
        cout << "-1\n";
    else
        cout << (a-b)/2 << " " << (a+b)/2 << "\n";
}