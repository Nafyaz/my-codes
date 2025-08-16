#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

void solve(int caseno)
{
    int n, i, aNum, bNum;
    bool aOne, bOne;
    string a, b;

    cin >> n >> a >> b;

    if(n == 2)
    {
        aNum = bitset<2>(a).to_ulong();
        bNum = bitset<2>(b).to_ulong();

        if(aNum == 0)
            cout << (bNum == 0? "YES\n" : "NO\n");
        else if(aNum == 1)
            cout << (bNum == 2? "NO\n" : "YES\n");
        else if(aNum == 2)
            cout << (bNum == 1? "NO\n" : "YES\n");
        else
            cout << (bNum == 0 || bNum == 3)? "YES\n" : "NO\n";

        return;
    }
    else if(n == 3)
    {
        aNum = bitset<3>(a).to_ulong();
        bNum = bitset<3>(b).to_ulong();

        if(aNum == 0)
            cout << (bNum == 0? "YES\n" : "NO\n");
        else if(aNum == 2)
            cout << (bNum == 5? "NO\n" : "YES\n");
        else if(aNum == 5)
            cout << (bNum == 2? "NO\n" : "YES\n");
        else
            cout << ((bNum == 2 || bNum == 5)? "NO\n" : "YES\n");

        return;
    }

    aOne = bOne = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] == '1')
            aOne = 1;
        if(b[i] == '1')
            bOne = 1;
    }

    if(!aOne && bOne)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(caseno);
    }
}
