#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll Q, type, x, c, mn, sum;
    deque<pair<ll, ll>> dq;

    cin >> Q;

    while(Q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> x >> c;

            dq.push_back({x, c});
        }
        else
        {
            cin >> c;

            sum = 0;
            while(c)
            {
                pair<ll, ll> temp = dq.front();
                dq.pop_front();

                mn = min(c, temp.ss);
                temp.ss -= mn;
                c -= mn;

                sum += temp.ff * mn;

                if(temp.ss)
                    dq.push_front(temp);
            }

            cout << sum << "\n";
        }
    }
}
