#include <iostream>
#include <vector>
using namespace std;

int main() {

    int vertices, edges;
    cin >> vertices >> edges;

    int arr1[edges];
    int arr2[edges];

    for (int i = 0; i < edges; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < edges; i++) {
        cin >> arr2[i];
    }

    // list
    vector<int> result[vertices];

    for (int i = 0; i < edges; i++) {
        
        result[arr1[i] - 1].push_back(arr2[i]);
        result[arr2[i] - 1].push_back(arr1[i]);
        
    }
    
    int oddDegree = 0;

    for (int i = 0; i < vertices; i++) {
        if ((result[i].size())%2 != 0) {
            oddDegree++;
        }
    }
    if (oddDegree == 0 || oddDegree == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}