#ifndef DEF_OPERATIONS_H
#define DEF_OPERATIONS_H

#include <string>
using namespace std;

struct Vehicle
{
    string type;
    string category;
    int model;
    string name;
    float price;
};

void Get_VehicleData(string vehicle);
void Write_VehicleData(Vehicle v);

#endif