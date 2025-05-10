#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll NUM = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertices, edges, source, des;
    cin >> vertices >> edges >> source >> des;

    // adjacent list, directed weighted graph
    vector<vector<pair<int, int> > > graph(vertices + 1);
    int u, v, w;
    
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    // 2D matrix for traking shortest & second shortest distance
    vector<vector<ll> > dist(vertices + 1, vector<ll>(2, NUM));
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

    pq.emplace(0, source);  // 0 for shortest distance, 1 for second shortest distance 
    dist[source][0] = 0;

    while (! pq.empty()) {

        auto [current_dist, node] = pq.top();
        pq.pop();

        for (auto [next, weight] : graph[node]) {

            ll new_dist = current_dist + weight;

            if (new_dist < dist[next][0]) {
                dist[next][1] = dist[next][0];
                dist[next][0] = new_dist;
                pq.emplace(new_dist, next);
            } else if (new_dist > dist[next][0] && new_dist < dist[next][1]) {
                dist[next][1] = new_dist;
                pq.emplace(new_dist, next);
            }
        }
    }

    cout << (dist[des][1] == NUM ? -1 : dist[des][1]) << '\n';
    return 0;
}