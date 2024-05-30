#include <iostream>
#include <vector>
#include "input.h"
#include "files.h"

using namespace std;


void replace_negative_zero(std::vector<std::vector<double>>& matrix) {
	for (auto& row : matrix) {
		for (auto& val : row) {
			if (val == 0.0) {
				val = 0.0; // Убедиться, что -0 становится 0
			}
		}
	}
}

vector<vector<double>> set_matrix_by_user_input() {

	int rows = input_int("Enter number of rows: ", 0, INT_MAX);
	int columns = input_int("Enter number of colums: ", 0, INT_MAX);

	vector<vector<double>> matrix(rows, vector<double>(columns));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			cout << "Enter matrix[" << i+1 << "][" << j+1 << "]: ";
			matrix[i][j] = input_double("", -DBL_MAX, DBL_MAX);
		}
	}
	replace_negative_zero(matrix);
	return matrix;
}

vector<vector<double>> set_matrix_by_random_value() {

	int rows = input_int("Enter number of rows: ", 0, INT_MAX);
	int columns = input_int("Enter number of colums: ", 0, INT_MAX);

	vector<vector<double>> matrix(rows, vector<double>(columns));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			double random_number = (std::rand() % 10000) / 100.0 - 50.0;
			matrix[i][j] = random_number;
		}
	}
	replace_negative_zero(matrix);
	return matrix;
}

void load_data(vector<vector<double>>& matrix) {
	string filepath = get_valid_filepath();

	vector<vector<double>> matrix_from_file = load_matrix_from_file(filepath);

	if(matrix_from_file.empty()) { cerr << "Error reading from file" << endl; }
	else {
		matrix = matrix_from_file;
	}
}




void show_matrix(const vector<vector<double>>& matrix, size_t size, string message) {
	if (matrix.empty()) { return; }
	cout << message << endl << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;                  
	}
}

void show_table(vector<vector<string>>& table, size_t size, string message) {
	
	cout << message << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < table[i].size(); j++) {

			cout << table[i][j] << "\t";
		}
		cout << endl;
	}
}

//void save_data(vector<vector<double>>& matrix) {
//	if (matrix.empty()) { cout << "Your matrix is empty!" << endl; return; }
//
//	else {
//		save_matrix_with_results_to_file(matrix);
//	}
//}