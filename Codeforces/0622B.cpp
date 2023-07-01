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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, m, a;

    scanf("%d:%d", &h, &m);
    m = h*60 + m;

    scanf("%d", &a);

    m = (m + a) % 1440;

    cout << setfill('0') << setw(2) << m/60 << ":" << setfill('0') << setw(2) << m%60 << "\n"; 
}