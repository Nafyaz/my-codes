#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

string grid[1003];
bool isVisited[1003][1003][3];
int h, w;
pair<int, int> bg, ed;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

bool isInvalid(pair<int, int> pos)
{
    return pos.first < 0 || pos.first >= h || pos.second < 0 || pos.second >= w;
}

bool isBlocked(pair<int, int> pos)
{
    return grid[pos.first][pos.second] == '#';
}

struct Node
{
    pair<int, int> pos;
    int dist;
    int prevDir;
};

Node getNodeChild(Node node, int dir)
{
    return {{node.pos.first + dirX[dir], node.pos.second + dirY[dir]}, node.dist + 1, dir % 2};
}

int bfs()
{
    queue<Node> q;

    Node bgNode = {bg, 0, -1};

    q.push(bgNode);
    isVisited[bg.first][bg.second][2] = true;

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if ((node.prevDir == 0 && i % 2 == 0) || (node.prevDir == 1 && i % 2 == 1))
                continue;

            Node child = getNodeChild(node, i);
            if (isInvalid(child.pos) || isBlocked(child.pos) || isVisited[child.pos.first][child.pos.second][child.prevDir])
                continue;

            if (child.pos == ed)
                return child.dist;

            q.push(child);
            isVisited[child.pos.first][child.pos.second][child.prevDir] = true;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == 'S')
                bg = {i, j};
            if (grid[i][j] == 'G')
                ed = {i, j};
        }
    }

    cout << bfs() << "\n";
}