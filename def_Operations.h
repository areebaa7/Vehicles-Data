#ifndef DEF_OPERATIONS_H
#define DEF_OPERATIONS_H

#include <string>
using namespace std;

struct Vehicle
{
    string type;
    string category;
    int model;
    string name;       // Use underscore instead of spaces, e.g. Honda_Civic
    long long price;
};

void Get_VehicleData(string vehicle);
void Write_VehicleData(Vehicle v);
void Read_VehicleData();
void Update_VehicleData();
void Delete_VehicleData();

#endif