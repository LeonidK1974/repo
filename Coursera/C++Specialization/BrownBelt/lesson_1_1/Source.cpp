#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "head.h"
#include "profile.h"
using namespace std;

int main()
{
	unordered_map<string, int> freqs;
	ifstream fs("input.txt");

	{
		LOG_DURATION("fill collection");
		string text;
		while (fs >> text) {
			++freqs[text];
		}
	}
	
	/*for (const auto&[k, v] : Head(freqs, 10)) {
		cout << k << "\t" << v << endl;
	}

	cout << endl;
*/

	LOG_DURATION("fill collection");
	vector<pair<string, int>> words(freqs.begin(), freqs.end());
	sort(words.begin(), words.end(), [](const auto& l, const auto& r) {
		return l.second > r.second;
		});

	for (const auto&[k, v] : Head(words, 10)) {
		cout << k << "\t" << v << endl;
	}
}