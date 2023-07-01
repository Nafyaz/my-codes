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

bool isInt(string s)
{
    if(s.empty())
        return 0;

    if(s.size() > 1 && s[0] == '0')
        return 0;

    int i;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] < '0' || s[i] > '9')
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;
    string s, temp;
    vector<string> a, b;

    cin >> s;

    temp = "";
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == ';' || s[i] == ',')
        {
            if(isInt(temp))
                a.push_back(temp);
            else
                b.push_back(temp);
            
            temp = "";
        }
        else
            temp.push_back(s[i]);
    }
    if(isInt(temp))
        a.push_back(temp);
    else
        b.push_back(temp);

    if(a.size() == 0)
        cout << "-\n";
    else
    {
        cout << "\"";
        for(i = 0; i < a.size(); i++)    
            cout << a[i] << (i+1 == a.size()? "\"" : ",");
        cout << "\n";
    }

    if(b.size() == 0)
        cout << "-\n";
    else
    {
        cout << "\"";
        for(i = 0; i < b.size(); i++)
            cout << b[i] << (i+1 == b.size()? "\"" : ",");
        cout << "\n";
    }
}