#include <iostream>
#include "input.h"
#include "menu.h"
#include "tasks.h"
#include "sorts.h"
#include "tests.h"
#include "files.h"


enum MENU{SET_MATRIX_BY_USER = 1, SET_MATRIX_BY_RANDOM, SET_MATRIX_FROM_FILE, SAVE_MATRIX, RUN_SORTS, TESTS, EXIT};

int main(){
	bool repeat = true;
	int user_choice = 0;
	vector<vector<double>> matrix;
	show_greeting();
	do {
		show_task();
		user_choice = input_int("Enter: ", 0, 8);
		switch (user_choice)
		{
		case(SET_MATRIX_BY_USER): {
			matrix = set_matrix_by_user_input();
			show_matrix(matrix, matrix.size(), "Your matrix:");
			break;
		}
		case(SET_MATRIX_BY_RANDOM): {
			matrix = set_matrix_by_random_value();
			show_matrix(matrix, matrix.size(), "Your matrix:");
			break;
		}
		case(SET_MATRIX_FROM_FILE): {
			load_data(matrix);
			show_matrix(matrix, matrix.size(), "Your matrix:");
			break;
		}
		case(SAVE_MATRIX): {
			save_matrix(matrix);
			break;
		}
		case(RUN_SORTS): {
			run_sorts(matrix);
			break;
		}
		case(EXIT): {
			repeat = false;
			break;
		}
		case(TESTS): {
			test_sorts();
			break;
		}
		default:
			cout << "Wrong input!" << endl;
			break;
		}
	} while (repeat);
}

