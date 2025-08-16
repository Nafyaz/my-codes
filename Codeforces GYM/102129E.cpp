#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, color[2], turn;
    priority_queue<int> pq[2];

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        pq[a%2].push(a);
    }

    color[0] = color[1] = 0;
    turn = 0;
    while(!pq[0].empty() || !pq[1].empty())
    {
        if(!pq[1].empty())
        {
            color[turn]++;

            a = pq[1].top();
            pq[1].pop();

            pq[0].push(a-1);

            turn ^= 1;
        }
        else
        {
            a = pq[0].top();
            pq[0].pop();

            if(a == 2)
            {
                color[0]++;
                color[1]++;
            }
            else
            {
                a /= 2;

                pq[a%2].push(a);
                pq[a%2].push(a);
            }

            turn ^= 1;
        }
    }

    cout << color[0] << "\n";
}
