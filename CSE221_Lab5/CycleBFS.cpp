#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    // input
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> InDegree(vertices + 1, 0);

    // adjacent list / directed graph
    vector<vector<int> > adjList(vertices + 1);
    int m , n;
    for (int i = 0; i < edges; i++) {
        cin >> m >> n;
        adjList[m].push_back(n);
        InDegree[n]++;
    }

    // topological sort
    queue<int> q;
    vector<int> result;

    // BFS
    //if Indegree[i] == 0, then push to queue
    for (int i = 1; i <= vertices; i++) {
        if (! InDegree[i]) {
            q.push(i);
        }
    }

    while (! q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int i : adjList[node]) {
            InDegree[i]--;
            if (! InDegree[i]){
                q.push(i);
            }
        }
    }

    int count = result.size();

    if (count == vertices) {
        cout << "NO\n"; // acyclic
    } else {
        cout << "YES\n";
    }


    return 0;
}