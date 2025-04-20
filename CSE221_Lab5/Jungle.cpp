#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    
    // input 
    int vertices, edges, source, des, key;
    cin >> vertices >> edges >> source >> des >> key;

    // adjacent list / directed graph
    vector<int> adjList[vertices + 1];
    int m , n;
    for (int i = 0; i < edges; i++) {
        cin >> m >> n;
        adjList[m].push_back(n);
    }

    // array to store distance and parent node
    vector<int> distance(vertices + 1, -1);
    vector<int> parent(vertices + 1, -1);
    queue<int> q;

    // BFS
    q.push(source);
    distance[source] = 0;

    bool isFound = false;
    int node;
    while (! q.empty() && ! isFound) {
        node = q.front();
        q.pop();

        for (auto x : adjList[node]) {
            if (distance[x] == -1) {
                distance[x] = distance[node] + 1;
                parent[x] = node;
                q.push(x);

                if (x == des) {
                    isFound = true;
                    break;
                }
            }
        }
    }

    // output
    if (distance[des] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> path;

        for (int i = des; i != -1; i = parent[i]) {
            path.push_back(i);
        }
        
        auto f = find(path.begin(), path.end(), key);

        if (f != path.end()) {
            cout << distance[des] << endl;
            reverse(path.begin(), path.end());

            for (int i : path) {
                cout << i << " ";
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}