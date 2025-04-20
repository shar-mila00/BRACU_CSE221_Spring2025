#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int R, H;
vector<string> grid;
vector<vector<bool>> visited;

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    int diamonds = 0;
    if (grid[i][j] == 'D') diamonds++;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Move Up
        if (x > 0 && !visited[x - 1][y] && grid[x - 1][y] != '#') {
            visited[x - 1][y] = true;
            if (grid[x - 1][y] == 'D') diamonds++;
            q.push({x - 1, y});
        }

        // Move Down
        if (x < R - 1 && !visited[x + 1][y] && grid[x + 1][y] != '#') {
            visited[x + 1][y] = true;
            if (grid[x + 1][y] == 'D') diamonds++;
            q.push({x + 1, y});
        }

        // Move Left
        if (y > 0 && !visited[x][y - 1] && grid[x][y - 1] != '#') {
            visited[x][y - 1] = true;
            if (grid[x][y - 1] == 'D') diamonds++;
            q.push({x, y - 1});
        }

        // Move Right
        if (y < H - 1 && !visited[x][y + 1] && grid[x][y + 1] != '#') {
            visited[x][y + 1] = true;
            if (grid[x][y + 1] == 'D') diamonds++;
            q.push({x, y + 1});
        }
    }

    return diamonds;
}

int main() {
    cin >> R >> H;
    grid.resize(R);
    visited.assign(R, vector<bool>(H, false));

    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    int maxDiamonds = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < H; ++j) {
            if (!visited[i][j] && grid[i][j] != '#') {
                int collected = bfs(i, j);
                maxDiamonds = max(maxDiamonds, collected);
            }
        }
    }

    cout << maxDiamonds << endl;
    return 0;
}