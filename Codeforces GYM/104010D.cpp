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

LL c, id;
LL trie[MAXN][2], queryNo[MAXN], color[MAXN];
bool isLast[MAXN];
void Add(string s, LL qNo, LL x)
{
    LL i, r = 0;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L')
        {
            if(trie[r][0] == 0)
            {
                id++;
                trie[r][0] = id;
            }

            r = trie[r][0];
        }
        
        if(s[i] == 'R')
        {
            if(trie[r][1] == 0)
            {
                id++;
                trie[r][1] = id;
            }

            r = trie[r][1];
        }
    }

    isLast[r] = 1;
    queryNo[r] = qNo;
    color[r] = x;
}

LL query(string s)
{
    LL i, r = 0, retQNo = -1, retColor = -1, lastI = -1;

    if(isLast[0] == 1)
    {
        retQNo = queryNo[0];
        retColor = color[0];
    }

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L')
        {
            if(trie[r][0] == 0)
                break;
            r = trie[r][0];
        }

        if(s[i] == 'R')
        {
            if(trie[r][1] == 0)
                break;
            r = trie[r][1];
        }

        if(isLast[r] == 1 && retQNo < queryNo[r])
        {
            retQNo = queryNo[r];
            retColor = color[r];
            lastI = i;
        }
    }

    if(retQNo == -1)
        return -1;

    for(i = lastI + 1; i < s.size(); i++)
    {
        if(s[i] == 'L')
            retColor = (retColor + 1) % c;
        else
            retColor = (retColor - 1 + c) % c;
    }

    return retColor;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL q, type, i, x;
    string s;

    cin >> q >> c;

    for(i = 0; i < q; i++)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> x >> s;

            Add(s, i, x);
        }

        else
        {
            cin >> s;

            cout << query(s) << "\n";
        }
    }
}