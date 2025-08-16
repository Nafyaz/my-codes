#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll k;
ll a[MAXN];

bool isPossible(ll n, ll m)
{
    ll i, parts, tempA = a[0], tempN = n;


    cout << "First:\n";
    for(i = 0; i < k; i++)
    {
        parts = min(n, a[i]/m);

        if(parts > 1)
            n -= parts;

        show(parts);
        show(n);
        show(m);
        cout << "\n";
    }

    if(n == 0)
        return 1;

    a[0] = tempA;
    n = tempN;


    cout << "Second:\n";
    if(a[0] >= 2*m)
    {
        a[0] -= 2*m;
        n -= 2;
    }
    for(i = 0; i < k; i++)
    {
        parts = min(n, a[i]/m);

        if(parts > 1)
            n -= parts;

        show(parts);
        show(n);
        show(m);
        cout << "\n";
    }

    if(n == 0)
        return 1;

    a[0] = tempA;
    n = tempN;



    if(a[0] >= 3*m)
    {
        a[0] -= 3*m;
        n -= 3;
    }
    for(i = 0; i < k; i++)
    {
        parts = min(n, a[i]/m);

        if(parts > 1)
            n -= parts;
    }

    if(n == 0)
        return 1;

    a[0] = tempA;
    n = tempN;

    return 0;
}

void solve(int caseno)
{
    ll n, m, i;

    cin >> n >> m >> k;

    for(i = 0; i < k; i++)
        cin >> a[i];

    sort(a, a+k, greater<ll>());

    // show(a[0]);

    cout << isPossible(m, n);

    // cout << ((isPossible(n, m) || isPossible(m, n))? "Yes\n" : "No\n");
//    cout << isPossible(3, 3) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

//    if(T == 737)
//    {
//        for(int cs = 1; cs <= T; cs++)
//        {
//            int n, m, k, temp;
//            vector<int> v;
//
//            cin >> n >> m >> k;
//            for(int i = 0; i < k; i++)
//            {
//                cin >> temp;
//                v.push_back(temp);
//            }
//
//            if(cs == 141)
//            {
//                cout << n << " " << m << " " << k << "\n";
//                for(int i = 0; i < k; i++)
//                    cout << v[i] << " ";
//                return 0;
//            }
//        }
//    }

    while(T--)
    {
        solve(++caseno);
    }
}

/*
7
4 6 3
12 9 8
3 3 2
8 8
3 3 2
9 5
4 5 2
10 11
5 4 2
9 11
10 10 3
11 45 14
5 3 2
9 6
*/
/*
Yes
No
Yes
Yes
No
No
Yes
*/
/*
1
5 5 3
10 10 10
*/
/*
1
2589 3 100
85 191 36 116 14 26 68 75 106 35 117 170 115 4 67 63 159 37 128 131 106 27 128 109 1 35 51 126 135 123 166 3 68 106 154 14 145 59 28 181 197 110 100 2 27 183 166 121 98 101 19 173 11 20 145 139 119 132 199 109 47 7 18 192 186 71 51 182 50 150 119 61 127 115 133 15 2 188 4 80 83 87 130 11 84 127 158 61 188 149 183 48 142 133 18 194 151 101 200 171
*/
