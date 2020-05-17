#include "test_runner.h"

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;

//// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Iterator>
auto FindSentenceEnd(Iterator tokens_begin, Iterator tokens_end) {
	for (auto iter = tokens_begin; iter != tokens_end; ++iter){
		if (iter->IsEndSentencePunctuation()) {
			advance(iter, 1);
			while (iter != tokens_end){
				if (iter->IsEndSentencePunctuation())
					advance(iter, 1);
				else
					break;
			}			
			return iter;
		}
	}
	return tokens_end;
}

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
  // Напишите реализацию функции, не копируя объекты типа Token
	vector<Sentence<Token>> sentences;
	//typename vector<Token>::iterator tokens_begin = begin(tokens);
	auto tokens_begin = begin(tokens);
	const auto tokens_end = end(tokens);
	while (tokens_begin != tokens_end) {
		const auto sentence_end = FindSentenceEnd(tokens_begin, tokens_end); 
		Sentence<Token> sentence; 
		for (; tokens_begin != sentence_end; ++tokens_begin) { 
			sentence.push_back(move(*tokens_begin)); 
		} 
		sentences.push_back(move(sentence));

	}

	return sentences;
}


struct TestToken {
  string data;
  bool is_end_sentence_punctuation = false;

  bool IsEndSentencePunctuation() const {
    return is_end_sentence_punctuation;
  }
  bool operator==(const TestToken& other) const {
    return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
  }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
  return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!"}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!"}}
    })
  );

  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!", true}}
    })
  );

  ASSERT_EQUAL(
    SplitIntoSentences(vector<TestToken>({{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true}})),
    vector<Sentence<TestToken>>({
        {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
        {{"Without"}, {"copies"}, {".", true}},
    })
  );

  ASSERT_EQUAL(
	SplitIntoSentences(vector<TestToken>({ {"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true} })),
	vector<Sentence<TestToken>>({
		{{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true},  {"!", true}},
		{{"Without"}, {"copies"}, {".", true}},
		})
  );
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSplitting);
  return 0;
}
