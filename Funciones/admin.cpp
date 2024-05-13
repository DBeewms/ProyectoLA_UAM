#include "informes.cpp"
#include <iostream>
#include <string>
#define sizePass 5

using namespace std;

int i = 0;

// Registrar empleados
void registrarEmpleado();
// Editar empleados
void editarEmpleado();
// Eliminar empleados
void eliminarEmpleado();

void imprimirDatosEmpleado();

void generarContrasena(char *contrasena);


void generarContrasena(char *contrasena)
{
    srand(time(0));
    for (int i = 0; i < sizePass; i++)
    {
        int num = rand() % 10;
        contrasena[i] = '0' + num;
    }
    contrasena[sizePass] = '\0';
}


void registrarEmpleado()
{
    string nombre, apellido, cedula;
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
        claves.push_back(contrasena);
        cout << "La contraseña del empleado es:" << contrasena << endl;
    }
}


void imprimirDatosEmpleado()
{
    cout << "Nombre: " << nombres[i] << endl;
    cout << "Apellido: " << apellidos[i] << endl;
    cout << "Cedula: " << cedulas[i] << endl;
    cout << "Contraseña: " << claves[i] << endl;
}


void editarEmpleado()
{
    buscarEmpleado();
    imprimirDatosEmpleado();
    int opcion;
    cout << "¿Que deseas editar?" << endl;
    cout << "1. Nombre ";
    cout << "2. Apellido";
    cout << "3. Cedula";
    cout << "4. Contraseña";
    cout << "5. Salir";
    cout << "Elige tu opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "El nombre actual es: " << nombres[i] << endl;
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombres[i];
        cout << "El nuevo nombre es: " << nombres[i] << endl;
        break;

    case 2:
        cout << "El apellido actual es: " << apellidos[i] << endl;
        cout << "Ingrese el nuevo apellido: ";
        cin >> apellidos[i];
        cout << "El nuevo apellido es: " << apellidos[i] << endl;
        break;

    case 3:
        cout << "La cedula actual es: " << cedulas[i] << endl;
        cout << "Ingrese la nueva cedula: ";
        cin >> cedulas[i];
        cout << "La nueva cedula es: " << cedulas[i] << endl;
        break;

    case 4:
        cout << "La contraseña actual es: " << claves[i] << endl;
        char contrasena[sizePass];
        generarContrasena(contrasena);
        claves[i] = contrasena;
        cout << "La nueva contraseña es: " << claves[i] << endl;
        break;

    case 5:
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}

void eliminarEmpleado()
{
    buscarEmpleado();
    imprimirDatosEmpleado();
    int opcion;
    cout << "¿Estas seguro de que deseas eliminar este empleado?" << endl;
    cout << "1. Si";
    cout << "2. No";
    cout << "Elige tu opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        nombres.erase(nombres.begin() + i);
        apellidos.erase(apellidos.begin() + i);
        cedulas.erase(cedulas.begin() + i);
        claves.erase(claves.begin() + i);

        cout << "Empleado eliminado" << endl;

        break;

    case 2:
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}
