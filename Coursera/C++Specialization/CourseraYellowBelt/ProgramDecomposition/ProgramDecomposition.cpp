// ProgramDecomposition.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	// Реализуйте эту функцию
	string operation_code;
	is >> operation_code;
	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		string bus;
		is >> bus;
		q.bus = bus;
		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (string& stop : q.stops) {
			cin >> stop;
		}
	}
	else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		string stop;
		cin >> stop;
		q.stop = stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		string bus;
		cin >> bus;
		q.bus = bus;
	} 
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	// Наполните полями эту структуру
	string message;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	os << r.message;
	
	return os;
}

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string message;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	os << r.message;
	return os;
}

struct AllBusesResponse {
	// Наполните полями эту структуру
	string message;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	os << r.message;
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		// Реализуйте этот метод
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// Реализуйте этот метод
		BusesForStopResponse bfs_Response;

		if (stops_to_buses.count(stop) == 0) {
			bfs_Response.message = "No stop";
		}
		else {
			for (const string& bus : stops_to_buses.at(stop)) {
				bfs_Response.message += bus;
				bfs_Response.message +=	" ";
			}
		}

		return bfs_Response;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		// Реализуйте этот метод
		StopsForBusResponse sfbResponse;
		if (buses_to_stops.count(bus) == 0) {
			sfbResponse.message = "No bus";
		}
		else {
			bool start = true;
			for (const string& stop : buses_to_stops.at(bus)) {
				if (!start) {
					sfbResponse.message += "\n";
				}
				sfbResponse.message += "Stop " + stop  + ": ";
				if (stops_to_buses.at(stop).size() == 1) {
					sfbResponse.message += "no interchange";
				}
				else {
					for (const string& other_bus : stops_to_buses.at(stop)) {
						if (bus != other_bus) {
							sfbResponse.message += other_bus;
							sfbResponse.message += " ";
						}
					}
				}
				start = false;
			}
		}

		return sfbResponse;
	}

	AllBusesResponse GetAllBuses() const {
		// Реализуйте этот метод
		AllBusesResponse all_Response;
		if (buses_to_stops.empty()) {
			all_Response.message = "No buses";
		}
		else {
			bool start = true;
			for (const auto& bus_item : buses_to_stops) {
				if (!start) {
					all_Response.message += "\n";
				}
				all_Response.message += "Bus " +  bus_item.first + ": ";
				for (const string& stop : bus_item.second) {
					all_Response.message +=  stop;
					all_Response.message += " ";
				}
				start = false;
			}
		}
		return all_Response;
	}
		
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}

