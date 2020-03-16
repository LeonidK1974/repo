#include "bus_manager.h"


void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	// Реализуйте этот метод
	buses_to_stops[bus] = stops;
	for (const string& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	// Реализуйте этот метод
	BusesForStopResponse bfs_Response;

	if (stops_to_buses.count(stop) == 0) {
		bfs_Response.message = "No stop";
	}
	else {
		for (const string& bus : stops_to_buses.at(stop)) {
			bfs_Response.message += bus;
			bfs_Response.message += " ";
		}
	}

	return bfs_Response;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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
			sfbResponse.message += "Stop " + stop + ": ";
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

AllBusesResponse BusManager::GetAllBuses() const {
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
			all_Response.message += "Bus " + bus_item.first + ": ";
			for (const string& stop : bus_item.second) {
				all_Response.message += stop;
				all_Response.message += " ";
			}
			start = false;
		}
	}
	return all_Response;
}

