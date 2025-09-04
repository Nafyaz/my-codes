#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        int alive, target;
        cin >> alive >> target;

        pair<int, int> group[2] = {{2, 0}, {2, 1}};
        int dyingGroupNo = 1;
        int totalDead = 0;

        while (totalDead < target) {
            int willDie;

            // cout << "dyingGroupNo: " << dyingGroupNo << " ";
            if (dyingGroupNo == 0)
                willDie = (alive+1)/2;
            else
                willDie = alive/2;

            pair<int, int> survivingGroup = group[dyingGroupNo^1];
            pair<int, int> dyingGroup = group[dyingGroupNo];

            // cout << "willDie: "  << willDie << "\n";

            if (totalDead + willDie >= target) {
                cout << dyingGroup.first * (target - totalDead - 1) + dyingGroup.second + 1<< "\n";
            }
            
            group[0] = {survivingGroup.first*2, survivingGroup.second};
            group[1] = {survivingGroup.first*2, survivingGroup.first + survivingGroup.second};

            if (alive%2 == 1)
                dyingGroupNo ^= 1;

            totalDead += willDie;
            alive -= willDie;
        }
    }
}