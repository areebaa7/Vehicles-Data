#include "def_Operations.h"
#include <iostream>
#include <fstream>


using namespace std;

// This function takes data for one vehicle
void Get_VehicleData(string vehicle)
{
    Vehicle v;

    // Store type (Car / Bike)
    v.type = vehicle;

    cout << "Enter " << vehicle << " category: " << endl;
    getline(cin, v.category);

    cout << "Enter " << vehicle << " model: " << endl;
    cin >> v.model;
    cin.ignore();

    cout << "Enter " << vehicle << " name: " << endl;
    getline(cin, v.name);

    cout << "Enter " << vehicle << " price: " << endl;
    cin >> v.price;
    cin.ignore();

    // Display entered data
    cout << "Entered Data:"<<endl;
    cout << "Type: " << v.type << endl;
    cout << "Category: " << v.category << endl;
    cout << "Model: " << v.model << endl;
    cout << "Name: " << v.name << endl;
    cout << "Price: " << v.price << endl;

    
    Write_VehicleData(v);
}


// This function writes one vehicle record to file
void Write_VehicleData(Vehicle v)
{
    ofstream vehiclesdata("vehicles.txt", ios::app);

    if (!vehiclesdata.is_open())
    {
        cout << "File could not open." << endl;
        return;
    }

    vehiclesdata << "Vehicle Type: " << v.type << endl;
    vehiclesdata << "Category: " << v.category << endl;
    vehiclesdata << "Model: " << v.model << endl;
    vehiclesdata << "Name: " << v.name << endl;
    vehiclesdata << "Price: " << v.price << endl;
    vehiclesdata << "-----------------------------" << endl;

    vehiclesdata.close();

    cout << "Data written to file successfully." << endl;
}