#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <chrono>
#include "informes.cpp"

using namespace std;

// // Usar estas variables al implementar las funciones:

// // time_t horaEntrada_t, horaSalida_t;
// // pair<time_t, time_t> horasEntradaSalida;

// // void pedirFecha();
// // pair<time_t, time_t> ingresarEntradaSalida();
// // void registrarAsistencia(time_t horaEntrada_t);
// // time_t calcularHorasExtra(time_t horaSalida_t);

// // horasEntradaSalida = ingresarEntradaSalida();
// // horaEntrada_t = horasEntradaSalida.first;
// // horaSalida_t = horasEntradaSalida.second;

// pair<time_t, time_t> ingresarEntradaSalida();

// pair<time_t, time_t> ingresarEntradaSalida()
// {
//     // Tomar el punto actual del calendario del sistema
//     auto now = system_clock::now();

//     // Convertir a time_t que representa el tiempo del calendario
//     time_t now_time_t = system_clock::to_time_t(now);

//     // Convierte a un estrucutra tm que representa la fecha y tiempo de un calendario
//     tm *now_tm = localtime(&now_time_t);

//     // Pedir hora de entrada y de salida
//     string horaEntrada_str, horaSalida_str;
//     cout << "Define la hora de entrada y salida..." << endl;
//     cout << "Hora de entrada (HH:MM:SS): ";
//     cin >> horaEntrada_str;
//     cout << "Hora de salida (HH:MM:SS): ";
//     cin >> horaSalida_str;

//     // Parsear la hora de entrada y salida a tm
//     tm horaEntrada_tm = *now_tm, horaSalida_tm = *now_tm;
//     stringstream horaEntrada_ss(horaEntrada_str), horaSalida_ss(horaSalida_str);
//     horaEntrada_ss >> get_time(&horaEntrada_tm, "%H:%M:%S");
//     horaSalida_ss >> get_time(&horaSalida_tm, "%H:%M:%S");

//     // Parsear las estructuras tm devuelta a time_t
//     time_t horaEntrada_t = mktime(&horaEntrada_tm);
//     time_t horaSalida_t = mktime(&horaSalida_tm);

//     return make_pair(horaEntrada_t, horaSalida_t);
// }

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
    system("cls || clear");

    // Pedimos los datos del empleado
    fflush(stdin);
    cout << "Ingrese el nombre del empleado: ";
    cin.getline(empleados[numEmpleados].nombre, MAX_STR, '\n');
    cout << "Ingrese el apellido del empleado: ";
    cin.getline(empleados[numEmpleados].apellido, MAX_STR, '\n');
    cout << "Ingrese el id de usuario: ";
    fflush(stdin);
    cin >> empleados[numEmpleados].infoUsuario.id;
    if (empleados[numEmpleados].infoUsuario.id < 0)
    {
        cout << "El id no puede ser negativo" << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < numEmpleados; i++)
    {
        if (empleados[i].infoUsuario.id == empleados[numEmpleados].infoUsuario.id)
        {
            cout << "El id ya existe" << endl;
            system("pause");
            return;
        }
    }

    cout << "Se generara la clave automaticamente" << endl;

    // Generamos la clave aleatoriamente
    generarContrasena(empleados[numEmpleados].infoUsuario.clave);
    cout << "La contraseña del empleado es: " << empleados[numEmpleados].infoUsuario.clave << endl;

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
        cout << "Id de usuario: " << empleados[index].infoUsuario.id << endl;
        cout << "PIN: " << empleados[index].infoUsuario.clave << endl;
    }
}

// Para editar a un empleado
void editarEmpleado()
{
    system("cls || clear");
    int index = buscarEmpleado();
    imprimirDatosEmpleado(index);
    int opcion;
    if (index != -1)
    {
        if (numEmpleados == 0)
        {
            cout << "No hay empleados registrados" << endl;
            system("pause");
            return;
        }

        cout << "Que deseas editar?" << endl;
        cout << "1. Nombre " << endl;
        cout << "2. Apellido" << endl;
        cout << "3. id" << endl;
        cout << "4. clave" << endl;
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
            cout << "La id actual es: " << empleados[index].infoUsuario.id << endl;
            cout << "Ingrese la nueva id: ";
            fflush(stdin);
            cin >> empleados[index].infoUsuario.id;
            cout << "La nueva id es: " << empleados[index].infoUsuario.id << endl;
            system("pause");
            break;

        case 4:
            cout << "La clave actual es: " << empleados[index].infoUsuario.clave << endl;
            cout << "Se generara una nueva clave" << endl;
            // Creamos un nuevo arreglo para almacenar la nueva clave
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
            cout << "¿Estas seguro de que deseas eliminar este empleado?" << endl;
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
                // Disminuimos el contador de empleados
                numEmpleados--;
                // Guardar los cambios en el archivo
                guardarEmpleadosEnArchivo("empleados.txt");
                cout << "Empleado eliminado exitosamente" << endl;
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
        cout << "id: " << empleados[i].infoUsuario.id << endl;
        cout << "Clave: " << empleados[i].infoUsuario.clave << endl;
        cout << endl;
    }
    system("pause");
}

