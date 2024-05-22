#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "personas.h"

using namespace std;
using namespace chrono;

// Buscar empleados
void buscarEmpleado();

// ACTUALIZAR BUSCAR EMPLEADO

int i = 0;

void buscarEmpleado()
{
    i = 0;
    string cedula;
    cout << "Ingrese la cedula del empleado que desea buscar: ";
    cin >> cedula;

    for (i < cedulas.size(); i++;)
    {
        if (cedulas[i] == cedula)
        {
            break;
        }
        else
        {
            cout << "Empleado no encontrado" << endl;
        }
    }
}