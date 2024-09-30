void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Reverse the matrix so that we can find the transpose
    reverse(matrix.begin(), matrix.end());

    // Now find the transpose of matrix inorder to get final rotation
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}