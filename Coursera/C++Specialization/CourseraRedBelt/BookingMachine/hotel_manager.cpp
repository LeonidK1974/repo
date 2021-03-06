#include "test_runner.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

class HotelManager {
public:
  HotelManager() {}

  void Book(int64_t reserv_time, string hotel_name, int user_id, int room_count) {

    if (room_count != 0 || hotel_name != "") {
	reserv_stat.push({reserv_time, hotel_name, user_id, room_count});
	all_hotels_stat[hotel_name].users_stat[user_id]++;
	all_hotels_stat[hotel_name].rooms_stat += room_count;
    }
      while (86399 < (reserv_time - reserv_stat.front().reserv_time)) {
	  try {
	      auto& it_hotel = all_hotels_stat.at(reserv_stat.front().hotel_name);
	      auto& it_user_stat = it_hotel.users_stat.at(reserv_stat.front().user_id);

	      it_user_stat--;

	      if (it_user_stat == 0) {
		  it_hotel.users_stat.erase(reserv_stat.front().user_id);
	      }

	      it_hotel.rooms_stat -= reserv_stat.front().room_count;
	      reserv_stat.pop();
	  }
	  catch (out_of_range& e) {};

      }

  }

  int Clients(string hotel_name) {
    int result = 0;
    try {
	result = all_hotels_stat.at(hotel_name).users_stat.size();
    }
    catch (out_of_range& e) {}

    return result;
  }

  int Rooms(string hotel_name) {
    int result = 0;

    try {
	result = all_hotels_stat.at(hotel_name).rooms_stat;
    }
    catch (out_of_range& e) {}

    return result;
  }

private:
  struct reservation {
    int64_t reserv_time;
    string hotel_name;
    int user_id = 0;
    int room_count = 0;
  };

  struct hotel_stat {
    map<int, int> users_stat;
    int rooms_stat = 0;
  };

  queue<reservation> reserv_stat;
  map<string, hotel_stat> all_hotels_stat;
};

void test() {
    HotelManager manager;

    // Test empty bookings
    ASSERT_EQUAL(manager.Clients("mariott"), 0);
    ASSERT_EQUAL(manager.Rooms("mariott"), 0);

    manager.Book(0, "mariott", 1, 10);
    manager.Book(0, "mariott", 2, 1);
    manager.Book(0, "mariott", 3, 1);
    manager.Book(0, "mariott", 4, 1);
    manager.Book(0, "hilton", 1, 1);
    manager.Book(1, "hilton", 2, 1);

    // Test correctness
    ASSERT_EQUAL(manager.Clients("mariott"), 4);
    ASSERT_EQUAL(manager.Rooms("mariott"), 13);
    ASSERT_EQUAL(manager.Clients("hilton"), 2);
    ASSERT_EQUAL(manager.Rooms("hilton"), 2);

    // Test event past 1 day resets statics
    manager.Book(86400, "mariott", 1, 1);
    ASSERT_EQUAL(manager.Clients("mariott"), 1);
    ASSERT_EQUAL(manager.Rooms("mariott"), 1);
    ASSERT_EQUAL(manager.Clients("hilton"), 1);
    ASSERT_EQUAL(manager.Rooms("hilton"), 1);

    // Test no clients and room for the last day
    manager.Book(86401, "mariott", 5, 1);
    ASSERT_EQUAL(manager.Clients("mariott"), 2);
    ASSERT_EQUAL(manager.Rooms("mariott"), 2);
    ASSERT_EQUAL(manager.Clients("hilton"), 0);
    ASSERT_EQUAL(manager.Rooms("hilton"), 0);

    manager.Book(999999999999999000, "hilton", 3, 5);
    manager.Book(999999999999999900, "hilton", 4, 3);
    manager.Book(999999999999999990, "mariot", 6, 1);
    manager.Book(999999999999999999, "mariot", 6, 2);
    ASSERT_EQUAL(manager.Rooms("hilton"), 8);
    ASSERT_EQUAL(manager.Clients("hilton"), 2);
    ASSERT_EQUAL(manager.Rooms("mariot"), 3);
    ASSERT_EQUAL(manager.Clients("mariot"), 1);
}

int main() {

  TestRunner tr;
  tr.RunTest(test, "test");

  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  HotelManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;

    if (query_type == "BOOK") {
	int reserv_time;
	string hotel_name;
	int user_id, room_count;
	cin >> reserv_time >> hotel_name >> user_id >> room_count;
	manager.Book(reserv_time, hotel_name, user_id, room_count);
    }
    else if (query_type == "CLIENTS") {
	string hotel_name;
	cin >> hotel_name;
	cout << manager.Clients(hotel_name) << endl;
    }
    else if (query_type == "ROOMS") {
    	string hotel_name;
    	cin >> hotel_name;
    	cout << manager.Rooms(hotel_name) << endl;
    }
  }
  return 0;
}
