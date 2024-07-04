#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <sstream> // ostringstream
#include "admin.cpp"

int anio, mes, dias;

using namespace std;



//Funciones para el empleado
    //Imprimir sus propios datos
void imprimirDatosEmpleadoEnEmpleados(int index);
    //Registrar su asistencia
void registrarAsistencia(time_t horaEntrada_t);

void imprimirDatosEmpleadoEnEmpleados(int index)
{
    system("cls || clear");
    cout << "Datos del empleado:" << endl;
    cout << "Nombre: " << empleados[index].nombre << endl;
    cout << "Apellido: " << empleados[index].apellido << endl;
    cout << "Cedula: " << empleados[index].infoUsuario.cedula << endl;
    system("pause");
}


void registrarAsistencia(time_t horaEntrada_t, int indexEmpleado)
{
    int indexFechas = -1;
    // Tomar el punto actual del calendario del sistema
    auto now = system_clock::now();

    // Convertir a time_t que representa el tiempo del calendario
    time_t now_time_t = system_clock::to_time_t(now);

    // Convierte a un estrucutra tm que representa la fecha y tiempo de un calendario
    
    tm *now_tm = localtime(&now_time_t);
    
    //Representación textual de una fecha para mostrarla al usuario
        // Crea un stringstream para formatear la fecha
    ostringstream date_stream_fecha;
    date_stream_fecha << put_time(now_tm, "%d-%m-%Y");
        //La fecha se escribirá en el formato de día-mes-año como cadena
    string formatted_date = date_stream_fecha.str();

    // Crea un stringstream para formatear la hora
    ostringstream date_stream_hora;
    date_stream_hora << put_time(now_tm, "%H:%M:%S");
    // Guarda la hora formateada como cadena
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
        //Conversion de strings a char
        char formatted_date_char[9];
        strcpy(formatted_date_char, formatted_date.c_str());

        char formatted_hora_char[9];
        strcpy(formatted_hora_char, formatted_hora.c_str());
        
        // Guardar la asistencia en el arreglo
            // Asistencia en tiempo

        //Encontrar la posicion vacia en el arreglo de Fechas
        for (int i = 0; i < MAX_FECHAS; i++)//Ciclo para encontrar la primera posicion vacia
        {
            if (empleados[indexEmpleado].arreglosFechas[i].fechaRegistrada[0] == '\0')
            {
                indexFechas = i;
                break;
            }
        }
        if (indexFechas = -1)
        {
            cout << "Lo lamentamos, el registro de fechas ha alcanzado su limite" << endl;
            return;
        }
        

            //Agregar la fecha formateada al arreglo.
        strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].fechaRegistrada, formatted_date_char);
                
            //Agregar la hora formateada al arreglo.
        strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].horaRegistrada, formatted_hora_char);
        
            //Marcar la asistencia del empleado
            /*0 en asistencia indica una inasistencia, mientras que 1 indica que el empleado asistio*/
        empleados[indexEmpleado].arreglosFechas[indexFechas].asistencia = 1;

            //Marcar como llegada puntual
            /*0 en llegadaEmpleado indica que el empleado llego a tiempo, mientras que 1 indica que llego tarde*/
        empleados[indexEmpleado].arreglosFechas[indexFechas].llegadaEmpleado = 0;
    }
    else
    {
        //Conversion de strings a char
        char formatted_date_char[9];
        strcpy(formatted_date_char, formatted_date.c_str());

        char formatted_hora_char[9];
        strcpy(formatted_hora_char, formatted_hora.c_str());
        
        // Guardar la asistencia en el arreglo
            // Asistencia en tiempo

        //Encontrar la posicion vacia en el arreglo de Fechas
        for (int i = 0; i < MAX_FECHAS; i++)//Ciclo para encontrar la primera posicion vacia
        {
            if (empleados[indexEmpleado].arreglosFechas[i].fechaRegistrada[0] == '\0')
            {
                indexFechas = i;
                break;
            }
        }

            //Agregar la fecha formateada al arreglo.
        strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].fechaRegistrada, formatted_date_char);
                
            //Agregar la hora formateada al arreglo.
        strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].horaRegistrada, formatted_hora_char);
        
            //Marcar la asistencia del empleado
            /*0 en asistencia indica una inasistencia, mientras que 1 indica que el empleado asistio*/
        empleados[indexEmpleado].arreglosFechas[indexFechas].asistencia = 1;

            //Marcar como llegada tarde
            /*0 en llegadaEmpleado indica que el empleado llego a tiempo, mientras que 1 indica que llego tarde*/
        empleados[indexEmpleado].arreglosFechas[indexFechas].llegadaEmpleado = 1;
    }
}
