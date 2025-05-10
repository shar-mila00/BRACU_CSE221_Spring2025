#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NUM = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // input
    int vertices, edges, source, des;
    cin >> vertices >> edges >> source >> des;

    vector<ll> weight(vertices + 1);
    for (int i = 1; i <= vertices; i++) cin >> weight[i];

    vector<vector<int> > graph(vertices + 1);
    int u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].emplace_back(v);
    }

    vector<ll> dist(vertices + 1, NUM);
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq; // (distance, node)

    dist[source] = weight[source];
    pq.emplace(weight[source], source);

    while (! pq.empty()) {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto i : graph[node]) {
            ll new_dis = d + weight[i];
            if (new_dis < dist[i]) {
                dist[i] = new_dis;
                pq.emplace(new_dis, i);
            }
        }
    }

    if (dist[des] == NUM) {
        cout << -1 << endl;
    } else {
        cout << dist[des] << endl;
    }

    return 0;
}