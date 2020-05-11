#pragma once

#include "http_request.h"
#include <array>
#include <map>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Stats {
public:
	Stats();
	void AddMethod(string_view method);
	void AddUri(string_view uri);
	const map<string_view, int>& GetMethodStats() const;
	const map<string_view, int>& GetUriStats() const;

private:
	void add(string_view to_add,
		map<std::string_view, int> &add_to,
		vector<string> &lookup);

	vector<string> methods_names = { "GET", "PUT", "POST", "DELETE", "UNKNOWN"};		
	//const string default_method_ = "UNKNOWN";

	vector<string> uris_names = { "/", "/product", "/order", "/basket", "/help", "unknown" };
	
	//const string default_uri_ = "unknown";

	map<string_view, int> method_stats_, uri_stats_;
};

HttpRequest ParseRequest(string_view line);
