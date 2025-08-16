#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int n;
int LPS[11][120];
string s[11], full[11];

void KMP(int pos)
{
    int i, j;
    int sz = full[pos].size();

    LPS[pos][0]=0;
    for (i = 1; i < sz; i++)
    {
        j = LPS[pos][i-1];

        while (j > 0 && full[pos][i] != full[pos][j])
            j = LPS[pos][j-1];

        if (full[pos][i] == full[pos][j])
            j++;

        LPS[pos][i] = j;
    }
}

pii colorMax(int bg, int ed)
{
    int i, j, k, flag;
    vector<int> color(ed+1);

    for(i = ed; i >= bg; i--)
    {
        if(color[i] == 0)
            flag = 0;
        else
            flag = 1;

        for(j = 0; j < n; j++)
        {
            if(LPS[j][s[j].size()+1+i] == s[j].size())
            {
                flag = 1;

                for(k = 0; k < s[j].size(); k++)
                    color[i-k] = j+1;
            }
        }

        if(flag == 0)
            return {-1, -1};
    }

    for(i = 0; i <= bg; i++)
    {
        if(color[i])
            return {color[i], i};
    }
}

void solve(int caseno)
{
    int i, j, k, leftMost;
    string text;
    vector<bool> color(120);
    vector<pii> ans;

    cin >> text;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s[i];
        full[i] = s[i] + '#' + text;

        KMP(i);
    }

//    for(i = 0; i < full[1].size(); i++)
//        cout << LPS[1][i] << " ";
//    cout << "\n";
//
//    return;

    for(i = text.size()-1; i >= 0; i--)
    {
        if(color[i] == 0)
        {
            pii temp = colorMax(i, text.size()-1);
            leftMost = temp.ss;

            ans.push_back({temp.ff, temp.ss+1});

            if(leftMost == -1)
            {
                cout << "-1\n";
                return;
            }

            color[i] = 2;
            for(j = leftMost; j < i; j++)
                color[j] = 1;
        }
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

/*
6
bababa
2
ba
aba
caba
2
bac
acab
abacabaca
3
aba
bac
aca
baca
3
a
c
b
codeforces
4
def
code
efo
forces
aaaabbbbcccceeee
4
eeee
cccc
aaaa
bbbb
*/
