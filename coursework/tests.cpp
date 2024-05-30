#include "Bubble_sort.h"
#include "Selection_sort.h"
#include "Insertion_sort.h"
#include "Shell_sort.h"
#include "Quick_sort.h"

#include <cassert>

bool is_tests_right() {
	Bubble_sort bubble_sort_test;
	Selection_sort selection_sort_test;
	Insertion_sort insertion_sort_test;
	Shell_sort Shell_sort_test;
	Quick_sort quick_sort_test;

	vector<vector<double>> matrix_to_test_bubble_sort = {
		{ -1.0, -4.0, 1.0 },
		{ 3.0, 2.0, -2.0 },
		{ 0.0, -3.0, 5.0 }
	};

	vector<vector<double>> expected_matrix_to_test_bubble_sort = {
		{ 3.0, -4.0, 5.0 },
		{ -1.0, -3.0, -2.0 },
		{ 0.0, 2.0, 1.0 }
	};

	bubble_sort_test.sort(matrix_to_test_bubble_sort);
	assert(matrix_to_test_bubble_sort == expected_matrix_to_test_bubble_sort);

	vector<vector<double>> matrix_to_test_selection_sort = {
		{ -11.0, -42.02, 1.0 },
		{ -13.0, 2.5, -21.05 },
		{ 0.0, -3.0, 51.32 }
	};

	vector<vector<double>> expected_matrix_to_test_selection_sort = {
		{ -13.0, -42.02, 51.32 },
		{ -11.0, -3.0, -21.05 },
		{ 0.0, 2.5, 1.0 }
	};

	selection_sort_test.sort(matrix_to_test_selection_sort);
	assert(matrix_to_test_selection_sort == expected_matrix_to_test_selection_sort);

	vector<vector<double>> matrix_to_test_insertion_sort = {
		{ -114.0, -422.02, 15.0 },
		{ -1305.0, 2.15, -211.05 },
		{ 10.0, -31.0, 5132.32 }
	};

	vector<vector<double>> expected_matrix_to_test_insertion_sort = {
		{ -1305.0, -422.02, 5132.32 },
		{ -114.0, -31.0, -211.05 },
		{ 10.0, 2.15, 15.0 }
	};

	insertion_sort_test.sort(matrix_to_test_insertion_sort);
	assert(matrix_to_test_insertion_sort == expected_matrix_to_test_insertion_sort);

	vector<vector<double>> matrix_to_test_Shell_sort = {
		{ -11.0, -42.02, 1.0 },
		{ -5.023, -1.302, -12.052 },
		{ -13.0, 0.5, -21.05 },
		{ 0.0, -3.0, 51.32 }
	};

	vector<vector<double>> expected_matrix_to_test_Shell_sort = {
		{ -13.0, -42.02, 51.32 },
		{ -11.0, -3.0, -21.05 },
		{ -5.023, -1.302, -12.052 },
		{ 0.0, 0.5, 1.0 }
	};

	Shell_sort_test.sort(matrix_to_test_Shell_sort);
	assert(matrix_to_test_Shell_sort == expected_matrix_to_test_Shell_sort);

	vector<vector<double>> matrix_to_test_quick_sort = {
		{ -11.0, -42.02, 1.0 },
		{ -13.0, 2.5, -21.05 },
		{ 0.0, 0.5, 1.0 },
		{ 0.0, -3.0, 51.32 }
	};

	vector<vector<double>> expected_matrix_to_test_quick_sort = {
		{ -13.0, -42.02, 51.32 },
		{ -11.0, -3.0, -21.05 },
		{ 0.0, 2.5, 1.0 },
		{ 0.0, 0.5, 1.0 }
	};

	insertion_sort_test.sort(matrix_to_test_quick_sort);
	assert(matrix_to_test_quick_sort == expected_matrix_to_test_quick_sort);

	return true;
}


void test_sorts() {

	if (is_tests_right()) {
		cout << "All tests passed succesfully!" << endl;
	}
	else {
		cout << "Tests failed!" << endl;
	}
}