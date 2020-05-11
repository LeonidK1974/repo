#include <algorithm>
#include "http_request.h"
#include "stats.h"
#include <string>
#include <iostream>

Stats::Stats() {
	for (const auto &method : methods_names) {
		method_stats_[method] = 0;
	}

	for (const auto &uri : uris_names) {
		uri_stats_[uri] = 0;
	}
}

void Stats::AddMethod(string_view method) {
	add(method, method_stats_, methods_names);
}

void Stats::AddUri(string_view uri) {
	add(uri, uri_stats_, uris_names);
}

const map<string_view, int>& Stats::GetMethodStats() const {
	return method_stats_;
}

const map<string_view, int>& Stats::GetUriStats() const {
	return uri_stats_;
}

void Stats::add(std::string_view to_add,
	std::map<std::string_view, int> &add_to,
	vector<string> &lookup) {

	bool known = false;
	for (const auto &known_value : lookup) {
		if (to_add.compare(known_value) == 0) {
			add_to[known_value]++;
			known = true;
			break;
		}
	}
	if (!known) {
		add_to[*(lookup.end()-1)]++;
	}
}

HttpRequest ParseRequest(string_view line) {
	string_view method, uri, protocol;
	// note: do not expect a null terminated string
	const auto words_begin(line.find_first_not_of(" \t\n"));
	line.remove_prefix(min(words_begin, line.size()));

	const auto words_end(line.find_last_not_of(" \t\n"));

	if (words_end != string_view::npos) {
		line.remove_suffix(line.size() - words_end - 1);
	}

	size_t pos = 0; 
	const size_t pos_end = line.npos;

	size_t space = line.find(' ', pos);
	method = line.substr(pos, space - pos);

	pos = space + 1; 

	space = line.find(' ', pos);
	uri = line.substr(pos, space - pos);

	pos = space + 1;

	space = line.find(' ', pos);
	protocol = line.substr(pos, space - pos);

	return { method, uri, protocol };
}