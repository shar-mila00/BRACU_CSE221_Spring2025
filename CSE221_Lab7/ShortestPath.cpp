#include <bits/stdc++.h>
using namespace std;

const long long NUM = 1e18; // taking a very long number
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input
    int vertices, edges, source, des;
    cin >> vertices >> edges >> source >> des;

    vector<int> list1(edges), list2(edges);
    vector<long long> weight(edges); // weight can be very long number

    for (int i = 0; i < edges; i++) cin >> list1[i];
    for (int i = 0; i < edges; i++) cin >> list2[i];
    for (int i = 0; i < edges; i++) cin >> weight[i];

    // adjacent list
    vector<vector<pair<int, long long> > > graph(vertices + 1);
    for (int i = 0; i < edges; i++) {
        graph[list1[i]].emplace_back(list2[i], weight[i]); // directed weighted graph
    }

    // traking explored nodes, the distances and parents corresponding to the nodes
    // vector<bool> explored(vertices + 1, 0);
    vector<long long> distance(vertices + 1, NUM);
    vector<int> parent(vertices + 1, -1);

    // priority queue (distance, nodes) to retrieve the shortest path
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

    distance[source] = 0;
    pq.emplace(0, source);

    while (! pq.empty()) {

        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > distance[node]) 
        continue;

        // otherwise mark explored
        //explored[node] = 1;

        if (node == des) {
            break;
        }

        for (auto neighbour : graph[node]) {
            int next = neighbour.first;
            long long dis = neighbour.second;

            if (distance[node] + dis < distance[next]) {
                distance[next] = distance[node] + dis;
                parent[next] = node;
                pq.emplace(distance[next], next);
            }
        }
    }

    // output
    if (distance[des] == NUM) {
        cout << -1 << endl;
    } else {

        vector<int> path;
        for (int i = des; i != -1; i = parent[i]) {
            path.push_back(i);
        }

        reverse(path.begin(), path.end());

        cout << distance[des] << endl;

        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}