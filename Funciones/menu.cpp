#include "empleados.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

void menuAdmin();
void menuEmpleado();
void menuPrincipal();

void menuAdmin()
{
    int opcion;
    do
    {
        system("cls");
        cout << "1. Registrar empleado" << endl;
        cout << "2. Editar empleado" << endl;
        cout << "3. Buscar empleado" << endl;
        cout << "4. Eliminar empleado" << endl;
        cout << "5. Generar informes" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarEmpleado();
            break;
        case 2:
            editarEmpleado();
            break;
        case 3:
            imprimirDatosEmpleado();
            break;
        case 4:
            eliminarEmpleado();
            break;
        case 5:
            // Generar informe
            break;
        case 6:
            system("cls");
            cout << "Saliendo" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida..." << endl;
            system("pause");
            break;
        }
    } while (opcion != 6);
}

void menuEmpleado()
{
    int opcion;
    time_t horaEntrada_t, horaSalida_t;
    pair<time_t, time_t> horasEntradaSalida;

    if (iniciarSesionEmpleado() != 1)
    {
        do
        {
            cout << "1. Registrar asistencia" << endl;
            cout << "2. Imprimir informe" << endl;
            cout << "3. Salir" << endl;
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                // Usa la funcion de admin para registrar entrada/salida
                horasEntradaSalida = ingresarEntradaSalida();
                horaEntrada_t = horasEntradaSalida.first;
                horaSalida_t = horasEntradaSalida.second;
                registrarAsistencia(horaEntrada_t);
                break;
            case 2:
                // Imprimir informe
                system("cls");
                cout << "Imprimiendo informe..." << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                cout << "Saliendo..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida..." << endl;
                system("pause");
                break;
            }
        } while (opcion != 3);
    }
}

void menuPrincipal()
{
    int opcion;
    do
    {
        system("cls");
        cout << "1. Administrador" << endl;
        cout << "2. Empleado" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuAdmin();
            break;
        case 2:
            menuEmpleado();
            break;
        case 3:
            system("cls");
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida..." << endl;
            system("pause");
            break;
        }
    } while (opcion != 3);
}
