#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip> // put_time
#include <sstream> // ostringstream

#define MAX_SIZE 100
#define MAX_REG 200

using namespace std;
using namespace chrono;

typedef struct PERSONA
{
    char nombre[100];
    string cedula;
    string fechas[MAX_SIZE];
    string horas[MAX_SIZE];
    int asistencias[MAX_SIZE];
    int llegadaTarde[MAX_SIZE];
};

int lastReg = 0;

// CRUD
PERSONA getEmpleado(int index);

void agregarEmpleado(PERSONA empleadoCreado);
int buscarEmpleado(string cedula);
void editarEmpleado(PERSONA empleadoTemp, int index);
void eliminarEmpleado(int index);

void mostrarEmpleado(int index);

PERSONA empleados[MAX_REG];

void imprimirAsistencia();

// ASISTENCIA
void pedirFecha();
pair<time_t, time_t> ingresarEntradaSalida();
void registrarAsistencia(time_t horaEntrada_t);
time_t calcularHorasExtra(time_t horaSalida_t);

int main()
{
    int op = 0;
    time_t horaEntrada_t, horaSalida_t;
    pair<time_t, time_t> horasEntradaSalida;

    do
    {
        system("cls");
        cout << "1. Ingresar hora de entrada y salida" << endl;
        cout << "2. Registrar asistencia" << endl;
        cout << "3. Mostrar registro de asistencias" << endl;
        cout << "5. Salir" << endl;
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            horasEntradaSalida = ingresarEntradaSalida();
            horaEntrada_t = horasEntradaSalida.first;
            horaSalida_t = horasEntradaSalida.second;
            break;
        case 2:
            system("cls");
            registrarAsistencia(horaEntrada_t);
            cout << "Asistencia registrada" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            imprimirAsistencia();
            system("pause");
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (op != 5);

    return 0;
}

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

void registrarAsistencia(time_t horaEntrada_t)
{
    // Tomar el punto actual del calendario del sistema
    auto now = system_clock::now();

    // Convertir a time_t que representa el tiempo del calendario
    time_t now_time_t = system_clock::to_time_t(now);

    // Convierte a un estrucutra tm que representa la fecha y tiempo de un calendario
    tm *now_tm = localtime(&now_time_t);

    // Crea un stringstream para formatear la fecha
    ostringstream date_stream_fecha;
    date_stream_fecha << put_time(now_tm, "%d-%m-%Y");
    // Save the formatted date as a string
    string formatted_date = date_stream_fecha.str();

    // Crea un stringstream para formatear la hora
    ostringstream date_stream_hora;
    date_stream_hora << put_time(now_tm, "%H:%M:%S");
    // Save the formatted date as a string
    string formatted_hora = date_stream_hora.str();

    // Tomar el formato de la hora local para el calculo de la diferencia
    tm formatoHoraActual_tm = *now_tm;
    stringstream formatoHoraActual_ss(formatted_hora);
    formatoHoraActual_ss >> get_time(&formatoHoraActual_tm, "%H:%M:%S");

    // Parsear las estructuras tm devuelta a time_t
    time_t formatoHoraActual_t = mktime(&formatoHoraActual_tm);

    // Calcula la diferencia en segundos
    double diferenciaSegundos = difftime(formatoHoraActual_t, horaEntrada_t);

    // Convierte a minutos
    double diferenciaMinutos = (diferenciaSegundos / 60);

    // Lapso de tiempo de 5 min para la tolerancia
    double tolerancia = 5.0;

    if (diferenciaMinutos <= tolerancia)
    {
        // Guardar la asistencia en el vector
        // Asisgencia en tiempo
        nuevoEmpleado.fechas.push_back(formatted_date);
        nuevoEmpleado.horas.push_back(formatted_hora);
        nuevoEmpleado.asistencias.push_back("1");
        nuevoEmpleado.llegadaTarde.push_back("0");
    }
    else
    {
        // Llegada tarde
        nuevoEmpleado.fechas.push_back(formatted_date);
        nuevoEmpleado.horas.push_back(formatted_hora);
        nuevoEmpleado.asistencias.push_back("1");
        nuevoEmpleado.llegadaTarde.push_back("1");
    }

    empleados.push_back(nuevoEmpleado);
}


// Funciones copiadas del repositorio documentacion


void imprimirAsistencia()
{
    // Determina el tamaño del arreglo fechas, dentro del arreglo empleados de tipo persona
    for (size_t i = 0; i < sizeof(empleados) / sizeof(empleados[0]); ++i)
    {
        cout << "Empleado " << i + 1 << ":" << endl;

        size_t size = sizeof(empleados[i].fechas) / sizeof(empleados[i].fechas[0]);

        for (size_t j = 0; j < size; ++j)
        {
            cout << "Fecha: " << empleados[i].fechas[j] << endl;
            cout << "Asistencia: " << empleados[i].asistencias[j] << endl;
            cout << "Llegada Tarde: " << empleados[i].llegadaTarde[j] << endl;
        }
    }
}

void empleadoInicial(int index)
{
    // Crea una cadena vacia
    empleados[index].cedula[0] = '\0';
}

void agregarEmpleado(PERSONA empleadoCreado)
{
    empleados[lastReg] = empleadoCreado;
    lastReg++;
}

PERSONA getEmpleado(int index)
{
    return empleados[index];
}

int buscarEmpleado(string cedula)
{
    int index = -1;

    for (int i = 0; i < lastReg; i++)
    {
        if (cedula == empleados[i].cedula)
        {
            index = i;
            break;
        }
    }
    return index;
}

void editarEmpleado(PERSONA empleadoTemp, int index)
{
    empleados[index] = empleadoTemp;
}

void borrarEmpleado(int index)
{
    if (index == lastReg)
    {
        cout << "Empleado no registrado" << endl;
        return;
    }	
    for (int i = index; i < lastReg - 1; i++)
    {
        empleados[i] = empleados[i + 1];
    }
    lastReg--;

    empleadoInicial(lastReg);
}


// Funciones para asistencia
// buscar, get, borrar
// buscar
// get
// borrar



