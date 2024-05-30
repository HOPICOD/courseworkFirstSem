#include <iostream>
using namespace std;

void show_greeting() {
	cout << "Student of group 4307, Bakhmetov Kirill Alexeyevich. 2024" << endl;
	cout << "Option 3" << endl;
	cout << "Coursework" << endl;
	cout << "It is necessary to create a console program to sort the data array using the following methods: " << endl;
	cout << "bubble sort, selection sort, insertion sort, shell sort, and quicksort." << endl;
	cout << "Display unordered(once) and ordered(for each of the methods) data arrays." << endl;
	cout << "Create a comparative table of the effectiveness of the methods," << endl;
	cout << "in which it is necessary to specify the number of comparisons and permutations of variables in each sorting method" << endl;

	cout << "The unordered matrix of N rows and M columns is inputted once" << endl;
	cout << "(from the keyboard, file, or generated randomly) and is then used for each sorting method." << endl << endl;

	cout << "Task: Arrange each column of the matrix in descending order of absolute values" << endl << endl;
}

void show_task() {
	cout << "[1] - Set matrix by user input" << endl;
	cout << "[2] - Set matrix by random values" << endl;
	cout << "[3] - Set matrix from file" << endl;
	cout << "[4] - Save matrix" << endl;
	cout << "[5] - Run sorts" << endl;
	cout << "[6] - Run tests" << endl;
	cout << "[7] - Exit" << endl;
	//cout << "6 - exit" << endl;
}