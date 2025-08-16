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

    LL q, h, s, d, n;

    cin >> q >> h >> s >> d >> n;

    cout << (n/2)*min({8*q, 4*h, 2*s, d}) + (n%2)*min({4*q, 2*h, s}) << "\n";
}