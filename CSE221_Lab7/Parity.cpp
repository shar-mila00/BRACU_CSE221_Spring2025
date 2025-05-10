#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NUM = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //input 
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> list1(edges), list2(edges), weight(edges);

    for (int i = 0; i < edges; i++) cin >> list1[i];
    for (int i = 0; i < edges; i++) cin >> list2[i];
    for (int i = 0; i < edges; i++) cin >> weight[i];

    vector<vector<pair<int, int> > > graph(vertices + 1);

    for (int i = 0; i < edges; i++) {
        graph[list1[i]].emplace_back(list2[i], weight[i]);
    }

    // parity state : even 0, odd 1
    vector<vector<ll> > dist(vertices + 1, vector<ll>(2, NUM)); // 2D array to track min distance for both state
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int> >, greater<> > pq; // distance, node, parity

    // shortest distance from 1 to vertices, no consequtive parity
    pq.emplace(0, 1, -1); // distance, node, last parity used

    while (! pq.empty()) {

        auto [d, node, lastParity] = pq.top();
        pq.pop();

        for (auto &[next, w] : graph[node]) {

            int parity = w % 2;
             // If last_parity is set and same as current, skip
            if (lastParity != -1 && parity == lastParity) 
            continue;

            if (d + w < dist[next][parity]) {
                dist[next][parity] = d + w;
                pq.emplace(dist[next][parity], next, parity);
            }
        }
    }

    ll result = min(dist[vertices][0], dist[vertices][1]);
    cout << (result == NUM ? -1 : result) << '\n';

    return 0;
}