#include <bits/stdc++.h>
using namespace std;

const long long NUM = 1e18;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // input
    int city , road;
    cin >> city >> road;

    vector<vector<pair<int, long long> > > graph(city + 1);
    int u, v;
    long long weight;
    for (int i = 0; i < road; i++) {
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }

    vector<long long> dist(city + 1, NUM);
    // vector<bool> explored(city + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<> > pq;
    dist[1] = 0;
    pq.emplace(0, 1); // distance, node

    while (! pq.empty()) {
        long long d = pq.top().first; 
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) 
        continue;

        // explored[node] = 1;

        for (auto neighbour : graph[node]) {
            int next = neighbour.first; 
            long long new_dis = max(dist[node], neighbour.second);
            if (new_dis < dist[next]) {  // more weight of a path, more danger, not the sum of the path
                dist[next] = new_dis;
                pq.emplace(dist[next], next);
            }
        }
    }

    for (int i = 1; i <= city; i++) {
        if (dist[i] == NUM) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    return 0;
}