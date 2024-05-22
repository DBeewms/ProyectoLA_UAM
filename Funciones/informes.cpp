#include "personas.cpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <vector>
#include <sstream> // ostringstream

using namespace std;
using namespace chrono;

void pedirFecha();
pair<time_t, time_t> ingresarEntradaSalida();
void registrarAsistencia(time_t horaEntrada_t);
time_t calcularHorasExtra(time_t horaSalida_t);

int zeller(int anio, int mes, int dia);
int calcularDiasMes(int mes, int anio);

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

void registrarAsistencia(time_t horaEntrada_t, time_t horaSalida_t)
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
        //Asisgencia en tiempo
        fechas.push_back(formatted_date);
        horas.push_back(formatted_hora);
        asistencias.push_back(1);
    }
    else
    {
        // Llegada tarde
        fechas.push_back(formatted_date);
        horas.push_back(formatted_hora);
        llegadaTarde.push_back(1);
    }
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
int calcularDiasMes(int mes, int anio)
{
    int dias = 0;

    switch (mes)
    {
    case 1:
        dias = 31;
        break;
    case 2:
        if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
        {
            dias = 29;
        }
        else
        {
            dias = 28;
        }
        break;
    case 3:
        dias = 31;
        break;
    case 4:
        dias = 30;
        break;
    case 5:
        dias = 31;
        break;
    case 6:
        dias = 30;
        break;
    case 7:
        dias = 31;
        break;
    case 8:
        dias = 31;
        break;
    case 9:
        dias = 30;
        break;
    case 10:
        dias = 31;
        break;
    case 11:
        dias = 30;
        break;
    case 12:
        dias = 31;
        break;
    default:
        break;
    }
    return dias;
}