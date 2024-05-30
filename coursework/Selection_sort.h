#pragma once

#include "Isort.h"

#include <vector>

using namespace std;

class Selection_sort : public Isort {
public:
	void sort(vector<vector<double>>& matrix) override {
		for (int col = 0; col < matrix[0].size(); col++) {
				for (int i = 0; i < matrix.size() - 1; i++) {
					int maxIndex = i;
					for (int j = i + 1; j < matrix.size(); j++) {
						this->comparsion_counter++;
						if (abs(matrix[j][col]) > abs(matrix[maxIndex][col])) {
							maxIndex = j;
					}
				}
				if (maxIndex != i) {
					swap(matrix[i][col], matrix[maxIndex][col]);
					this->swap_counter++;
					}
			}
		}
	}
};