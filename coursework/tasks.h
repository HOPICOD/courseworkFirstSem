#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> set_matrix_by_user_input();

vector<vector<double>> set_matrix_by_random_value();

void load_data(vector<vector<double>>& matrix);

void show_matrix(const vector<vector<double>>& matrix, size_t size, string message);

void show_table(vector<vector<string>>& table, size_t size, string message);

void replace_negative_zero(std::vector<std::vector<double>>& matrix);

//void save_data(vector<vector<double>>& matrix, string filename);