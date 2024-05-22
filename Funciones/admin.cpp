#include "informes.cpp"
#include <iostream>
#include <string>
#define sizePass 5

using namespace std;

// Usar estas variables al implementar las funciones:

// time_t horaEntrada_t, horaSalida_t;
// pair<time_t, time_t> horasEntradaSalida;

// void pedirFecha();
// pair<time_t, time_t> ingresarEntradaSalida();
// void registrarAsistencia(time_t horaEntrada_t);
// time_t calcularHorasExtra(time_t horaSalida_t);

// horasEntradaSalida = ingresarEntradaSalida();
// horaEntrada_t = horasEntradaSalida.first;
// horaSalida_t = horasEntradaSalida.second;


int i = 0;

//ACTUALIZAR FUNCIONES SIGUIENDO LA ESTRUCTURA PERSONA

// Registrar empleados
void registrarEmpleado();
// Editar empleados
void editarEmpleado();
// Eliminar empleados
void eliminarEmpleado();

void imprimirDatosEmpleado();
void generarContrasena(char *contrasena);

pair<time_t, time_t> ingresarEntradaSalida();


pair<time_t, time_t> ingresarEntradaSalida()
{
    // Tomar el punto actual del calendario del sistema
    auto now = system_clock::now();

    // Convertir a time_t que representa el tiempo del calendario
    time_t now_time_t = system_clock::to_time_t(now);

    // Convierte a un estrucutra tm que representa la fecha y tiempo de un calendario
    tm *now_tm = localtime(&now_time_t);

    // Pedir hora de entrada y de salida
    string horaEntrada_str, horaSalida_str;
    cout << "Define la hora de entrada y salida..." << endl;
    cout << "Hora de entrada (HH:MM:SS): ";
    cin >> horaEntrada_str;
    cout << "Hora de salida (HH:MM:SS): ";
    cin >> horaSalida_str;

    // Parsear la hora de entrada y salida a tm
    tm horaEntrada_tm = *now_tm, horaSalida_tm = *now_tm;
    stringstream horaEntrada_ss(horaEntrada_str), horaSalida_ss(horaSalida_str);
    horaEntrada_ss >> get_time(&horaEntrada_tm, "%H:%M:%S");
    horaSalida_ss >> get_time(&horaSalida_tm, "%H:%M:%S");

    // Parsear las estructuras tm devuelta a time_t
    time_t horaEntrada_t = mktime(&horaEntrada_tm);
    time_t horaSalida_t = mktime(&horaSalida_tm);

    return make_pair(horaEntrada_t, horaSalida_t);
}

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

// ACTUALIZAR SIGUIENDO LA ESTRUCTURA DE LA SIGUIENTE FUNCION

void imprimirDatosEmpleado()
{
    cout << "Nombre: " << nombres[i] << endl;
    cout << "Apellido: " << apellidos[i] << endl;
    cout << "Cedula: " << cedulas[i] << endl;
    cout << "Contraseña: " << claves[i] << endl;
}

// void imprimirAsistencia() {
//     for (size_t i = 0; i < empleados.size(); ++i) {

//         cout << "Empleado " << i + 1 << ":" << endl;

//         for (size_t j = 0; j < empleados[i].fechas.size(); ++j) {
//             cout << "Fecha: " << empleados[i].fechas[j] << endl;
//             cout << "Asistencia: " << empleados[i].asistencias[j] << endl;
//             cout << "Llegada Tarde: " << empleados[i].llegadaTarde[j] << endl;
//         }
//         cout << endl;
//     }
// }


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
