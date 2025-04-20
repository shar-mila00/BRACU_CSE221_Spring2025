#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int> >& list, vector<bool>& visited, vector<int>& result) {

    visited[node] = 1;
    result.push_back(node);

    for (auto i : list[node]) {
        if (! visited[i]) {
            dfs(i, list, visited, result);
        }
    }
}

int main() {

    // input
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> list1(edges, 0), list2(edges, 0);
    for (int i = 0; i < edges; i++) {
        cin >> list1[i];
    }

    for (int i = 0; i < edges; i++) {
        cin >> list2[i];
    }

    // making adjacent list
    vector<vector<int> > adjList(vertices + 1);
    for (int i = 0; i < edges; i++) {
        adjList[list1[i]].push_back(list2[i]);
        adjList[list2[i]].push_back(list1[i]);
    }

    // take visited named array and a result array

    vector<bool> visited(vertices + 1, 0);
    vector<int> result;

    dfs(1, adjList, visited, result);

    // print
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}