//
// Created by kedar on 15/5/19.
//

#include "classTest.h"

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms)
            : bedrooms_(bedrooms), bathrooms_(bathrooms) {}

    int get_price() {
        cout << bedrooms_ << ":" << bathrooms_ << endl;
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms)
            : HotelRoom(bedrooms, bathrooms) {
        bedrooms_ha = bedrooms;
        bathrooms_ha = bathrooms;
    }

    int get_price() {
        cout << "2. "<< bedrooms_ha << ":" << bathrooms_ha << endl;

        return 50*bedrooms_ha + 100*bathrooms_ha + 100;
    }
private:
    int bedrooms_ha;
    int bathrooms_ha;

};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}