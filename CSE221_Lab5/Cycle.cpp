#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(int node, const vector<vector<int> >& adjList, vector<bool>& path, vector<bool> visited) {

    // mark visited node and path node
    visited[node] = 1;
    path[node]= 1;

    for (int i : adjList[node]) {

        // check repeat of a node in path
        if (path[i]) {
            return true;
        }

        // check if visited, no need to go to the same path with no cycle
        if (! visited[i] && detectCycle(i, adjList, path, visited)) {
            return true;
        }
    }

    // if no cycle + end of branch, path[node] should be unmarked while backtracking
    path[node] = 0;
    return false;
}

int main() {

    // input
    int vertices, edges;
    cin >> vertices >> edges;

    // adjacent list / directed graph
    vector<vector<int> > adjList(vertices + 1);
    int m , n;
    for (int i = 0; i < edges; i++) {
        cin >> m >> n;
        adjList[m].push_back(n);
    }

    vector<bool> path(vertices + 1, 0), visited(vertices + 1, 0);

    bool ans = false;

    // there may be disconnected nodes
    for (int i = 1; i <= vertices; i++) {
        if (! visited[i] && detectCycle(i, adjList, path, visited)) {
            ans = true;
        }
    }

    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}