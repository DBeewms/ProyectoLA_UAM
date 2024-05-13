#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Buscar empleados
void buscarEmpleado();

vector<int> asistencias;
vector<int> tarde;
vector<string> nombres;
vector<string> apellidos;
vector<string> cedulas;
vector<string> claves;

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