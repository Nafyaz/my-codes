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
#define MAXN 200005

LL n, id[MAXN];
LL BIT[MAXN];

void Update(LL i, LL val)
{
    while(i < MAXN)
    {
        BIT[i] += val;
        i += i & (-i);
    }
}

LL Query(LL i)
{
    LL ret = 0;

    while(i)
    {
        ret += BIT[i];
        i -= i & (-i);
    }

    return ret;
}

void solve(int caseno)
{
    LL q, i, p, k;
    string type;
    LL low, high, mid, ansPos, ansId;

    cin >> n >> q;

    for(i = 1; i < MAXN; i++)
        BIT[i] = 0;

    for(i = 1; i <= n; i++)
    {
        cin >> id[i];
        Update(i, 1);
    }

    cout << "Case " << caseno << ": \n";
    while(q--)
    {
        cin >> type;

        if(type == "a")
        {
            cin >> p;

            n++;
            id[n] = p;
            Update(n, 1);
        }
        else
        {
            cin >> k;
            
            if(Query(n) < k)
            {
                cout << "none\n";
                continue;
            }
            
            low = 1;
            high = n;
            while(low <= high)
            {
                mid = (low + high)/2;

                if(Query(mid) >= k)
                {
                    ansId = id[mid];
                    ansPos = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }

            cout << ansId << "\n";
            Update(ansPos, -1);
        }

        // cout << "Query: ";
        // for(i = 1; i <= n; i++)
        //     cout << Query(i) << " ";
        // cout << "\n";
    }
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