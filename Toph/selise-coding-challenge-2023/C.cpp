#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long LL;
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

LL step1(LL ed)
{
    LL i;
    for(i = 16; i < ed; i += 16)
    {
        if(!query(i))
            return i;
    }

    return ed;
}

LL step2(LL ed)
{
    LL i;
    for(i = ed-12; i < ed; i += 4)
    {
        if(!query(i))
            return i;
    }

    return ed;
}

LL step3(LL ed)
{
    LL i;
    for(i = ed-2; i < ed; i += 2)
    {
        if(!query(i))
            return i;
    }

    return ed;
}

int main()
{
    LL ed;
    ed = step1(64);
    ed = step2(ed);
    ed = step3(ed);

    cout << "! " << (1ULL << (ed-1)) << endl;
}