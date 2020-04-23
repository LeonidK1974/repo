#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>

#include "profile.h"

using namespace std;

class ReadingManager {
public:
	ReadingManager()
		: 	pages(MAX_BOOK_PAGES_ + 1, 0) {}	

	void Read(int user_id, int page_count) {

		LOG_DURATION("Read");

		int user_pages = users[user_id]; // количество страниц пользователя

		for (auto it = user_pages; it != page_count; ++it) // O(P) - максимум 10^3 страниц
		{
			++pages[it];
		}

		auto p = users.insert(pair<int,int>(user_id, page_count));
		if (p.second == false)
		{
			users[user_id] = page_count;
		}

	}

	double Cheer(int user_id) const 
	{
		LOG_DURATION("Cheer");
		// вывод - доля существующих пользователей (не считая его самого) прочитала меньшую часть книги, чем он
		if (users.count(user_id) == 0) { // если пользователь еще не читает
			return 0;
		}

		if (users.size() == 1) { // если пользователь единственный читатель
			return 1;
		}

		int user_pages = users.at(user_id); // количество страниц пользователя

		int done_users = pages[user_pages-1]; // количество пользователей также прочитавших user_pages-страниц

		return (users.size() - done_users) * 1.0 / (users.size() - 1); //
	}

private:
	// Статическое поле не принадлежит какому-то конкретному
	// объекту класса. По сути это глобальная переменная,
	// в данном случае константная.
	// Будь она публичной, к ней можно было бы обратиться снаружи
	// следующим образом: ReadingManager::MAX_USER_COUNT.
	static const int MAX_USER_COUNT_ = 100'000;
	static const int MAX_BOOK_PAGES_ = 1000;

	map<int, int> users; //список пользователей и прочтенных страниц
	vector<int> pages; //список страниц и количество читающих данную страницу
};


int main() {
	// Для ускорения чтения данных отключается синхронизация
	// cin и cout с stdio,
	// а также выполняется отвязка cin от cout
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ReadingManager manager;

	int query_count;
	cin >> query_count;

	for (int query_id = 0; query_id < query_count; ++query_id) {
		string query_type;
		cin >> query_type;
		int user_id;
		cin >> user_id;

		if (query_type == "READ") {
			int page_count;
			cin >> page_count;
			manager.Read(user_id, page_count);
		}
		else if (query_type == "CHEER") {
			cout << setprecision(6) << manager.Cheer(user_id) << "\n";
		}
 	}

	return 0;
}