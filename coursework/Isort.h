#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Isort {

protected:

		int swap_counter = 0;

		int comparsion_counter = 0;

public:
	virtual ~Isort() = default;
	virtual void sort(vector<vector<double>>& matrix) = 0;

	int get_swap_counter() { return swap_counter; };
	int get_comparsion_counter() { return comparsion_counter; };

	void show_counters() {

		cout << "Swaps: " << swap_counter << endl;
		cout << "Comparsion: " << comparsion_counter << endl;
	}

	void reset_counters() {

		swap_counter = 0;
		comparsion_counter = 0;
	}
};