#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct PERSONA
{
    string nombre;
    string apellido;
    string cedula;
    vector<string> fechas;
    vector<string> horas;
    vector<int> asistencias;
    vector<int> llegadaTarde;
    int inasistencias;
    string horasExtras;
    string clave;

};

vector<PERSONA> empleados;

PERSONA nuevoEmpleado;