#include "query.h"

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