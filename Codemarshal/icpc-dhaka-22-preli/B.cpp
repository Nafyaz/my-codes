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
#define MAXN 500005

int a[MAXN], b[MAXN];

void solve(int caseno)
{
    int n, i, j, temp, gcdA, gcdB;
    set<int> aS, bS;
    bool canAlice, canBob;

    cin >> n;

    gcdA = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        temp = a[i];

        for(j = 2; j*j <= temp; j++)
        {
            if(isPrime[temp])
            {
                aS.insert(temp);
                temp = 1;
                break;
            }
            while(temp%j == 0)
            {
                temp /= j;
                aS.insert(j);
            }
        }
        if(temp > 1)
            aS.insert(temp);

        gcdA = __gcd(gcdA, a[i]);
    }

    gcdB = 0;
    for(i = 0; i < n; i++)
    {
        cin >> b[i];

        temp = b[i];

        for(j = 2; j*j <= temp; j++)
        {
            if(isPrime[temp])
            {
                bS.insert(temp);
                temp = 1;
                break;
            }

            while(temp%j == 0)
            {
                temp /= j;
                bS.insert(j);
            }
        }
        if(temp > 1)
            bS.insert(temp);

        gcdB = __gcd(gcdB, b[i]);
    }

    cout << "Case " << caseno << ": ";

    canAlice = 1;
    for(auto bP : bS)
    {
        if(aS.find(bP) == aS.end())
        {
            canAlice = 0;
            break;
        }
    }

    if(canAlice == 0)
    {
        cout << "No No\n";
        return;
    }

    canBob = 1;
    for(i = 0; i < n; i++)
    {
        a[i] /= gcdA;
        b[i] /= gcdB;

        if(a[i] != b[i])
        {
            canBob = 0;
            break;
        }
    }

    cout << "Yes " << (canBob? "Yes\n" : "No\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}