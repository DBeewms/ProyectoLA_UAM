#include <iostream>
#include <string>
#include <fstream>
#include "admin.cpp"

using namespace std;
// Prototipos de funciones
void menuInicioSesion();
void menuAdministrador();

// Definicion de funciones
void menuInicioSesion()
{
    // Variables Locales
    int opcion;

    do
    {
        system("cls || clear");
        // Menu de inicio de sesion
        cout << "\t\t\t _________________________________________________________________\t\t\t" << endl;
        cout << "\t\t\t|                                                                 |\t\t\t" << endl;
        cout << "\t\t\t|    ______ _                           _     _                   |\t\t\t" << endl;
        cout << "\t\t\t|    | ___ (_)                         (_)   | |                  |\t\t\t" << endl;
        cout << "\t\t\t|    | |_/ /_  ___ _ ____   _____ _ __  _  __| | _ __             |\t\t\t" << endl;
        cout << "\t\t\t|    | ___ \\ |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\             |\t\t\t" << endl;
        cout << "\t\t\t|    | |_/ / |  __/ | | \\ V /  __/ | | | | (_| | (_) |            |\t\t\t" << endl;
        cout << "\t\t\t|    \\____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/             |\t\t\t" << endl;
        cout << "\t\t\t|                                                                 |\t\t\t" << endl;
        cout << "\t\t\t|_________________________________________________________________|\t\t\t\n\n"
             << endl;
        cout << "\t\t\t            Bienvenido a la pagina de inicio de Sesion                \t\t\t" << endl;
        cout << "\t\t\t                            --- MENU ---                           \t\t\t\n\n"
             << endl;
        cout << "\t ____________________________                                      \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t|    Iniciar Sesion como:    |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 1. Administrador           |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 2. Empleado                |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t|____________________________|                                     \t\t\t\n\n"
             << endl;
        cout << "\t-------------------------------------------------------------------- \t\t\t" << endl
             << endl;
        cout << "\tPor favor elige una opcion: ";
        cin >> opcion;
        cout << "\n\n"
             << endl;

        switch (opcion)
        {
        case 1:
            menuAdministrador();
            break;

        case 2:
            cout << "hola empleado";
            break;

        case 3:
            cout << "Saliendo..." << endl;
            break;
        }

    } while (opcion != 3);
}

void menuAdministrador()
{
    // Variables Locales
    int opcion;

    do
    {
        system("cls || clear");
        // Menu de administrador
        cout << "\t\t\t _________________________________________________________________\t\t\t" << endl;
        cout << "\t\t\t            Bienvenido a la pagina de Administrador                \t\t\t" << endl;
        cout << "\t\t\t                            --- MENU ---                           \t\t\t" << endl;
        cout << "\t\t\t__________________________________________________________________\t\t\t" << endl;
        cout << "\t ____________________________                                      \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t|    Selecciona una opcion:  |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 1. Registrar Empleado      |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 2. Editar Empleado         |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 3. Eliminar Empleado       |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 4. Buscar Empleado         |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 5. Lista de Empleados      |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 6. Salir                   |                                     \t\t\t" << endl;
        cout << "\t|____________________________|                                     \t\t\t\n\n"
             << endl;
        cout << "\t-------------------------------------------------------------------- \t\t\t" << endl
             << endl;
        cout << "\tPor favor elige una opcion: ";
        cin >> opcion;
        cout << "\n\n"
             << endl;

        switch (opcion)
        {
        case 1:
            registrarEmpleado();
            break;
        case 2:
            editarEmpleado();
            break;
        case 3:
            eliminarEmpleado();
            break;
        case 4:
        {
            system("cls || clear");
            int index = buscarEmpleado();
            imprimirDatosEmpleado(index);
            system("pause");
            break;
        }
        case 5:
            mostrarTodosLosEmpleados();
            break;
        case 6:
            system("cls || clear");
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    } while (opcion != 3);
}
