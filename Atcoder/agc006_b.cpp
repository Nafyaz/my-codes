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

LL a[MAXN];
set<LL> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, x, i;

    cin >> n >> x;

    for(i = 1; i <= 2*n; i++)
        st.insert(i);


    if(x == 1 || x == 2*n-1)
    {
        cout << "No\n";
        return 0;
    }

    a[n] = x;
    st.erase(x);
    if(x == 2)
    {
        a[n-1] = x+1;
        a[n+1] = 2;
        a[n+2] = x+2;
        st.erase(x+1);
        st.erase(2);
        st.erase(x+2);
    }
    else
    {
        a[n-1] = x-1;
        a[n+1] = x+1;
        a[n+2] = x-2;
        st.erase(x-1);
        st.erase(x+1);
        st.erase(x-2);
    }

    cout << "Yes\n";
    x = 1;
    for(i = 1; i <= 2*n-1; i++)
    {
        if(a[i] == 0)
        {
            cout << *st.begin() << "\n";
            st.erase(st.begin());
        }
        else
            cout << a[i] << "\n";
    }
}