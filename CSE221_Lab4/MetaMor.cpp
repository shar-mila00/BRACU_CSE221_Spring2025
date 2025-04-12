#include <iostream>
using namespace std;
#include <vector>

int main() {
    int vertices;
    cin >> vertices;
    
    // 2D matrix
    vector<vector<int> > matrix(vertices, vector<int>(vertices, 0));
    for (int i = 0; i < vertices; i++) {
        int node;
        cin >> node;

        int neighbour;
        for (int j = 1; j <= node; j++) {
            cin >> neighbour;
            matrix[i][neighbour] = 1;
        }
    }

    // print
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}