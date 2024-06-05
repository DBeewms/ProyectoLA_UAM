#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "personas.h"

using namespace std;
using namespace chrono;

// Buscar empleados
int buscarEmpleado();

// ACTUALIZAR BUSCAR EMPLEADO


int buscarEmpleado()
{
    string cedula;
    cout << "Ingrese la cedula del empleado que desea buscar: ";
    cin >> cedula;

    for (int i = 0; i < numEmpleadosRegistrados; i++) {
        if (empleados[i].cedula == cedula) {
            return i;
        }
    }
    cout << "Empleado no encontrado" << endl;
    return -1;
}