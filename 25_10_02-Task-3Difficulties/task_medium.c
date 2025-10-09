#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>> &mat) {
    
    // flatten the matrix into a 1-dimensional array
    vector<int> arr;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            arr.push_back(mat[i][j]);
        }
    }

    // sort the array
    sort(arr.begin(), arr.end());

    // find the median element
    int mid = arr.size() / 2;
    return arr[mid];
}

int main() {
    vector<vector<int>> matrix = 
                        {{1, 3, 5}, 
                         {2, 6, 9}, 
                         {3, 6, 9}};
    cout << median(matrix) << endl;
    return 0;
}
