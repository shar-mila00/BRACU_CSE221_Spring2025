#include <bits/stdc++.h>
using namespace std;

const long long NUM = 1e18;

// function to return distance
vector<long long> shortestPath(int vertices, int source, vector<vector<pair<int, long long> > > &graph) {

    vector<long long> dist(vertices + 1, NUM);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<>> pq; // (distance, node)

    dist[source] = 0;
    pq.emplace(0, source);

    while (! pq.empty()) {
        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
        continue;

        for (auto neighbour : graph[node]) {
            int next = neighbour.first;
            long long w = neighbour.second;
            if (dist[node] + w < dist[next]) {
                dist[next] = dist[node] + w;
                pq.emplace(dist[next], next);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //input
    int vertices, edges, S, T;
    cin >> vertices >> edges >> S >> T;

    vector<vector<pair<int, long long> > > graph(vertices + 1);
    int u, v;
    long long weight;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight); // directed weighted graph
    }

    vector<long long> Alice = shortestPath(vertices, S, graph);
    vector<long long> Bob = shortestPath(vertices, T, graph);

    long long minTime = NUM;
    int meet = -1;

    for (int i = 1; i <= vertices; i++) {

        if (Alice[i] < NUM && Bob[i] < NUM) {
            long long time = max(Alice[i], Bob[i]); // total time taken by the max distance as one can wait for other
            if (time < minTime || (time == minTime && i < meet)) {
                minTime = time;
                meet = i;
            }
        }
    }

    if (meet == -1) {
        cout << -1;
    } else {
        cout << minTime << " " << meet << endl;
    }
    return 0;
}