#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// All 8 possible knight moves
const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int knightMinMoves(int N, int x1, int y1, int x2, int y2) {
    // Adjust to 0-based indexing
    x1--; y1--; x2--; y2--;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<pair<int, int>, int>> q; // ((x, y), steps)

    q.push({{x1, y1}, 0});
    visited[x1][y1] = true;

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        int x = node.first.first, y = node.first.second, steps = node.second;

        if (x == x2 && y == y2) return steps;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }

    return -1; // Target not reachable
}

int main() {
    int N, x1, y1, x2, y2;
    cin >> N >> x1 >> y1 >> x2 >> y2;

    cout << knightMinMoves(N, x1, y1, x2, y2) << endl;

    return 0;
}
