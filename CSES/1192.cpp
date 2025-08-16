#include<bits/stdc++.h>
using namespace std;

int n, m;
string grid[1003];

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

void dfs(int x, int y) {
    grid[x][y] = '#';

    for (int i = 0; i < 4; i++) {
        int x2 = x+dirX[i], y2 = y+dirY[i];
        if (isValid(x2, y2))
            dfs(x2, y2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
}