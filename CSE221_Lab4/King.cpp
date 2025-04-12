#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int boardSize;
    cin >> boardSize;

    int row, col; // position
    cin >> row >> col;

    vector<pair<int, int> > result;

    int count = 0;

    if ((row - 1) > 0) {
        result.push_back({row - 1, col});
        count++;
        if (col - 1 > 0) {
            result.push_back({row, col - 1});
            result.push_back({row - 1, col - 1});
            count += 2;
        }
        
        if (boardSize - col > 0) {
            result.push_back({row, col + 1});
            result.push_back({row - 1, col + 1});
            count += 2;
        } 
    } else {

        if (col - 1 > 0) {
            result.push_back({row, col - 1});
            count += 1;
        }
        
        if (boardSize - col > 0) {
            result.push_back({row, col + 1});
            count += 1;
        }
    }

    if (boardSize - row > 0) {
        result.push_back({row + 1, col});
        count++;

        if (col - 1 > 0) {
            result.push_back({row + 1, col - 1});
            count += 1;
        }
        
        if (boardSize - col > 0) {
            result.push_back({row + 1, col + 1});
            count += 1;
        }
    }
    
    sort(result.begin(), result.end());
    cout << count << endl;
    
    for (auto i : result) {
        cout << i.first << " " << i.second << " \n";
    }
    return 0;
}