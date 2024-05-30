#pragma once

#include "Isort.h"

#include <vector>

using namespace std;

class Insertion_sort : public Isort {
public:
	void sort(vector<vector<double>>& matrix) override {
		for (int col = 0; col < matrix[0].size(); col++) {
			for (int i = 1; i < matrix.size(); i++) {
				for (int j = i; j > 0; j--) {
					this->comparsion_counter++;
						if (abs(matrix[j - 1][col]) >= abs(matrix[j][col])) {
							break;
						}
						this->swap_counter++;
						swap(matrix[j - 1][col], matrix[j][col]);	 
				}
			}
		}
	}
};