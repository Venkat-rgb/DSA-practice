void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int col0 = 1;

    // Considering first row and first column as row and column array
    // Marking 0 in first row (or) first column, if that row (or) column contains 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                if (j == 0) {
                    col0 = 0;
                } else {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }

    // Marking the (n - 1) * (n - 1) to 0 based on first row and first column
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int row = matrix[i][0];
            int col = matrix[0][j];
            if (row == 0 || col == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Now mark the total first row to zeros if matrix[0][0] = 0  
    if(matrix[0][0] == 0) {
        // As matrix[0][0] = 0, we are starting from [0][1]
        for(int i = 1; i < n; ++i) {
            matrix[0][i] = 0;
        }
    }

    // Now mark the total first column to zeros if col0 = 0
    if(col0 == 0) {
        for(int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}