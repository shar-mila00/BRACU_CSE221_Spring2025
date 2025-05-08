#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int course, req;
    cin >> course >> req;

    vector<vector<int> > courseList(course + 1);
    vector<int> inDegree(course + 1, 0);

    int u, v;
    for (int i = 0; i < req; i++) {
        cin >> u >> v;
        courseList[u].push_back(v);
        inDegree[v]++;
        
    }

    queue<int> q;
    vector<int> result;

    // topological sort
    for (int i = 1; i <= course; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (! q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto j : courseList[node]) {
            inDegree[j] --;
            if (inDegree[j] == 0) {
                q.push(j);
            }
        }
    }

    if (result.size() != course) {
        cout << -1;
    } else {
        for (int i : result) {
            cout << i << " ";
        }
    }
    return 0;
}