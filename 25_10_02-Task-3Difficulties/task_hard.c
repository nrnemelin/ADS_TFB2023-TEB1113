#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find the maximum area of 
// rectangle in a histogram.
int getMaxArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    int res = 0;
    
    for (int i = 0; i < n; i++) {
      
        // Process all bars that are higher or equal to current
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            int tp = s.top(); 
            s.pop();

            // Width between previous smaller (stack top) and current index
            int width = s.empty() ? i : i - s.top() - 1;
            
            res = max(res, heights[tp] * width);
        }
        s.push(i);
    }

    // Process remaining bars in stack
    while (!s.empty()) {
        int tp = s.top(); 
        s.pop();

        int width = s.empty() ? n : n - s.top() - 1;
        res = max(res, heights[tp] * width);
    }

    return res;
}

// Function to find the maximum area of rectangle
// in a 2D matrix.
int maxArea(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    
    // heights will store histogram heights
    vector<int> heights(m, 0);
    int ans = 0;
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
       
            // Update histogram heights
            if (mat[i][j] == 1) heights[j]++;
            else heights[j] = 0;
        }
        ans = max(ans, getMaxArea(heights));
    }
    
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };
         
    cout << maxArea(mat) << endl;  
    
    return 0;
}
