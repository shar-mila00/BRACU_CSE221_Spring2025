#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxNum(int player, vector<vector<int> >& graph) {

    queue<int> q;
    vector<int> color(player + 1, -1);
    int maxN = 0;
    int robot, human;

    for (int i = 1; i <= player; i++) {
        if (color[i] == -1) {
            
            q.push(i);
            color[i] = 0;
            robot = 1, human = 0; // 0 for robot, 1 for human

            while (! q.empty()) {
                int node = q.front(); 
                q.pop();

                for (int k : graph[node]) {
                    if (color[k] == -1) {
                        color[k] = 1 - color[node];

                        if (color[k] == 0) {
                            robot ++;
                        } else {
                            human ++;
                        }
                        q.push(k);
                    } else if (color[k] == color[node]) {
                        return -1;
                    }
                }
            }
            maxN += max(robot, human);
        }
    }
    return maxN;
}

int main() {

    int player, tackle;
    cin >> player >> tackle;

    // input
    vector<vector<int> > graph(player + 1);
    int u, v;

    for (int i = 0; i < tackle; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maxCount = maxNum(player, graph);
    cout << maxCount;
    return 0;
}