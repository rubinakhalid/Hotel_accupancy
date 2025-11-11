//
//  main.cpp
//  Hotel Occupancy
//
//  Created by Rubina on 1/24/25.
//

#include <iostream>
#include <iomanip>   // for fixed and setprecision
using namespace std;

int main() 
{
    int noOfFloors, totalRooms = 0, totalOccupied = 0;

    cout << "Welcome to the Hotel Management Calculator!" << endl;

    // Get number of floors
    do {
        cout << "Enter the number of floors in the hotel: ";
        cin >> noOfFloors;

        if (noOfFloors <= 0) {
            cout << "The number of floors should be greater than 0. Please try again." << endl;
        }

    } while (noOfFloors <= 0);

    // Loop through each floor
    for (int floor = 1; floor <= noOfFloors; ++floor) 
    {
        if (floor == 13) {
            cout << "Skipping floor 13..." << endl;
            continue;
        }

        int rooms, occupied;

        // Rooms input
        do {
            cout << "Enter the number of rooms on floor " << floor << ": ";
            cin >> rooms;

            if (rooms <= 0) {
                cout << "The number of rooms should be greater than 0. Please try again." << endl;
            }

        } while (rooms <= 0);

        // Occupied rooms input
        do {
            cout << "Enter the number of occupied rooms on floor " << floor << ": ";
            cin >> occupied;

            if (occupied < 0 || occupied > rooms) {
                cout << "Occupied rooms should be between 0 and the total number of rooms. Please try again." << endl;
            }

        } while (occupied < 0 || occupied > rooms);

        totalRooms += rooms;
        totalOccupied += occupied;
    }

    // Calculations
    int totalUnoccupied = totalRooms - totalOccupied;
    double occupancyRate = (static_cast<double>(totalOccupied) / totalRooms) * 100;

    // Output
    cout << "\nHotel Occupancy Report:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Total rooms: " << totalRooms << endl;
    cout << "Occupied rooms: " << totalOccupied << endl;
    cout << "Unoccupied rooms: " << totalUnoccupied << endl;

    cout << fixed << setprecision(2);
    cout << "Occupancy rate: " << occupancyRate << "%" << endl;

    return 0;
}
