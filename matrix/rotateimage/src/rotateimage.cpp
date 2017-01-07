/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <algorithm>
#include "rotateimage.h"

void rotateimage::dummy() {
}

void rotateimage::RotateNNImage(vector<vector<int>> &image) {
    int row = image.size();
    int col = image[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            std::swap(image[i][j], image[j][i]);
        }
        std::reverse(image[i].begin(), image[i].end());
    }
}


