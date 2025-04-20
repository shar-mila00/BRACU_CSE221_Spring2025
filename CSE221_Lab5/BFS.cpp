#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int vertices, edges;
    cin >> vertices >> edges;
    // adjacent list
    vector<int> adjList[vertices + 1];
    
    int m, n;
    for (int i = 0; i < edges; i++) {
        cin >> m >> n;
        adjList[m].push_back(n);
        adjList[n].push_back(m);
    }

    // BFS part
    queue<int> q;
    vector<bool> visited(vertices + 1, 0);
    vector<int> result; 

    q.push(1);
    visited[1] = 1;

    int node;

    while (! q.empty()) {
        node = q.front();
        q.pop();
        result.push_back(node);

        // looking into it's unvisited nodes
        for (int i = 0; i < adjList[node].size(); i++) {
            if (! visited[adjList[node][i]]) {
                visited[adjList[node][i]] = 1;
                q.push(adjList[node][i]); 
            }
        }
    }

    // print 
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}