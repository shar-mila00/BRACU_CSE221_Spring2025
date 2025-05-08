#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// all possible moves by knight

const int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int knightMoves(int size, int m, int n, int r, int s) {

    // 2D grid
    vector<vector<int> > visited(size + 1, vector<int>(size + 1, 0)); // track the visited positions
    queue<pair<pair<int, int>, int> > q;

    q.push({{m, n}, 0}); // initial positions (m, n) and step = 0
    visited[m][n] = 1;

    while (! q.empty()) {
        
        int x, y = q.front().first.first; q.front().first.second;
        int step = q.front().second;
        q.pop();

        if (x == r && y == s) {
            return step;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= size && ny >= 1 && ny <= size && ! visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({{nx, ny}, step + 1});
            }
        }
    }
    return -1; // target not found
    
}

int main() {
    
    int size, m, n, p, q; // position (m, n), target(p, q)
    cin >> size;
    cin >> m >> n >> p >> q;

    int stepCount = knightMoves(size, m, n, p, q);

    cout  << stepCount ;
    

    return 0;
}