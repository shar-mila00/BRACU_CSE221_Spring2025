#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// bfs function
vector<int> bfs(int source, int des, const vector<vector<int> >& adjList, vector<int>& distance, vector<int>& parent) {
    queue<int> q;

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

    return distance;

}

// path
vector<int> pathFind(int node, vector<int>& parent) {
    vector<int> path;

        for (int i = node; i != -1; i = parent[i]) {
            path.push_back(i);
        }

    reverse(path.begin(), path.end());    
    return path;    
}

int main() {

    // input 
    int vertices, edges, source, des, key;
    cin >> vertices >> edges >> source >> des >> key;

    // adjacent list / directed graph
    vector<vector<int> > adjList(vertices + 1);
    int m , n;
    for (int i = 0; i < edges; i++) {
        cin >> m >> n;
        adjList[m].push_back(n);
    }

    vector<int> dist1(vertices + 1, -1), parent1(vertices + 1, -1);
    bfs(source, key, adjList, dist1, parent1);

    vector<int> dist2(vertices + 1, -1), parent2(vertices + 1, -1);
    bfs(key, des, adjList, dist2, parent2);

    if (dist1[key] == -1 || dist2[des] == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path1 = pathFind(key, parent1);
    vector<int> path2 = pathFind(des, parent2);

    // Avoid repeating key
    path2.erase(path2.begin());

    vector<int> full_path = path1;
    full_path.insert(full_path.end(), path2.begin(), path2.end());

    cout << full_path.size() - 1 << endl;
    for (int node : full_path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}