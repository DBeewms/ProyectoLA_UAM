#include "informes.cpp"
#include "inicioSesion.cpp"
#include "personas.cpp"
#include <iostream>

using namespace std;

// Registrar empleados
void registrarEmpleado();
// Editar empleados
void editarEmpleado();
// Buscar empleados
void buscarEmpleado();
// Eliminar empleados
void eliminarEmpleado();

void registrarEmpleado()
{
    string nombre, apellido, cedula,;
    char contrasena[sizePass];
    int j;
    for (int i = 0; i < j; i++)
    {
        cout << "Cuantos empleados desea registrar? ";
        cin >> j;
        cout << "Ingrese el nombre del empleado: ";
        cin >> nombre;
        nombres.push_back(nombre);
        cout << "Ingrese el apellido del empleado: ";
        cin >> apellido;
        apellidos.push_back(apellido);
        cout << "Ingrese la cedula del empleado: ";
        cin >> cedula;
        cedulas.push_back(cedula);
        generarContrasena(contrasena);
        contraseñas.push_back(contrasena);

    }
}

void buscarEmpleado()
{
    string cedula;
    cout << "Ingrese la cedula del empleado que desea buscar: ";
    cin >> cedula;
    for (int i = 0; i < cedulas.size(); i++)
    {
        if (cedulas[i] == cedula)
        {
            cout << "Nombre: " << nombres[i] << endl;
            cout << "Apellido: " << apellidos[i] << endl;
            cout << "Cedula: " << cedulas[i] << endl;
            cout << "Contraseña: " << contraseñas[i] << endl;
            break;
        }else{
            cout << "Empleado no encontrado" << endl;
        }
    }
}