#include "admin.cpp"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int i = 0;

void iniciarSesionEmpleado()
{
    char contrasena[sizePass];
    buscarEmpleado();

    cout << "Ingrese la contraseña: ";
    cin >> contrasena;

    if (claves[i] == contrasena)
    {
        cout << "Sesion iniciada" << endl;
    }
    else
    {
        cout << "Contraseña incorrecta" << endl;
    }
}

void registrarAsistencia()
{

    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
    
    cout << "Nombre: " << nombres[i] << endl;
    cout << "Apellido: " << apellidos[i] << endl;
    cout << "Cedula: " << cedulas[i] << endl;

}

// Uso de la funcion generarContrasena

// int main(int argc, char const *argv[])
// {
//     char contrasena[sizePass+1];

//     generarContrasena(contrasena);
//     for (int i = 0; i < sizePass; i++)
//     {
//         cout << contrasena[i];
//     }

//     return 0;
// }