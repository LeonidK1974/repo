// Translator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "test_runner.h"
#include <deque>
#include <map>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Translator {
public:
	void Add(string_view source, string_view target);
	string_view TranslateForward(string_view source) const;
	string_view TranslateBackward(string_view target) const;

private:
	string_view GetClonedView(string_view s) {
		for (const auto* map_ptr : { &forward_dict, &backward_dict }) {
			const auto it = map_ptr->find(s);
			if (it != map_ptr->end()) {
				return it->first;
			}
		}
		return data.emplace_back(s);
	}

	static string_view Translate(const map<string_view, string_view>& dict, string_view s) {
		const auto it = dict.find(s);
		if(it != dict.end()) {
			return it->second;
		}
		else {
		return {};
		}
	}

	map<string_view, string_view> forward_dict;
	map<string_view, string_view> backward_dict;
	deque<string> data;
};

void Translator::Add(string_view source, string_view target) {
		const string_view source_view = GetClonedView(source);
		const string_view target_view = GetClonedView(target);
		forward_dict[source_view] = target_view;
		backward_dict[target_view] = source_view;
}

string_view Translator::TranslateForward(string_view source) const {
	return Translate(forward_dict, source);
}

string_view Translator::TranslateBackward(string_view target) const {
	return Translate(backward_dict, target);
}

void TestSimple() {
	Translator translator;
	translator.Add(string("okno"), string("window"));
	translator.Add(string("stol"), string("table"));

	ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
	ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
	ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestSimple);
	return 0;
}

