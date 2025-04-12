#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> result(vertices, 0);

    int node;
    for (int i = 0; i < edges; i++) {
        cin >> node;
        result[node - 1]--; // out degree
    }

    for (int j = 0; j < edges; j++) {
        cin >> node;
        result[node - 1]++;
    }

    for (int i = 0; i < vertices; i++) {
        cout << result[i] << " ";
    }
    return 0;
}