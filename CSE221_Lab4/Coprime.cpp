#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2005;

vector<int> adj[MAXN];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Precompute the graph
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (gcd(i, j) == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Sort neighbor lists for binary access
    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Process queries
    while (Q--) {
        int X, K;
        cin >> X >> K;

        if (K > adj[X].size()) {
            cout << "-1\n";
        } else {
            cout << adj[X][K - 1] << "\n";
        }
    }

    return 0;
}
