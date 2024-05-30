#pragma once

#include "Isort.h"

#include <vector>

using namespace std;

class Quick_sort : public Isort {
public:
    void sort(std::vector<std::vector<double>>& matrix) override {
        size_t numRows = matrix.size();
        size_t numCols = matrix[0].size();

        for (int col = 0; col < numCols; col++) {
            quick_sort_column(matrix, col, 0, static_cast<int>(numRows) - 1);//ѕреобразование size_t в int, чтобы не было предупреждени€
        }
    }

private:
    void quick_sort_column(vector<vector<double>>& matrix, int col, int low, int high) {
        if (low < high) {
            int pi = partition(matrix, col, low, high);
            quick_sort_column(matrix, col, low, pi - 1);
            quick_sort_column(matrix, col, pi + 1, high);
        }
    }

    int partition(vector<vector<double>>& matrix, int col, int low, int high) {
        double pivot = std::abs(matrix[high][col]);
        int i = low - 1;

        for (int j = low; j < high; j++) {
            this->comparsion_counter++;
            if (std::abs(matrix[j][col]) >= pivot) {
                i++;
                if (i != j) {
                    swap(matrix[i][col], matrix[j][col]);
                    this->swap_counter++;
                }
            }
        }
        if (i + 1 != high) {        
            swap(matrix[i + 1][col], matrix[high][col]);
            this->swap_counter++;
        }
        return i + 1;
    }
};