#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include "input.h"

using namespace std;

bool file_exists(string filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(string filename) {

	const int YES = 1;

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;

	int user_choice = 0;

	user_choice = input_int("Enter menu item:", 0, 3);

	if (user_choice == YES) { return true; }

	return false;

}

vector<vector<double>> load_matrix_from_file(string filename) {

	vector<vector<double>> matrix;

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Unable to open file " << filename << endl;
		return matrix;
	}

	string line;
	while (getline(file, line)) {
		vector<double> row;
		double num;
		istringstream iss(line);
		bool valid_line = true; // ‘лаг дл€ проверки, содержит ли строка допустимые значени€
		bool any_numbers = false; // ‘лаг дл€ проверки, были ли извлечены числа из строки
		while (iss >> num) {
			row.push_back(num);
			any_numbers = true;
		}

		// ≈сли строка не содержит чисел или размер строки не совпадает с предыдущими строками, считаем ее недействительной
		if (!any_numbers || (matrix.size() > 0 && row.size() != matrix.back().size())) {
			valid_line = false;
		}

		// ≈сли строка содержит допустимые значени€, добавл€ем ее в матрицу
		if (valid_line) {
			matrix.push_back(row);
		}
		else {
			cerr << "Skipping invalid line:\"" << line << "\"" << endl;
		}
	}

	file.close();
	return matrix;
}


bool is_filepath_valid(string filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.txt$");

	if (!regex_match(filepath, file_path_regex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}


bool is_filename_valid(string filename) {
	regex filename_regex("^[^\\/:*?\"<>|]+\\.txt$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	regex filename_reserved_chars("[\\/:*?\"<>|]");

	if (!regex_match(filename, filename_regex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(filename, filename_reserved_names)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(filename, filename_reserved_chars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;
	bool is_name_valid = false;

	string filepath{ "" };

	while (!is_path_valid || !is_name_valid) {
		cout << "Enter fullpath with filename (only txt acceptable): " << endl;
		getline(cin, filepath);
		size_t pos = filepath.find_last_of("\\");

		if (pos > sizeof(filepath)) {

			if (is_filename_valid(filepath)) {

				is_path_valid = true;
				is_name_valid = true;

			}
		}

		if (pos != string::npos) {
			string filename = filepath.substr(pos + 1);
			string path = filepath.substr(0, pos + 1);

			if (is_filepath_valid(path + filename) && is_filename_valid(filename)) {
				is_path_valid = true;
				is_name_valid = true;
			}

		}
	}

	return filepath;
}

string get_overwrite_confirmation(string& full_path) {
	if (file_exists(full_path)) {
		if (!confirm_overwrite(full_path)) {
			cout << "Please choose another file." << endl;
			full_path = get_valid_filepath();
			return get_overwrite_confirmation(full_path);
		}
	}
	return full_path;
}

void save_matrix_with_results_to_file(vector<vector<double>>& matrix, vector<vector<double>>& vector_to_bubble_sort, vector<vector<double>>& vector_to_selection_sort,
	vector<vector<double>>& vector_to_insertion_sort, vector<vector<double>>& vector_to_shell_sort, vector<vector<double>>& vector_to_quick_sort, vector<vector<string>>& results) {
	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}
	file << "Original matrix:" << endl;
	for (auto& row : matrix) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}
	file << endl << endl;
	file << "Matrix sorted by the bubble method:" << endl;

	for (auto& row : vector_to_bubble_sort) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file << endl << endl;
	file << "Matrix sorted by the selection method:" << endl;

	for (auto& row : vector_to_selection_sort) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file << endl << endl;
	file << "Matrix sorted by the insertion method:" << endl;

	for (auto& row : vector_to_insertion_sort) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file << endl << endl;
	file << "Matrix sorted by the Shell method:" << endl;

	for (auto& row : vector_to_shell_sort) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file << endl << endl;
	file << "Matrix sorted by the quick method:" << endl;

	for (auto& row : vector_to_quick_sort) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file << endl << endl;
	
	for (auto& row : results) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " \t";
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}

	file.close();
}

void save_matrix(vector<vector<double>>& matrix) {
	if (matrix.empty()) { cout << "Your matrix is empty!" << endl; return; }
	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}
	for (auto& row : matrix) {
		for (size_t i = 0; i < row.size(); ++i) {
			file << row[i];
			if (i < row.size() - 1) {
				file << " "; // –азделение элементов в строке пробелом
			}
		}
		file << endl; // ѕереход на новую строку после каждой строки матрицы
	}
}