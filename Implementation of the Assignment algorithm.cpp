#include<bits/stdc++.h>
using namespace std;

int array3[100][2];

int count_number_of_assignments(int array[][100], int rows, int columns) {
// This function checks the number of assignments made. //
	int count = 0;

	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			if((array[i][j] == -200) || (array[i][j] == 0)) {
				count++;
			}
		}
	}

	return count;
}
int find_row_minimum(int array1[][100], int nrow, int columns) {
// This function calculates the minimum element present in a row to facilitate row minimum subtraction. //

	int minimum = INT_MAX;
	for(int j = 0; j < columns; j++) {
		if(array1[nrow][j] < minimum) {
			minimum = array1[nrow][j];
		}

		else {
			continue;
		}

	}

	return minimum;

}

int find_column_minimum(int array1[][100], int rows, int ncolumn) {
// This function helps in calculating the minimum element of a column inorder to facilitate column minimum subtraction. //
	int minimum = INT_MAX;

	for(int j = 0; j < rows; j++) {

		if(array1[j][ncolumn] < minimum) {
			minimum = array1[j][ncolumn];
		}

		else {
			continue;
		}
	}

	return minimum;
}

int find_zero_in_a_row(int array[][100], int nrow, int columns) {
// This function returns the index of the element whose value is 0 in a row. If the row has multiple such zeros then the functions returns -1. //
	int flag = 0;
	int index = -1;
	for(int j = 0; j < columns; j++) {

		if(array[nrow][j] == 0) {

			if(flag == 0) {
				index = j;
				flag = 1;
			}

			else {
				return -1;
			}
		}
	}

	return index;
}

int find_zero_in_a_column(int array[][100], int ncolumn, int rows) {
	// This function returns the index of the element whose value is 0 in a column. If the column has multiple such zeros then the functions returns -1. //
	int flag = 0;
	int index = -1;

	for(int j = 0; j < rows; j++) {

		if(array[j][ncolumn] == 0) {

			if(flag == 0) {
				index = j;
				flag = 1;
			}

			else {
				return -1;
			}
		}
	}

	return index;
}

int find_unassigned_row_index(int array[][100],  int nrow, int columns) {
// This function helps in ticking an unassigned column by returning the index of the row in which no assignment has been made. //
	int flag = 1;

	for(int i = 0; i < columns; i++) {

		if(array[nrow][i] == -200) {
			flag = 0;
		}
	}

	return flag;
}

int count_number_of_ones(int array[][100], int rows, int columns) {
// This function helps in finding the number of assigned rows. //
	int count = 0;

	for(int i = 0; i < rows; i++) {

		if(array[i][columns] == 1) {
			count++;
		}
	}

	return count;
}

int find_minimum_theta(int array[][100], int rows, int columns) {
// This function helps in finding the value of theta. //
	int minimum = INT_MAX;

	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			if((array[i][columns] == 1) && (array[rows][j] == -1)) {

				if(array[i][j] < minimum) {
					minimum = array[i][j];
				}
			}
		}
	}

	return minimum;
}
void newarray(int array[][100], int rows, int columns) {



	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			if((array[i][j] == -100) || (array[i][j] == -200)) {
				array[i][j] = 0;
			}
		}
	}


	for(int i = 0; i < rows; i++) {

		int row_minimum = find_row_minimum(array, i, columns);

		for(int j = 0; j < columns; j++) {
			array[i][j] = array[i][j] - row_minimum;
		}
	}

	for(int i = 0; i < columns; i ++) {

		int column_minimum = find_column_minimum(array, rows, i);

		for(int j = 0; j < rows; j++) {
			array[j][i] = array[j][i] - column_minimum;
		}
	}

/*	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {
			cout << array[i][j] << " " << flush;
		}

		cout << endl;
	}
*/
	cout << endl;

	for(int i = 0; i < rows; i++) {

		int column_index = find_zero_in_a_row(array, i, columns);

		if(column_index != -1) {
			array[i][column_index] = -200;

			for(int j = 0; j < rows; j++) {

				if(array[j][column_index] == 0) {
					array[j][column_index] = -100;
				}
			}
		}

	}

	cout << endl;

	for(int i = 0; i < columns; i++) {

		int row_index = find_zero_in_a_column(array, i, rows);

		if(row_index != -1) {
		//	cout << row_index << endl;
			array[row_index][i] = -200;
			for(int j = 0; j < columns; j++) {
				if(array[row_index][j] == 0) {
					array[row_index][j] = -100;
				}
			}
		}
	}

	cout << endl;

/*	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			cout << array[i][j] << " " << flush;
		}

		cout << endl;
	}
*/
	cout << endl;

	int number_of_assignments = count_number_of_assignments(array, rows, columns);

	if(number_of_assignments == rows) {

		int i = 0;

		for(int k = 0; k < rows; k++) {

			for(int j = 0; j < columns; j++) {

				if((array[j][k] == -200) || array[i][j] == 0) {
					array3[i][0] = j;
					array3[i][1] = k;
					i++;
				}
			}
		}


		for(int i = 0; i < rows; i++) {

				for(int j = 0; j < columns; j++) {

				 		cout << array[i][j] << " " << flush;
				}

					cout << endl;
			}

		for(int i = 0; i < rows; i++) {

				for(int j = 0; j < columns; j++) {

				 		if(array[i][j] == -200) {
				 			array[i][j] = 0;
				 		}

				 		if(array[i][j] == -100) {
				 			array[i][j] = -1;
				 		}
				}

					cout << endl;
			}

		for(int i = 0; i < rows; i++) {

				for(int j = 0; j < columns; j++) {

				 		cout << array[i][j] << " " << flush;
				}

					cout << endl;
			}


		return;
	}

	for(int i = 0; i < rows; i++) {

		array[i][columns] = -1;
	}

	for(int i = 0; i < columns; i++) {

		array[rows][i] = -1;
	}



	for(int i = 0; i < rows; i++) {

		int flag = find_unassigned_row_index(array, i, columns);

		if(flag == 1) {
			array[i][columns] = 1;
		}

	}

	int current_number_of_ones = count_number_of_ones(array, rows, columns);
	int previous = 0;

	while(current_number_of_ones != previous) {

		previous = current_number_of_ones;
		for(int i = 0; i < rows; i++) {

			if(array[i][columns] == 1) {

				for(int j = 0; j < columns; j++) {

					if(array[i][j] == -100) {
						array[rows][j] = 1;
					}


				}
			}
		}

		for(int i = 0; i < columns; i++) {

			if(array[rows][i] == 1) {

				for(int j = 0;  j < rows; j++) {

					if(array[j][i] == -200) {
						array[j][columns] = 1;
					}
				}
			}
		}

		current_number_of_ones = count_number_of_ones(array, rows, columns);

	}


/*	for(int i = 0; i <= rows; i++) {

		for(int j = 0; j <= columns; j++) {

	 		cout << array[i][j] << " " << flush;
		}

		cout << endl;
	}

*/
	cout << endl;

	int theta = find_minimum_theta(array, rows, columns);

	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			if((array[i][columns] == 1) && (array[rows][j] == -1)) {
				array[i][j] = array[i][j] - theta;
			}

			else if((array[i][columns] == -1) && (array[rows][j] == 1)) {

				if(array[i][j] == -100) {
					array[i][j] = 0;
				}
				array[i][j] = array[i][j] + theta;
			}

			else {
				continue;
			}
		}

	}


	newarray(array, rows, columns);
	return;
}

int main() {

	int array1[100][100];
	int array2[100][100];
	cout << "Enter the number of jobs available : " << flush;
	int rows;
	cin >> rows;

	cout << "Enter the number of people available : " << flush;
	int columns;
	cin >> columns;


	for(int i = 0; i < rows; i++) {

		for(int j = 0; j < columns; j++) {

			cout << "Enter the money charged by person " << j + 1 << " to do the job " << i + 1 << " : " << flush;
			cin >> array1[i][j];

		}

		cout << endl;
	}


	for(int i = 0; i < rows; i++) {

			for(int j = 0; j < columns; j++) {

				array2[i][j] = array1[i][j];
			}

			cout << endl;
		}


	newarray(array1, rows, columns);


	int sum = 0;

	for(int i = 0; i < rows; i++) {

		sum = sum + array2[array3[i][0]][array3[i][1]];
	}

	cout << "The minimum cost is " << sum << endl;


	return 0;

}
