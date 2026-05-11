#include <iostream>
#include "def_Operations.h"

using namespace std;

int main()
{
    string vehicle;
    char choice;

    do
    {
        cout << "Which vehicle do you want to enter (bike/car): " << endl;
        getline(cin, vehicle);

        Get_VehicleData(vehicle);

        cout << "Press Y to continue, N to stop: ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated by user." << endl;

    return 0;
}