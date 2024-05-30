#pragma once

#include "Isort.h"

#include <vector>

using namespace std;

class Bubble_sort : public Isort {
public:
	void sort(vector<vector<double>>& matrix) override {
		for (int col = 0; col < matrix[0].size(); col++) {
			bool swapped = false;
			do {
				swapped = false;
				for (int i = 0; i < matrix.size() - 1; i++) {
					this->comparsion_counter++;
					if (abs(matrix[i][col]) < abs(matrix[i + 1][col])) {
						swap(matrix[i][col], matrix[i + 1][col]);
						this->swap_counter++;
						swapped = true;
					}
				}
			} while (swapped);
		}
	}
};