#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll canTake(ll s, ll w, ll cnts, ll cntw, ll f)
{
    if(s > w)
        return canTake(w, s, cntw, cnts, f);
    
    if(f <= cnts*s)
        return f/s;
    
    return cnts + min(cntw, (f-cnts*s)/w);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, p, f, cnts, cntw, s, w, i, mySword, hisSword, myAxe, hisAxe, ans;

    cin >> t;

    while(t--)
    {
        cin >> p >> f;
        cin >> cnts >> cntw;
        cin >> s >> w;

        if(s > w)
        {
            swap(s, w);
            swap(cnts, cntw);
        }

        ans = 0;
        for(i = 0; i <= cnts; i++)
        {
            mySword = min(i, p/s);
            hisSword = min(cnts-mySword, f/s);

            myAxe = min(cntw, (p-mySword*s)/w);
            hisAxe = min(cntw-myAxe, (f-hisSword*s)/w);

            ans = max(ans, mySword+hisSword+myAxe+hisAxe);
        }

        cout << ans << "\n";
    }
}
