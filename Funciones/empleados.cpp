#include "admin.cpp"
#include <iostream>
#include <chrono>
#include <ctime>

int anio, mes, dias;

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
    if (mes >= 1 && mes <= 12)
    {
        if (dias <= calcularDiasMes(mes, anio) && dias > 0)
        {
            if (zeller(anio, mes, dias) == 6 && zeller(anio, mes, dias) == 7)
            {
                cout << "Este dia es fin de semana" << endl;
            }
            else
            {
                iniciarSesionEmpleado();
                cout << "Nombre: " << nombres[i] << endl;
                cout << "Apellido: " << apellidos[i] << endl;
                cout << "Cedula: " << cedulas[i] << endl;
                
            }
        }
    }
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