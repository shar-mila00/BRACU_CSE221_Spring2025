#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

    // input
    int vertices, edges, source, des;
    cin >> vertices >> edges >> source >> des;

    vector<int> u1(edges), u2(edges);
    for (int i = 0; i < edges; i++) {
        cin >> u1[i];
    }

    for (int i = 0; i < edges; i++) {
        cin >> u2[i];
    }

    // adjacency list
    vector<int> adjList[vertices + 1];
    for (int i = 0; i < edges; i++) {
        adjList[u1[i]].push_back(u2[i]);
        adjList[u2[i]].push_back(u1[i]);
    }

    // to print lexicographily
    for (int i = 1; i <= vertices; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    // an array for storing distance and another one for storing parents and a queue

    queue<int> q;
    vector<int> distance(vertices + 1, -1);
    vector<int> parent(vertices + 1, -1);

    int node;
    q.push(source);
    distance[source] = 0;

    bool isDes = false; // track if found

    // BFS 
    while (! q.empty() && ! isDes) {

        node = q.front();
        q.pop();

        for (auto i : adjList[node]) {
            if (distance[i] == -1) {
                distance[i] = distance[node] + 1;
                parent[i] = node;
                q.push(i);

                if (i == des) {
                    isDes = true;
                    break;
                }
            }
        }
    }

    if (distance[des] == -1) {
        cout << -1 << endl;
    } else {
        cout << distance[des] << endl;

        // for the path
        vector<int> shortestPath;
        for (int i = des; i != -1; i = parent[i]) {
            shortestPath.push_back(i);
        }

        reverse(shortestPath.begin(), shortestPath.end());

        for (int k : shortestPath) {
            cout << k << " ";
        }
    }
    return 0;
}