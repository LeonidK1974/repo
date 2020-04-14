#include "test_runner.h"
#include <iostream>
#include <utility>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table
{
public:
	Table(size_t row, size_t column) : row_(row), column_(column)
	{
		Resize(row_, column_);
	};

	vector<T>& operator[](size_t index)
	{
		return table_[index];
	}

	const vector<T>& operator[](size_t index) const
	{
		return table_[index];
	}

	void Resize(size_t row, size_t column)
	{
		row_ = row;
		column_ = column;
		table_.resize(row);
		for (vector<T>& row : table_)
		{
			row.resize(column, T());
		}		
	}
	
	pair<size_t, size_t> Size() const
	{
		return make_pair(row_, column_);
	}

private:
	size_t row_;
	size_t column_;
	vector<vector<T>> table_;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}
