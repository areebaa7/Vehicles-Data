#include <iostream>
#include "def_Operations.h"

using namespace std;

int main()
{
    int choice;
    string vehicle;

    do
    {
        cout << "\n===== VEHICLE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View Vehicles\n";
        cout << "3. Update Vehicle\n";
        cout << "4. Delete Vehicle\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Which vehicle do you want to enter (bike/car): ";
                getline(cin, vehicle);
                Get_VehicleData(vehicle);
                break;

            case 2:
                Read_VehicleData();
                break;

            case 3:
                Update_VehicleData();
                break;

            case 4:
                Delete_VehicleData();
                break;

            case 5:
                cout << "Program terminated by user." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}