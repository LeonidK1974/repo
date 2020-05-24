#include "test_runner.h"
#include "profile.h"

#include <future>
#include <string>
#include <vector>

using namespace std;

//template <typename Iterator>
//class IteratorRange {
//public:
//	IteratorRange(Iterator begin, Iterator end)
//		: first(begin)
//		, last(end)
//		, size_(distance(first, last))
//	{
//	}
//
//	Iterator begin() const {
//		return first;
//	}
//
//	Iterator end() const {
//		return last;
//	}
//
//	size_t size() const {
//		return size_;
//	}
//
//private:
//	Iterator first, last;
//	size_t size_;
//};
//
//template <typename Iterator>
//class Paginator {
//private:
//	vector<IteratorRange<Iterator>> pages;
//
//public:
//	Paginator(Iterator begin, Iterator end, size_t page_size) {
//		for (size_t left = distance(begin, end); left > 0; ) {
//			size_t current_page_size = min(page_size, left);
//			Iterator current_page_end = next(begin, current_page_size);
//			pages.push_back({ begin, current_page_end });
//
//			left -= current_page_size;
//			begin = current_page_end;
//		}
//	}
//
//	auto begin() const {
//		return pages.begin();
//	}
//
//	auto end() const {
//		return pages.end();
//	}
//
//	auto begin() {
//		return pages.begin();
//	}
//
//	auto end() {
//		return pages.end();
//	}
//
//	size_t size() const {
//		return pages.size();
//	}
//};
//
//template <typename C>
//auto Paginate(C& c, size_t page_size) {
//	return Paginator(begin(c), end(c), page_size);
//}

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
	  for (const auto & wf : other.word_frequences)
		  word_frequences[wf.first] += wf.second;
  }
  
};

Stats ExploreWord(const set<string>& key_words, const string& word) {
	Stats stats{};

	if (key_words.count(word) > 0) {
		++stats.word_frequences[word];
	}

	return stats;
}

Stats ExploreKeyWordsThread(const set<string>& key_words, const vector<string>& page) {
	Stats result;
	
	for (auto word : page) {
		result += ExploreWord(key_words, word);
	}
	return result;
}


vector<string> ReadStrings(istream& stream)
{
	vector<string> strings;
	string s;
	while (stream >> s) {
		strings.push_back(move(s));
	}
	return strings;
}

template<typename T>
std::vector< std::vector<T> > split(std::vector<T> vec, uint64_t n) {
	std::vector< std::vector<T> > vec_of_vecs(n);

	uint64_t quotient = vec.size() / n;
	uint64_t reminder = vec.size() % n;
	uint64_t first = 0;
	uint64_t last;
	for (uint64_t i = 0; i < n; ++i) {
		if (i < reminder) {
			last = first + quotient + 1;
			vec_of_vecs[i] = std::vector<T>(vec.begin() + first, vec.begin() + last);
			first = last;
		}
		else if (i != n - 1) {
			last = first + quotient;
			vec_of_vecs[i] = std::vector<T>(vec.begin() + first, vec.begin() + last);
			first = last;
		}
		else
			vec_of_vecs[i] = std::vector<T>(vec.begin() + first, vec.end());
	}

	return vec_of_vecs;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) 
{
	/*std::stringstream ss;

	ss << input.rdbuf();*/

	// Реализуйте эту функцию
	vector<future<Stats>> futures;
	vector<string> streams = ReadStrings(input);
	//auto page_count = streams.size() / std::thread::hardware_concurrency();
	auto page_count = 4;

	vector<vector<string>> pages(page_count);
	pages = split(streams, page_count);

	for (auto page : pages) {
		futures.push_back(async([=] { return ExploreKeyWordsThread(ref(key_words), ref(page)); }));
	}

	Stats res{};
	for (auto & stat : futures)
	{
		res += stat.get();
	}

	return res;
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
