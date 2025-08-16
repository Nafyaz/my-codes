#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int n, k;
int p[MAXN];

vector<int> solve(deque<int> Q, pii best)
{
    vector<int> ret;
    set<pii> st;

    int i, L, R, moves;
    moves = k - best.ss + 1;
    R = best.ss - 1;
    L = -1;

    for(i = 0; i <= R; i++)
        st.insert({Q[i], i});

    while(L+1 < Q.size() || R+1 < Q.size())
    {
        while(moves > 0 && R+1 < Q.size())
        {
            R = R + 1;
            st.insert({Q[R], R});
            moves = moves - 1;
        }

        pii e = *st.begin();
        ret.push_back(e.ff);
        while(L < e.ss)
        {
            L = L + 1;
            if(L >= best.ss && L == e.ss)
                moves++;
            st.erase({Q[L], L});
        }
    }

    while(moves > 1)
    {
        ret.pop_back();
        moves--;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, mn, mnPos;

    cin >> n >> k;

    for(i = 1; i <= n; i++)    
        cin >> p[i];
    
    pii best = {INT_MAX, 0};
    for(i = 1; i <= k; i++)
        best = min(best, {p[n-i+1], i});

    deque<int> Q, P;

    for(i = 1; i <= n; i++)
        P.push_back(p[i]);

    for(i = 1; i <= best.ss; i++)
        Q.push_front(p[n-i+1]);

    for(i = 1; i <= n-best.ss; i++)
        Q.push_back(p[i]);

    vector<int> ans1 = solve(P, {0, 0});
    vector<int> ans2 = solve(Q, best);

    vector<int> ans = min(ans1, ans2);

    for(auto u : ans)
        cout << u << " ";
    cout << "\n";
}