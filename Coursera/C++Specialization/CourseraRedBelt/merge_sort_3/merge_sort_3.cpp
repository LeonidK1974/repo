#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // Напишите реализацию функции,
  // не копируя сортируемые элементы
	if (range_begin + 1 == range_end) { return; }

	vector<typename RandomIt::value_type> aux_vector(std::make_move_iterator(range_begin), std::make_move_iterator(range_end));

	int onethird = (aux_vector.size() / 3);

	MergeSort(begin(aux_vector), begin(aux_vector) + onethird);
	MergeSort(begin(aux_vector) + onethird, end(aux_vector) - onethird);
	MergeSort(end(aux_vector) - onethird, end(aux_vector));

	vector<typename RandomIt::value_type> tmp;

	std::merge(std::make_move_iterator(begin(aux_vector)), std::make_move_iterator(begin(aux_vector) + onethird),
		std::make_move_iterator(begin(aux_vector) + onethird), std::make_move_iterator(end(aux_vector) - onethird),
		back_inserter(tmp));

	std::merge(std::make_move_iterator(begin(tmp)), std::make_move_iterator(end(tmp)),
		std::make_move_iterator(end(aux_vector) - onethird), std::make_move_iterator(end(aux_vector)),
		range_begin);
}

class StringNonCopyable : public string {
public:
	using string::string;
	StringNonCopyable(string&& other) : string(move(other)) {}
	StringNonCopyable(const StringNonCopyable&) = delete;
	StringNonCopyable(StringNonCopyable&&) = default;
	StringNonCopyable& operator=(const StringNonCopyable&) = delete;
	StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestIntVector() {
  vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
  MergeSort(begin(numbers), end(numbers));
  ASSERT(is_sorted(begin(numbers), end(numbers)));
}
void TestNoCopy() {
	vector<StringNonCopyable> strings;
	static const int SIZE = 9;
	for (int i = 0; i < SIZE; ++i) {
		strings.push_back(StringNonCopyable(to_string(i)));
	}
	for (int i = 0; i < SIZE; ++i) {
		ASSERT_EQUAL(strings[i], to_string(i));
	}
	MergeSort(begin(strings), end(strings));
	ASSERT(is_sorted(begin(strings), end(strings)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
