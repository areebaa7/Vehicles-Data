#include "def_Operations.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

// Input one vehicle
void Get_VehicleData(string vehicle)
{
    Vehicle v;

    v.type = vehicle;

    cout << "Enter " << vehicle << " category: ";
    cin >> v.category;

    cout << "Enter " << vehicle << " model: ";
    cin >> v.model;

    cout << "Enter " << vehicle << " name: ";
    cin.ignore();
    getline(cin, v.name);

    cout << "Enter " << vehicle << " price: ";
    cin >> v.price;
    cin.ignore();

    Write_VehicleData(v);
}


void Write_VehicleData(Vehicle v)
{
    ofstream vehiclesdata("vehicles.txt", ios::app);

    if (!vehiclesdata.is_open())
    {
        cout << "File could not open." << endl;
        return;
    }

    vehiclesdata << v.type << " "
                 << v.category << " "
                 << v.model << " "
                 << v.name << " "
                 << v.price << endl;

    vehiclesdata.close();

    cout << "Data written to file successfully." << endl;
}

// Read all vehicles
void Read_VehicleData()
{
    ifstream vehiclesdata("vehicles.txt");

    if (!vehiclesdata.is_open())
    {
        cout << "File could not open." << endl;
        return;
    }

    Vehicle v;

    while (vehiclesdata >> v.type >> v.category >> v.model >> v.name >> v.price)
    {
        cout << "Type: " << v.type << endl;
        cout << "Category: " << v.category << endl;
        cout << "Model: " << v.model << endl;
        cout << "Name: " << v.name << endl;
        cout << "Price: " << v.price << endl;
        cout << "------------------------" << endl;
    }

    vehiclesdata.close();
}

// Update by model number
void Update_VehicleData()
{
    int modelToUpdate;
    Vehicle v;

    cout << "Enter model number to update: ";
    cin >> modelToUpdate;

    ifstream fin("vehicles.txt");
    ofstream fout("temp.txt");

    if (!fin.is_open() || !fout.is_open())
    {
        cout << "File error!" << endl;
        return;
    }

    bool found = false;
    bool hasData = false;

    while (fin >> v.type >> v.category >> v.model >> v.name >> v.price)
    {
        hasData = true;

        if (v.model == modelToUpdate)
        {
            found = true;

            cout << "Enter new type: ";
            cin >> v.type;

            cout << "Enter new category: ";
            cin >> v.category;

            cout << "Enter new model: ";
            cin >> v.model;

            cout << "Enter new name: ";
            cin >> v.name;

            cout << "Enter new price: ";
            cin >> v.price;
        }

        fout << v.type << " "
             << v.category << " "
             << v.model << " "
             << v.name << " "
             << v.price << endl;
    }

    fin.close();
    fout.close();

    if (!hasData)
    {
        cout << "File is empty or corrupted." << endl;
        return;
    }

    if (found)
    {
        remove("vehicles.txt");
        rename("temp.txt", "vehicles.txt");
        cout << "Record updated successfully." << endl;
    }
    else
    {
        remove("temp.txt"); // VERY IMPORTANT
        cout << "Model not found." << endl;
    }
}
// Delete by model number
void Delete_VehicleData()
{
    int modelToDelete;
    Vehicle v;

    cout << "Enter model number to delete: ";
    cin >> modelToDelete;

    ifstream fin("vehicles.txt");
    ofstream fout("temp.txt");

    if (!fin.is_open() || !fout.is_open())
    {
        cout << "File error!" << endl;
        return;
    }

    bool found = false;
    bool hasData = false;

    while (fin >> v.type >> v.category >> v.model >> v.name >> v.price)
    {
        hasData = true;

        if (v.model == modelToDelete)
        {
            found = true;
            continue;
        }

        fout << v.type << " "
             << v.category << " "
             << v.model << " "
             << v.name << " "
             << v.price << endl;
    }

    fin.close();
    fout.close();

    if (!hasData)
    {
        cout << "File is empty or corrupted." << endl;
        return;
    }

    if (found)
    {
        remove("vehicles.txt");
        rename("temp.txt", "vehicles.txt");
        cout << "Record deleted successfully." << endl;
    }
    else
    {
        remove("temp.txt"); // IMPORTANT (avoid empty overwrite)
        cout << "Model not found." << endl;
    }
}