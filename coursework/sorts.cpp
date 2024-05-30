#include "Bubble_sort.h"
#include "Selection_sort.h"
#include "Insertion_sort.h"
#include "Shell_sort.h"
#include "Quick_sort.h"
#include "tasks.h"
#include "files.h"
#include "input.h"

#include <iostream>
#include <vector>
#include <string>

enum SAVE_MENU {SAVE = 1, DONT_SAVE};

vector<vector<string>> run_sorts(vector<vector<double>>& matrix) {

	vector<vector<string>> results{};

	if (matrix.empty()) { cout << "Your matrix is empty!" << endl; return results; }

	Bubble_sort bubble_sort;
	Selection_sort selection_sort;
	Insertion_sort insertion_sort;
	Shell_sort shell_sort;
	Quick_sort quick_sort;


	vector<vector<double>> vector_to_bubble_sort = matrix;
	vector<vector<double>> vector_to_selection_sort = matrix;
	vector<vector<double>> vector_to_insertion_sort = matrix;
	vector<vector<double>> vector_to_shell_sort = matrix;
	vector<vector<double>> vector_to_quick_sort = matrix;

	show_matrix(matrix, matrix.size(), "Original matrix:");

	cout << endl;


	bubble_sort.sort(vector_to_bubble_sort);
	show_matrix(vector_to_bubble_sort, vector_to_bubble_sort.size(), "Matrix sorted by the bubble method:");
	cout << endl;

	selection_sort.sort(vector_to_selection_sort);
	show_matrix(vector_to_selection_sort, vector_to_selection_sort.size(), "Matrix sorted by the selection method:");
	cout << endl;

	insertion_sort.sort(vector_to_insertion_sort);
	show_matrix(vector_to_insertion_sort, vector_to_insertion_sort.size(), "Matrix sorted by the insertion method:");
	cout << endl;
	
	shell_sort.sort(vector_to_shell_sort);
	show_matrix(vector_to_shell_sort, vector_to_shell_sort.size(), "Matrix sorted by the Shell method:");
	cout << endl;
	
	quick_sort.sort(vector_to_quick_sort);
	show_matrix(vector_to_quick_sort, vector_to_quick_sort.size(), "Matrix sorted by the quick method:");
	cout << endl;


	results = {
		{"Algorithm", "Swaps", "Comparisons"},
		{"Bubble sort", to_string(bubble_sort.get_swap_counter()), to_string(bubble_sort.get_comparsion_counter())},
		{"Selection sort", to_string(selection_sort.get_swap_counter()), to_string(selection_sort.get_comparsion_counter())},
		{"Insertion sort", to_string(insertion_sort.get_swap_counter()), to_string(insertion_sort.get_comparsion_counter())},
		{"Shell sort", to_string(shell_sort.get_swap_counter()), to_string(shell_sort.get_comparsion_counter())},
		{"Quick sort", to_string(quick_sort.get_swap_counter()), to_string(quick_sort.get_comparsion_counter())}
	};

	show_table(results, results.size(), "Results:");

	int user_choice;
	user_choice = input_int("Do you want to save results? (1 - Yes, 2 - No)", 0, 3);

	switch (user_choice) {
	case(SAVE): {
		save_matrix_with_results_to_file(matrix, vector_to_bubble_sort, vector_to_selection_sort, vector_to_insertion_sort, vector_to_shell_sort, vector_to_quick_sort, results);
	}
	case(DONT_SAVE): {

	}
	//default: cout << "Wrong input!" << endl;
	}

	

	bubble_sort.reset_counters();
	selection_sort.reset_counters();
	insertion_sort.reset_counters();
	shell_sort.reset_counters();
	quick_sort.reset_counters();

	return results;
}