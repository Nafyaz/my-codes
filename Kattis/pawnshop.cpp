#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 300005;

LL arr[MAXN], brr[MAXN];
map<LL, LL> freq;

void solve(int caseno)
{
    LL n, i, cnt;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];
    for(i = 0; i < n; i++)
        cin >> brr[i];

    cnt = 0;
    for(i = 0; i < n; i++)
    {
        cout << brr[i] << " ";

        freq[arr[i]]++;
        if(freq[arr[i]] == 1)
            cnt++;

        freq[brr[i]]--;
        if(freq[brr[i]] == 0)
            cnt--;

        if(cnt == 0 && i+1 < n)
            cout << "# ";
    }

    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
