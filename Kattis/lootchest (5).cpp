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

    double delL, delW, G, L;
    double Ew, dp[102], Eg;

    cin >> delL >> delW >> G >> L;

    Ew = 100 / (100 - L);
    dp[100] = Ew;

    for(int i = 99; i >= 0; i--)    
        dp[i] = 1 + L/100*dp[min(100, (round)(i+delL))] + (100 - L)/100*dp[min(100, (round)(i+delW))];
    
    Eg = 100*dp[0] / G;

    cout << Eg << "\n";
}