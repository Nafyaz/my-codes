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

int n;
string s;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN];

void countingSort(int k)
{
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for(i = 0; i < n; i++)
    {
        if(i + k < n)
            c[RA[i+k]]++;
        else
            c[0]++;
    }
    for(i = sum = 0; i < maxi; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for(i = 0; i < n; i++)
    {
        if(SA[i]+k < n)
        {
            c[RA[SA[i]+k]]++;
            tempSA[c[RA[SA[i]+k]]] = SA[i];
        }
        else
        {
            c[0]++;
            tempSA[c[0]++] = SA[i];
        }
    }
    for(i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA()
{
    int i, k, r;
    for(i = 0; i < n; i++)
        RA[i] = s[i];
    for(i = 0; i < n; i++)
        SA[i] = i;
    for(k = 1; k < n; k <<= 1)
    {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for(i = 1; i < n; i++)
        {
            if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])
                r++;

            tempRA[SA[i]] = r;
        }
        for(i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if(RA[SA[n-1]] == n-1)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> s;

    n = s.size();

    constructSA();

    rotate(s.begin(), s.begin() + SA[0], s.end());

    cout << s << "\n";
}