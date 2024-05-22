#include "admin.cpp"
#include <iostream>
#include <chrono>
#include <ctime>

int anio, mes, dias;

using namespace std;

int i = 0;

void registrarAsistencia(time_t horaEntrada_t);

void iniciarSesionEmpleado()
{
    char contrasena[sizePass];
    buscarEmpleado();

    cout << "Ingrese la contraseña: ";
    cin >> contrasena;

    if (claves[i] == contrasena)
    {
        cout << "Sesion iniciada" << endl;
    }
    else
    {
        cout << "Contraseña incorrecta" << endl;
    }
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
        nuevoEmpleado.asistencias.push_back(1);
        nuevoEmpleado.llegadaTarde.push_back(0);
    }
    else
    {
        // Llegada tarde
        nuevoEmpleado.fechas.push_back(formatted_date);
        nuevoEmpleado.horas.push_back(formatted_hora);
        nuevoEmpleado.asistencias.push_back(1);
        nuevoEmpleado.llegadaTarde.push_back(1);
    }

    empleados.push_back(nuevoEmpleado);
}
