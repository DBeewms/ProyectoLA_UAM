#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "funFicheros.cpp"

using namespace std;
using namespace chrono;

// Buscar empleados
int buscarEmpleado();

int buscarEmpleado()
{
    char cedTemporal[MAX_CEDULA + 1];
    fflush(stdin);
    cout << "Ingrese la cedula del empleado: ";
    cin.getline(cedTemporal, 50);

    for (int i = 0; i < numEmpleados; i++)
    {
        if (strcmp(empleados[i].infoUsuario.cedula, cedTemporal) == 0)
        {
            return i;
        }
    }
    cout << "No se encontro el empleado" << endl;
    system("pause");
    return -1;
}