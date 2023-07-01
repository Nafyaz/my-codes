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

vector <int> jiro[2], ciel;

int killAll()
{
    int ret = 0, i, j;
    set<int> st;

    for(i = 0, j = 0; i < jiro[0].size(); i++)
    {
        while(j < ciel.size() && jiro[0][i] > ciel[j])
            j++;

        if(j == ciel.size())
            return 0;
        
        st.insert(j);
        j++;
    }

    for(i = 0, j = 0; i < jiro[1].size(); i++)
    {
        while(j < ciel.size() && jiro[1][i] > ciel[j] && st.find(j) != st.end())
            j++;

        if(j == ciel.size())
            return 0;

        ret += ciel[j] - jiro[1][i];
        st.insert(j);
        j++;
    }

    for(j = 0; j < ciel.size(); j++)
    {
        if(st.find(j) != st.end())
            ret += ciel[j];
    }

    return ret;
}

int killSome()
{
    int ret = 0, i, j;

    for(i = 0, j = ciel.size()-1; i < jiro[1].size() && jiro[1][i] <= ciel[j]; i++)
        ret += ciel[j] - jiro[1][i];
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, str, i, j;
    string type;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> type >> str;

        jiro[type == "DEF"].push_back(str);
    }

    for(i = 0; i < m; i++)
    {
        cin >> str;
        ciel.push_back(str);
    }

    sort(jiro[0].begin(), jiro[0].end());
    sort(jiro[1].begin(), jiro[1].end());
    sort(ciel.begin(), ciel.end());

    cout << max(killAll(), killSome()) << "\n";
}