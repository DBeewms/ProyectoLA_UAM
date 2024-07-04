#include "personas.cpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <sstream> // ostringstream

using namespace std;
using namespace chrono;

// Usar estas variables al implementar las funciones:

// time_t horaEntrada_t, horaSalida_t;
// pair<time_t, time_t> horasEntradaSalida;

// // Funciones
// void pedirFecha();

// Establecer la hora de entrada y salida de un empleado
pair<time_t, time_t> ingresarEntradaSalida();

// //Calcular las horas extras de un empleado
// time_t calcularHorasExtra(time_t horaSalida_t);

int zeller(int anio, int mes, int dia);
int calcularDiasMes(int mes, int anio);

pair<time_t, time_t> ingresarEntradaSalida()
{
    string horaEntrada_str, horaSalida_str;

    // Tomar el punto actual del calendario del sistema
    auto now = system_clock::now();

    // Convertir a time_t que representa el tiempo del calendario
    time_t now_time_t = system_clock::to_time_t(now);

    /*Convertir un tiempo en formato time_t a una estructura tm que representa la fecha
    y hora local, permitiendo un acceso más fácil a cada componente de la fecha y hora.*/
    tm *now_tm = localtime(&now_time_t);

    // Pedir hora de entrada y de salida
    cout << "Define la hora de entrada y salida..." << endl;
    cout << "Hora de entrada (HH:MM:SS): ";
    cin >> horaEntrada_str;
    cout << "Hora de salida (HH:MM:SS): ";
    cin >> horaSalida_str;

    // Parsear la hora de entrada y salida a tm
    tm horaEntrada_tm = *now_tm, horaSalida_tm = *now_tm; // Creacion e inicializacion de variables tipo tm
    stringstream horaEntrada_ss(horaEntrada_str), horaSalida_ss(horaSalida_str);

    /*Utilizan el operador de extracción (>>) para leer datos de los objetos stringstream*/
    horaEntrada_ss >> get_time(&horaEntrada_tm, "%H:%M:%S");
    horaSalida_ss >> get_time(&horaSalida_tm, "%H:%M:%S");
    /*La función get_time se utiliza para interpretar los datos leídos de
    acuerdo con el formato especificado ("%H:%M:%S")*/

    // Parsear las estructuras tm devuelta a time_t
    time_t horaEntrada_t = mktime(&horaEntrada_tm);
    time_t horaSalida_t = mktime(&horaSalida_tm);

    /*Por que no pasar directamente a time_t?
    Se obtiene la validación y normalización de la fecha y hora automáticamente.
    Se ajustan los valores de tm si son incoherentes,
    y esto no es algo que se obtendría fácilmente parseando directamente a time_t.*/

    return make_pair(horaEntrada_t, horaSalida_t); // Devuelve un PAR de valores
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