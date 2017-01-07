/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
*/

#include "setmatrixzeros.h"

void setmatrixzeros::dummy() {
}

void setmatrixzeros::SetMatrixZeros(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    bool flag_row = false;
    bool flag_col = false;
    for (int i = 0; i < col; ++i) if (matrix[0][i] == 0) flag_row = true;
    for (int i = 0; i < row; ++i) if (matrix[i][0] == 0) flag_col = true;

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (flag_row) for (int i = 0; i < col; ++i) matrix[0][i] = 0;
    if (flag_col) for (int i = 0; i < row; ++i) matrix[i][0] = 0;
}
