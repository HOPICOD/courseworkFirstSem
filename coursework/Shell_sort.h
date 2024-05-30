#pragma once

#include "Isort.h"

#include <vector>

using namespace std;

class Shell_sort : public Isort {
public:
	void sort(vector<vector<double>>& matrix) override {
		//for (int col = 0; col < matrix[0].size(); col++) {
		//	for (int step = matrix[col].size() / 2; step > 0; step / 2) {

		//		for (int i = step; i < matrix[col].size(); i++) {
		//			for (int j = i; j >= step; j -= step) {
		//				this->comparsion_counter++;
		//				if (abs(matrix[j - step][col]) >= abs(matrix[j][col])) {

		//					swap(matrix[j - step][col], matrix[j][col]);
		//					this->swap_counter++;
		//				}
		//			}

		//		}
		//	}
		//}
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        for (size_t col = 0; col < cols; col++) {
            for (size_t gap = rows / 2; gap > 0; gap /= 2) {
                for (size_t i = gap; i < rows; i++) {
                    double temp = matrix[i][col];
                    size_t j;
                    for (j = i; j >= gap; j -= gap) {
                        this->comparsion_counter++;
                        if (abs(matrix[j - gap][col]) >= abs(temp)) {
                            break;
                        }
                        matrix[j][col] = matrix[j - gap][col];
                        this->swap_counter++;
                    }
                    matrix[j][col] = temp;
                }
            }
        }
	}
};