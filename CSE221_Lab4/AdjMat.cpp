#include <iostream>
using namespace std;
#include <vector>

// graph representation with adjacency matrix
// undirected weighted ,, if unweighted : 1/0

// declare 2D matrix

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    
    vector<vector<int> >adjMat(vertices, vector<int>(vertices, 0));
    // if (m*n) matrices, m, n and also weight needs to be taken
    int m, n, weight;

    for (int i = 0; i < edges; i++) {
        cin >> m >> n >> weight; // if unweighted , no weight variable neeeds to be taken
        adjMat[m-1][n-1] = weight; // if unweighted, it should be 1
        //adjMat[n][m] = weight; // as undirected (m, n) and (n, m) both needs to be filled 
    }

    //print matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}