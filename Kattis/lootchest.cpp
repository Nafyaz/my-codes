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

double call(int i, double delL, double delW, double Ew)
{
    double P = (i*Ew - i)*delL + (i-1)*delW;

//    show(i);
//    show(P);
//    cout << "\n";

    if(P >= 100)
        return i*Ew;

    return P/100*(i*Ew) + (100-P)/100*call(i+1, delL, delW, Ew);
}

void solve(int caseno)
{
    double delL, delW, G, L;
    double Ew, Ep, Eg;

    cin >> delL >> delW >> G >> L;

    Ew = 100 / (100 - L);

    Ep = call(1, delL, delW, Ew);

    Eg = 100*Ep/G;

    show(Ew);
    show(Ep);
    show(Eg);
    cout << "\n";

    cout << fixed << setprecision(10) << Eg << "\n";
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

