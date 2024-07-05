#include "personas.cpp"
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

#define ANIOACTUAL 2024

using namespace std;
using namespace chrono;

time_t horaEntrada_t, horaSalida_t;
char horaEntrada_str[9], horaSalida_str[9];

// Funciones para el informe
void ingresarEntradaSalida();
void guardarHoras();
void leerHoras();
int zeller(int anio, int mes, int dia);
int calcularDiasDelMes(int mes, int anio);

// Cuantificar las asistencias y llegadas tardes en un mes
void cuantificarAsistenciasYLlegadasTardes(int mes, int anio, int indexEmpleado);

void ingresarEntradaSalida()
{
    // Tomar el punto actual del calendario del sistema
    auto now = system_clock::now();

    // Convertir a time_t que representa el tiempo del calendario
    time_t now_time_t = system_clock::to_time_t(now);

    // Convertir a una estructura tm que representa la fecha y tiempo de un calendario
    tm *now_tm = localtime(&now_time_t);

    cout << "Define la hora de entrada y salida..." << endl;
    do
    {
        cout << "Hora de entrada (HH:MM:SS): ";
        cin >> horaEntrada_str;
        if (horaEntrada_str[0] == '\0')
        { // Si la cadena está vacía, limpia el buffer
            cin.ignore(10000, '\n');
        }
    } while (horaEntrada_str[0] == '\0'); // Repite si la cadena está vacía

    do
    {
        cout << "Hora de salida (HH:MM:SS): ";
        cin >> horaSalida_str;
        if (horaSalida_str[0] == '\0')
        { // Si la cadena está vacía, limpia el buffer
            cin.ignore(10000, '\n');
        }
    } while (horaSalida_str[0] == '\0'); // Repite si la cadena está vacía

    // Parsear la hora de entrada y salida a tm
    tm horaEntrada_tm = *now_tm, horaSalida_tm = *now_tm;
    sscanf(horaEntrada_str, "%2d:%2d:%2d", &horaEntrada_tm.tm_hour, &horaEntrada_tm.tm_min, &horaEntrada_tm.tm_sec);
    sscanf(horaSalida_str, "%2d:%2d:%2d", &horaSalida_tm.tm_hour, &horaSalida_tm.tm_min, &horaSalida_tm.tm_sec);

    // Parsear las estructuras tm devueltas a time_t
    horaEntrada_t = mktime(&horaEntrada_tm);
    horaSalida_t = mktime(&horaSalida_tm);
}

// Función para guardar las horas en un archivo usando char[]
void guardarHoras()
{
    ofstream file("horaEntradaSalida.txt");

    if (file.is_open())
    {
        // Guardar las representaciones de cadena
        file << horaEntrada_str << "\n";
        file << horaSalida_str << "\n";
        // Guardar los valores time_t
        file << horaEntrada_t << "\n";
        file << horaSalida_t << "\n";
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
}

// Función para leer las horas desde un archivo usando char[] y time_t
void leerHoras()
{
    ifstream file("horaEntradaSalida.txt");

    if (file.is_open())
    {
        file.getline(horaEntrada_str, sizeof(horaEntrada_str));
        file.getline(horaSalida_str, sizeof(horaSalida_str));
        // Leer los valores time_t
        file >> horaEntrada_t;
        file >> horaSalida_t;
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
}

void cuantificarAsistenciasYLlegadasTardes(int mes, int anio, int indexEmpleado)
{
    int totalAsistencias = 0;
    int totalLlegadasTardes = 0;
    anio = ANIOACTUAL;
    int diasDelMes = calcularDiasDelMes(mes, anio);

    for (int i = 0; i < MAX_FECHAS; i++)
    {
        if (empleados[indexEmpleado].arreglosFechas[i].mesDeFecha == mes)
        {
            totalAsistencias += empleados[indexEmpleado].arreglosFechas[i].asistencia;
            totalLlegadasTardes += empleados[indexEmpleado].arreglosFechas[i].llegadaEmpleado;
        }
    }

    // Creación del nombre del archivo
    char nombreArchivo[60];
    strcpy(nombreArchivo, "informe");
    strcat(nombreArchivo, empleados[indexEmpleado].infoUsuario.cedula); // Concatenar la cédula
    strcat(nombreArchivo, ".txt");                                      // Concatenar la extensión del archivo

    // Creación y apertura del archivo
    ofstream archivo(nombreArchivo);

    if (archivo.is_open())
    {
        // Escribir datos en el archivo
        archivo << "Nombre: " << empleados[indexEmpleado].nombre << " " << empleados[indexEmpleado].apellido << endl;
        archivo << "Mes: " << mes << " Año: " << anio << endl;
        archivo << "Días del mes: " << diasDelMes << endl;
        archivo << "Total de asistencias en el mes: " << totalAsistencias << endl;
        archivo << "Total de llegadas tardes en el mes: " << totalLlegadasTardes << endl;
        archivo << "Proporción de asistencias: " << totalAsistencias << "/" << diasDelMes << endl;
        archivo.close(); // Cerrar el archivo
    }
    else
    {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }

    // También mostrar los datos en consola
    cout << "Nombre: " << empleados[indexEmpleado].nombre << " " << empleados[indexEmpleado].apellido << endl;
    cout << "Mes: " << mes << " Año: " << anio << endl;
    cout << "Días del mes: " << diasDelMes << endl;
    cout << "Total de asistencias en el mes: " << totalAsistencias << endl;
    cout << "Total de llegadas tardes en el mes: " << totalLlegadasTardes << endl;
    cout << "Proporción de asistencias: " << totalAsistencias << "/" << diasDelMes << endl;
}

// Devuelve el dia de la semana
int zeller(int anio, int mes, int dia)
{
    int a = (14 - mes) / 12;
    int y = anio - a;
    int m = mes + 12 * a - 2;

    int d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    return d;
}

// Devuelve la cantidad de dias dependiendo del mes
int calcularDiasDelMes(int mes, int anio)
{
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
            return 29;
        else
            return 28;
    default:
        return 31;
    }
}