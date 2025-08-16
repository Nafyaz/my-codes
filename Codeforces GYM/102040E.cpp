#include<bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << ": " << x << "; "

void solve(int n)
{
    char shift, temp;
    int i, ans;
    int h1, m1, s1, h2, m2, s2;
    int S1, S2, duration;
    int dStart = 9*3600 + 30*60, eStart = 12*3600 + 30*60;
    int dDuration = 8*3600, eDuration = 9*3600;

//    show(dStart);
//    show(eStart);
//    show(dDuration);
//    show(eDuration);
//    cout << "\n";

    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> shift >> temp >> h1 >> temp >> m1 >> temp >> s1 >> temp >> h2 >> temp >> m2 >> temp >> s2;

        S1 = h1*3600 + m1*60 + s1;
        S1 = max(S1, 8*3600 + 30*60);

        S2 = h2*3600 + m2*60 + s2;
        S2 = max(S2, 8*3600 + 30*60);

        duration = S2 - S1;

//        cout << "\n";
//        cout << shift<< temp << h1 << temp << m1 << temp << s1 << temp << h2 << temp << m2 << temp << s2 << "\n";
//        show(shift);
//        show(S1);
//        show(S2);
//        show(duration);

        if(shift == 'D' && (S1 > dStart || duration < dDuration))
            ans++;
        if(shift == 'E' && (S1 > eStart || duration < eDuration))
            ans++;

//        show(ans);
    }

    if(ans == 0)
        cout << "All OK\n";
    else if(ans <= 3)
        cout << ans <<  " Point(s) Deducted\n";
    else
        cout << "Issue Show Cause Letter\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        solve(n);
    }
}
/*
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:16:30:00
D:9:30:00:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:00:00
4
D:8:00:00:16:15:20
D:9:30:01:17:30:00
E:11:30:01:20:00:00
E:11:30:01:20:00:00
0
*/
    