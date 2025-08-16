#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll root[MAXN];

int Find(int x)
{
    if (x == root[x])
        return x;
    return root[x] = Find(root[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    root[max(x, y)] = min(x, y);
}

void solve(int caseno)
{
    int C, N, i, a;
    set<int> wrong;
    vector<pii> correct, errors;

    cin >> C >> N;

    for(i = 0; i < N; i++)
    {
        cin >> a;

        wrong.insert(a);
    }

    for(i = 1; i <= C; i++)
        root[i] = i;

    for(i = 2; i <= C; i++)
    {
        if(wrong.find(i) != wrong.end())
        {
            if(wrong.find(i-1) != wrong.end())
                Union(i, i-1);
        }
        else if(wrong.find(i-1) == wrong.end())
            Union(i, i-1);
    }

    for(i = C; i > 0; i = Find(i) - 1)
    {
        if(wrong.find(i) == wrong.end())
            correct.push_back({Find(i), i});
        else
            errors.push_back({Find(i), i});
    }

    reverse(correct.begin(), correct.end());
    reverse(errors.begin(), errors.end());

    cout << "Errors: ";
    for(i = 0; i < errors.size(); i++)
    {
        if(errors[i].ff == errors[i].ss)
            cout << errors[i].ff;
        else
            cout << errors[i].ff << "-" << errors[i].ss;

        if(i+2 < errors.size())
            cout << ", ";
        else if(i+2 == errors.size())
            cout << " and ";
    }
    cout << "\n";

    cout << "Correct: ";
    for(i = 0; i < correct.size(); i++)
    {
        if(correct[i].ff == correct[i].ss)
            cout << correct[i].ff;
        else
            cout << correct[i].ff << "-" << correct[i].ss;

        if(i+2 < correct.size())
            cout << ", ";
        else if(i+2 == correct.size())
            cout << " and ";
    }
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

