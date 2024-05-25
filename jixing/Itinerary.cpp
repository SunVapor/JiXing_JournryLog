#include "Itinerary.h"
#include <algorithm>

using namespace std;

    void Itinerary::createList(const string& name) {
        listName = name;
    }

    void Itinerary::renameList(const string& name) {
        listName = name;
    }

    void Itinerary::deleteList() {
        listName.clear();
        trips.clear();
    }

    void Itinerary::addTrip(const Trip& trip) {
        trips.push_back(trip);
    }

    void Itinerary::modifyTrip(int index, const Trip& trip) {
        if (index >= 0 && index < int(trips.size())) {
            trips[index] = trip;
        }
    }

    void Itinerary::deleteTrip(int index) {
        if (index >= 0 && index < int(trips.size())) {
            trips.erase(trips.begin() + index);
        }
    }

    vector<Itinerary::Trip> Itinerary::outputTrips() {
        return trips;
    }

    void Itinerary::sortTripsByTime() {
        sort(trips.begin(), trips.end(), [](const Trip& a, const Trip& b) {
            return a.time < b.time;
        });
    }