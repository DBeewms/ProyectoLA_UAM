#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <iomanip> // put_time
#include "informes.cpp"

using namespace std;

// Generar clave aleatoria
void generarContrasena(char *contrasena);

// Funciones de administrador para empleados
void registrarEmpleado();
void editarEmpleado();
void eliminarEmpleado();

void imprimirDatosEmpleado(int index);
void mostrarTodosLosEmpleados();

// Definicion de funciones

// Generar clave aleatoria
void generarContrasena(char *contrasena)
{
    srand(time(0));
    for (int i = 0; i < SIZE_PASS; i++)
    {
        int num = rand() % 10;
        contrasena[i] = '0' + num;
    }
    contrasena[SIZE_PASS] = '\0';
}

// Para registrar a un nuevo empleado
void registrarEmpleado()
{
    char cedulaTemp[100];
    system("cls || clear");

    // Pedimos los datos del empleado
    fflush(stdin);
    cout << "Ingrese el nombre del empleado: ";
    cin.getline(empleados[numEmpleados].nombre, MAX_STR, '\n');
    cout << "Ingrese el apellido del empleado: ";
    cin.getline(empleados[numEmpleados].apellido, MAX_STR, '\n');
    // Para solicitar la cedula
    cout << "Ingrese la cedula (exactamente " << MAX_CEDULA << " caracteres): ";

    cin.getline(cedulaTemp, sizeof(cedulaTemp)); // Leer la entrada del usuario

    while (strlen(cedulaTemp) != MAX_CEDULA)
    {
        cout << "Error: La cedula debe tener exactamente 10 caracteres. Intentelo de nuevo." << endl;
        cout << "Ingrese la cedula (exactamente 10 caracteres): ";
        cin.getline(cedulaTemp, sizeof(cedulaTemp)); // Leer la entrada del usuario
    }
    for (int i = 0; i < numEmpleados; i++)
    {
        if (strcmp(empleados[i].infoUsuario.cedula, cedulaTemp) == 0)
        {
            cout << "La Cedula: ya existe" << endl;
            system("pause");
            return;
        }
    }
    strncpy(empleados[numEmpleados].infoUsuario.cedula, cedulaTemp, MAX_CEDULA + 1); // Copiar la cedula valida al destino

    cout << "Se generara la clave automaticamente" << endl;

    // Generamos la clave aleatoriamente
    generarContrasena(empleados[numEmpleados].infoUsuario.clave);
    cout << "La clave del empleado es: " << empleados[numEmpleados].infoUsuario.clave << endl;

    numEmpleados++;

    // Guardar empleados en el archivo
    guardarEmpleadosEnArchivo("empleados.txt");

    cout << "Empleado registrado exitosamente" << endl;

    system("pause");
}

// Para imprimir los datos de un empleado
void imprimirDatosEmpleado(int index)
{
    if (index != -1)
    {
        // Imprimimos los datos del empleado
        cout << "Nombre: " << empleados[index].nombre << endl;
        cout << "Apellido: " << empleados[index].apellido << endl;
        cout << "Cedula: " << empleados[index].infoUsuario.cedula << endl;
        cout << "PIN: " << empleados[index].infoUsuario.clave << endl;
    }
}

// Para editar a un empleado
void editarEmpleado()
{
    char cedulaTemp[100];
    system("cls || clear");
    int index = buscarEmpleado();
    imprimirDatosEmpleado(index);
    int opcion;

    char cedulaAntigua[MAX_CEDULA + 1];

    if (index != -1)
    {
        if (numEmpleados == 0)
        {
            cout << "No hay empleados registrados" << endl;
            system("pause");
            return;
        }
        // Pedimos al usuario que campo desea editar
        cout << "Que deseas editar?" << endl;
        cout << "1. Nombre " << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Cedula" << endl;
        cout << "4. Clave" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige tu opcion: " << endl;
        cin >> opcion;

        // Reemplazamos los campos con los nuevos datos
        switch (opcion)
        {
        case 1:
            cout << "El nombre actual es: " << empleados[index].nombre << endl;
            cout << "Ingrese el nuevo nombre: ";
            fflush(stdin);
            cin.getline(empleados[index].nombre, MAX_STR, '\n');
            cout << "El nuevo nombre es: " << empleados[index].nombre << endl;

            system("pause");
            break;

        case 2:
            cout << "El apellido actual es: " << empleados[index].apellido << endl;
            cout << "Ingrese el nuevo apellido: ";
            fflush(stdin);
            cin.getline(empleados[index].apellido, MAX_STR, '\n');
            cout << "El nuevo apellido es: " << empleados[index].apellido << endl;
            system("pause");
            break;

        case 3:
            strcpy(cedulaAntigua, empleados[index].infoUsuario.cedula);

            cout << "La cedula actual es: " << cedulaAntigua << endl;
            fflush(stdin);
            cout << "Ingrese la nueva cedula (exactamente " << MAX_CEDULA << " caracteres): ";

            cin.getline(cedulaTemp, sizeof(cedulaTemp)); // Leer la entrada del usuario

            while (strlen(cedulaTemp) != MAX_CEDULA)
            {
                cout << "Error: La cedula debe tener exactamente 10 caracteres. Intentelo de nuevo." << endl;
                cout << "Ingrese la cedula (exactamente 10 caracteres): ";
                cin.getline(cedulaTemp, sizeof(cedulaTemp)); // Leer la entrada del usuario
            }
            for (int i = 0; i < numEmpleados; i++)
            {
                if (strcmp(empleados[i].infoUsuario.cedula, cedulaTemp) == 0)
                {
                    cout << "La Cedula: ya existe" << endl;
                    system("pause");
                    return;
                }
            }
            strncpy(empleados[index].infoUsuario.cedula, cedulaTemp, MAX_CEDULA + 1); // Copiar la cedula valida al destino

            cout << "La nueva id es: " << empleados[index].infoUsuario.cedula << endl;

            // Edicion del fichero .csv de asistencias

            if (strcmp(cedulaAntigua, empleados[index].infoUsuario.cedula) != 0)
            {
                char nombreArchivoAntiguo[30];
                char nombreArchivoNuevo[30];

                // Construir nombres de archivo
                sprintf(nombreArchivoAntiguo, "%s.csv", cedulaAntigua);
                sprintf(nombreArchivoNuevo, "%s.csv", empleados[index].infoUsuario.cedula);

                // Intentar cambiar el nombre del archivo
                if (rename(nombreArchivoAntiguo, nombreArchivoNuevo) != 0)
                {
                    cout << "Error al cambiar el nombre del archivo." << endl;
                }
                else
                {
                    cout << "Archivo renombrado exitosamente." << endl;
                }
            }

            // Construir nombres de archivo de informe
            char nombreInformeAntiguo[60];
            char nombreInformeNuevo[60];

            sprintf(nombreInformeAntiguo, "informe%s.txt", cedulaAntigua);
            sprintf(nombreInformeNuevo, "informe%s.txt", empleados[index].infoUsuario.cedula);

            // Intentar cambiar el nombre del archivo de informe
            if (rename(nombreInformeAntiguo, nombreInformeNuevo) != 0)
            {
                cout << "Error al cambiar el nombre del archivo de informe." << endl;
            }
            else
            {
                cout << "Archivo de informe renombrado exitosamente." << endl;
            }

            system("pause");
            break;
        case 4:
            cout << "La clave actual es: " << empleados[index].infoUsuario.clave << endl;
            cout << "Se generara una nueva clave" << endl;

            char contrasena[SIZE_PASS];

            // Generamos la nueva clave
            generarContrasena(contrasena);
            strcpy(empleados[index].infoUsuario.clave, contrasena);
            cout << "La nueva clave es: " << empleados[index].infoUsuario.clave << endl;
            system("pause");
            break;

        case 5:
            cout << "Saliendo..." << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

        // Guardar los cambios en el archivo
        guardarEmpleadosEnArchivo("empleados.txt");
    }
}

// Para eliminar a un empleado
void eliminarEmpleado()
{
    int opcion;
    system("cls || clear");
    int index = buscarEmpleado();
    imprimirDatosEmpleado(index);

    if (index != -1)
    {
        if (numEmpleados > 1)
        {
            cout << "Estas seguro de que deseas eliminar este empleado?" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cout << "Elige tu opcion: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                system("cls || clear");
                // Eliminamos el empleado del arreglo

                for (int i = index; i < numEmpleados - 1; i++)
                {
                    // El empleado a eliminar se sobreescribe con el siguiente empleado
                    empleados[i] = empleados[i + 1];
                }

                // Eliminar el archivo de informe del empleado
                char nombreInforme[35];
                sprintf(nombreInforme, "informe%s.txt", empleados[index].infoUsuario.cedula);

                if (remove(nombreInforme) != 0)
                {
                    cout << "Error al eliminar el archivo de informe del empleado." << endl;
                }
                else
                {
                    cout << "Archivo de informe del empleado eliminado exitosamente." << endl;
                }

                // Disminuimos el contador de empleados
                numEmpleados--;

                // Construir el nombre del archivo .csv a eliminar
                char nombreArchivo[30];
                sprintf(nombreArchivo, "%s.csv", empleados[index].infoUsuario.cedula);

                // Eliminar el archivo .csv del empleado
                if (remove(nombreArchivo) != 0)
                {
                    cout << "Error al eliminar el archivo del empleado." << endl;
                }
                else
                {
                    cout << "Archivo del empleado eliminado exitosamente." << endl;
                }

                // Guardar los cambios en el archivo
                cout << "Empleado eliminado exitosamente" << endl;
                guardarEmpleadosEnArchivo("empleados.txt");

                system("pause");
                break;
            case 2:
                cout << "Saliendo..." << endl;

                system("pause");
                break;
            default:
                cout << "Opcion no valida" << endl;

                system("pause");
                break;
            }
        }
        else
        {
            cout << "No puedes eliminar el unico empleado" << endl;
            system("pause");
        }
    }
}

// Para mostrar a todos los empleados
void mostrarTodosLosEmpleados()
{
    system("cls || clear");
    cout << "Lista de empleados" << endl;
    for (int i = 0; i < numEmpleados; i++)
    {
        cout << "Empleado " << i + 1 << endl;
        cout << "Nombre: " << empleados[i].nombre << endl;
        cout << "Apellido: " << empleados[i].apellido << endl;
        cout << "Cedula: " << empleados[i].infoUsuario.cedula << endl;
        cout << "Clave: " << empleados[i].infoUsuario.clave << endl;
        cout << endl;
    }
    system("pause");
}
