#include <iostream>
#include <string>
#include <fstream>
#include "empleados.cpp"

using namespace std;
// Prototipos de funciones
void menuInicioSesion();
void menuAdministrador();
void menuEmpleado(int index);
void loginEmpleado();

// Inicios de Sesion
int iniciarSesionEmpleado();
// Definicion de funciones
void menuInicioSesion()
{
    cargarEmpleadosDesdeArchivo("empleados.txt");
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
            loginEmpleado();
            break;

        case 3:
            cout << "Saliendo..." << endl;
            return;
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
            return;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    } while (opcion != 3);
}
void loginEmpleado()
{
    int opcion;
    do
    {
        system("cls || clear");
        cout << "\t\t\t _________________________________________________________________\t\t\t" << endl;
        cout << "\t\t\t                   Inicio de Sesion como Empleado                 \t\t\t" << endl;
        cout << "\t\t\t                            --- MENU ---                           \t\t\t" << endl;
        cout << "\t\t\t__________________________________________________________________\t\t\t" << endl;
        cout << "\t ____________________________                                      \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t|    Selecciona una opcion:  |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 1. Iniciar Sesion          |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 2. Salir                   |                                     \t\t\t" << endl;
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
            iniciarSesionEmpleado();
            break;
        case 2:
            system("cls || clear");
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            break;
        }
    } while (opcion != 2);
}

void menuEmpleado(int index)
{
    // Variables Locales
    int opcion;

    do
    {
        system("cls || clear");
        // Menu de empleado
        cout << "\t\t\t _________________________________________________________________\t\t\t" << endl;
        cout << "\t\t\t            Bienvenido a la pagina de Empleado                    \t\t\t" << endl;
        cout << "\t\t\t                            --- MENU ---                           \t\t\t" << endl;
        cout << "\t\t\t__________________________________________________________________\t\t\t" << endl;
        cout << "\t ____________________________                                      \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t|    Selecciona una opcion:  |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 1. Registrar mi Asistencia |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 2. Mostrar mi informe      |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 3. Mostrar mis datos       |                                     \t\t\t" << endl;
        cout << "\t|                            |                                     \t\t\t" << endl;
        cout << "\t| 4. Salir                   |                                     \t\t\t" << endl;
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
            cout << "Registrar mi asistencia" << endl;
            // Registrar la asistencia
            break;
        case 2:
            cout << "Mostrar mi informe" << endl;
            // Mostrar el informe
            break;
        case 3:
        
            imprimirDatosEmpleadoEnEmpleados(index);
            system("pause");
            break;
        
        case 4:
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

int iniciarSesionEmpleado()
{
    system("cls || clear");
    int count = 0;
    int index;

    INICIO_SESION usuario;
    cout << "\t\t\tPor favor ingrese el usuario y la contrasenia:\n"
         << endl;
    cout << "\t\t\t _________________________________\n";
    cout << "\t\t\t   -\\\\- Inicio de Sesion -\\\\-   \n\n";
    cout << "\t\t\t\t\t CEDULA: ";
    fflush(stdin);
   cin.getline(usuario.cedula, MAX_CEDULA + 1);
    cout << "\t\t\t\t\t CLAVE: ";
    fflush(stdin);
    cin.getline(usuario.clave, SIZE_PASS + 1);
    cout << "\n\n";
    cout << "\t\t\t _________________________________\n"
         << endl;

    for (int i = 0; i < numEmpleados; i++)
    {
        if (strcmp(usuario.cedula, empleados[i].infoUsuario.cedula) == 0)
        {
            if (strcmp(usuario.clave, empleados[i].infoUsuario.clave) == 0)
            {
                count = 1;
                index = i;
                break;
            }
        }
    }

    if (count == 1)
    {
        cout << "\n\n\t\t\t\t\tBienvenido! " << empleados[index].nombre << endl;
        cout << "\t\t\t\t\tInicio de sesion exitoso\n\n"
             << endl;
        system("pause");
        menuEmpleado(index);
    }
    else
    {
        cout << "\t\t\t\t\tInicio de sesion fallido\n\n"
             << endl;
        system("pause");
        return -1;
    }
}
