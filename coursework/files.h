#pragma once
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> load_matrix_from_file(string filename);

bool is_filepath_valid(string filepath);

bool is_filename_valid(string filename);

string get_valid_filepath();

void save_matrix_with_results_to_file(vector<vector<double>>& matrix, vector<vector<double>>& vector_to_bubble_sort, vector<vector<double>>& vector_to_selection_sort, 
	vector<vector<double>>& vector_to_insertion_sort, vector<vector<double>>& vector_to_shell_sort, vector<vector<double>>& vector_to_quick_sort, vector<vector<string>>& results);

bool file_exists(string filename);

bool confirm_overwrite(string filename);

string get_overwrite_confirmation(string& full_path);

void save_matrix(vector<vector<double>>& matrix);