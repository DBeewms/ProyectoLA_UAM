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

int buscarEmpleado()
{
    int idTemporal;
    cout << "Ingrese la id del empleado: ";
    cin >> idTemporal;

    for (int i = 0; i < numEmpleados; i++)
    {
        if (empleados[i].infoUsuario.id == idTemporal)
        {
            return i;
        }
        
    }
    cout << "No se encontro el empleado" << endl;
    system("pause");
    return -1;
}

