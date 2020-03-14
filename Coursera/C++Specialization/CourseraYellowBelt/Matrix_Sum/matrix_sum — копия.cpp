// Matrix_Sum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix
class Matrix {
public:
	Matrix() {  
		num_rows = 0;
		num_cols = 0;
	}

	Matrix(int new_rows, int new_cols)
	{
		Reset(new_rows, new_cols);
	}

	void Reset(int new_rows, int new_cols) {
		if (new_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (new_cols < 0) {
			throw out_of_range("num_columns must be >= 0");
		}

		if (new_rows == 0 || new_rows == 0) {
			new_rows = new_rows = 0;
		}

		num_rows = new_rows;
		num_cols = new_cols;
		matrix_of_ints.assign(num_rows, vector<int>(num_cols));
	};

	int At(int row, int col) const {
		return matrix_of_ints.at(row).at(col);
	};

	int& At(int row, int col) {
		return matrix_of_ints.at(row).at(col);
	};

	int GetNumRows() const {
		return num_rows;
	}

	int GetNumColumns() const {
		return num_cols;
	}

private:
	int num_rows;
	int num_cols;
	vector<vector<int>> matrix_of_ints;
};

bool operator == (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) return false;
	for (int i_row = 0; i_row < lhs.GetNumRows(); i_row++) {
		for (int i_col = 0; i_col < lhs.GetNumColumns(); i_col++) {
			if (lhs.At(i_row, i_col) != rhs.At(i_row, i_col)) return false;
		}
	}
	return true;
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}

	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}

	Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());
	for (int i_row = 0; i_row < lhs.GetNumRows(); i_row++) {
		for (int i_col = 0; i_col < lhs.GetNumColumns(); i_col++) {
			res.At(i_row, i_col) = lhs.At(i_row, i_col) + rhs.At(i_row, i_col);
		}
	}
	return res;
}

istream& operator >> (istream& is, Matrix& m) {
	int rows, columns;
	is >> rows >> columns;
	m.Reset(rows, columns);
	for (int i_row = 0; i_row < rows; i_row++) {
		for (int i_col = 0; i_col < columns; i_col++) {
			is >> m.At(i_row, i_col);
		}
	}
	return is;
}

ostream& operator << (ostream& os, const Matrix& m) {
	os << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for (int i_row = 0; i_row < m.GetNumRows(); i_row++) {
		for (int i_col = 0; i_col < m.GetNumColumns(); i_col++) {
			if (i_col > 0) {
				os << " ";
			}
			os << m.At(i_row, i_col);
		}
		os << endl;
	}
	return os;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;

	return 0;
}
