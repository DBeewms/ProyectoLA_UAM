#include "admin.cpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstring>

int anio, mes, dias;

using namespace std;

// Funciones para el empleado

// Imprimir sus propios datos
void imprimirDatosEmpleadoEnEmpleados(int index);
// Registrar su asistencia
void registrarAsistencia(time_t horaEntrada_t, int indexEmpleado);
// Cargar las fechas desde un archivo CSV
void cargarFechasDesdeCSV(int indexEmpleado);
// Cargar las fechas para todos los empleados
void cargarFechasParaTodosLosEmpleados();


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

    // Convierte a una estructura tm que representa la fecha y tiempo de un calendario
    tm *now_tm = localtime(&now_time_t);

    // Representacion textual de una fecha y hora para mostrarla al usuario
    char formatted_date[11]; 
    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y", now_tm);

    char formatted_hora[9]; 
    strftime(formatted_hora, sizeof(formatted_hora), "%H:%M:%S", now_tm);

    // Tomar el formato de la hora local para el calculo de la diferencia
    tm formatoHoraActual_tm = *now_tm;
    int horas, minutos, segundos;
    sscanf(formatted_hora, "%d:%d:%d", &horas, &minutos, &segundos);

    // Ajustar la estructura tm
    formatoHoraActual_tm.tm_hour = horas;
    formatoHoraActual_tm.tm_min = minutos;
    formatoHoraActual_tm.tm_sec = segundos;

    // Parsear las estructuras tm devuelta a time_t
    time_t formatoHoraActual_t = mktime(&formatoHoraActual_tm);

    // Calcula la diferencia en segundos
    double diferenciaSegundos = difftime(formatoHoraActual_t, horaEntrada_t);

    // Convierte a minutos
    double diferenciaMinutos = (diferenciaSegundos / 60);

    // Lapso de tiempo de 5 min para la tolerancia
    double tolerancia = 5.0;

    // Encontrar la posicion vacia en el arreglo de Fechas
    for (int i = 0; i < MAX_FECHAS; i++)
    {
        if (empleados[indexEmpleado].arreglosFechas[i].fechaRegistrada[0] == '\0')
        {
            indexFechas = i;
            break;
        }
    }
    if (indexFechas == -1)
    {
        cout << "Lo lamentamos, el registro de fechas ha alcanzado su limite" << endl;
        return;
    }

    int mesActual = now_tm->tm_mon + 1;      // tm_mon es 0-indexado
    int anioActual = now_tm->tm_year + 1900; // tm_year cuenta desde 1900

    int diasDelMes = calcularDiasDelMes(mesActual, anioActual);

    // Agregar la fecha y hora formateada al arreglo.
    strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].fechaRegistrada, formatted_date);
    strcpy(empleados[indexEmpleado].arreglosFechas[indexFechas].horaRegistrada, formatted_hora);

    empleados[indexEmpleado].arreglosFechas[indexFechas].mesDeFecha = mesActual;
    empleados[indexEmpleado].arreglosFechas[indexFechas].diasDelMes = diasDelMes;

    // Marcar la asistencia del empleado
    empleados[indexEmpleado].arreglosFechas[indexFechas].asistencia = 1;

    // Marcar como llegada puntual o tarde
    empleados[indexEmpleado].arreglosFechas[indexFechas].llegadaEmpleado = (diferenciaMinutos <= tolerancia) ? 0 : 1;

    char nombreArchivo[19]; 
    strcpy(nombreArchivo, empleados[indexEmpleado].infoUsuario.cedula);
    strcat(nombreArchivo, ".csv");

    // Verificar si el archivo ya existe para decidir si se añade la cabecera
    bool archivoExiste = ifstream(nombreArchivo).good();

    // Abrir o crear el archivo en modo append
    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo.is_open())
    {
        cout << "Error al abrir o crear el archivo para el empleado con cedula: " << empleados[indexEmpleado].infoUsuario.cedula << endl;
        return;
    }

    // Si el archivo no existia, añadir cabecera
    if (!archivoExiste)
    {
        archivo << "Fecha,Hora,Asistencia,Llegada,Mes de la fecha,Dias del mes\n";
    }

    // Escribir los datos en formato CSV
    archivo << empleados[indexEmpleado].arreglosFechas[indexFechas].fechaRegistrada << ","
            << empleados[indexEmpleado].arreglosFechas[indexFechas].horaRegistrada << ","
            << (empleados[indexEmpleado].arreglosFechas[indexFechas].asistencia ? "Presente" : "Ausente") << ","
            << (empleados[indexEmpleado].arreglosFechas[indexFechas].llegadaEmpleado ? "Tarde" : "A tiempo") << ","
            << empleados[indexEmpleado].arreglosFechas[indexFechas].mesDeFecha << ","
            << empleados[indexEmpleado].arreglosFechas[indexFechas].diasDelMes << "\n";

    archivo.close();
}

void cargarFechasDesdeCSV(int indexEmpleado)
{
    char nombreArchivo[50];
    char cedulaTemp[MAX_CEDULA + 1];

    strncpy(cedulaTemp, empleados[indexEmpleado].infoUsuario.cedula, MAX_CEDULA);
    cedulaTemp[MAX_CEDULA] = '\0';

    sprintf(nombreArchivo, "%s.csv", cedulaTemp);

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo para el empleado con cedula: " << cedulaTemp << endl;
        return;
    }

    char linea[256];
    archivo.getline(linea, 256); // Omitir la cabecera

    while (archivo.getline(linea, 256))
    {
        FECHAS fecha;
        int campoActual = 0;
        char campoBuffer[256];
        int bufferIndex = 0;

        for (int i = 0; linea[i] != '\0'; ++i)
        {
            if (linea[i] == ',' || linea[i] == '\n' || linea[i + 1] == '\0')
            {
                campoBuffer[bufferIndex] = '\0'; // Finalizar el string actual

                // Asignar el campoBuffer al campo correspondiente
                switch (campoActual)
                {
                case 0:
                    strncpy(fecha.fechaRegistrada, campoBuffer, MAX_LONG_FECHA);
                    break;
                case 1:
                    strncpy(fecha.horaRegistrada, campoBuffer, MAX_LONG_HORAS);
                    break;
                case 2:
                    fecha.asistencia = (strcmp(campoBuffer, "Presente") == 0) ? 1 : 0;
                    break;
                case 3:
                    fecha.llegadaEmpleado = (strcmp(campoBuffer, "A tiempo") == 0) ? 0 : 1;
                    break;
                case 4:
                    fecha.mesDeFecha = atoi(campoBuffer);
                    break;
                case 5:
                    fecha.diasDelMes = atoi(campoBuffer);
                    break;
                }

                campoActual++;
                bufferIndex = 0; // Resetear el indice para el siguiente campo
                if (linea[i] == '\n')
                    break; // Si es el final de la linea, salir del bucle
            }
            else
            {
                campoBuffer[bufferIndex++] = linea[i]; // Agregar el caracter actual al buffer
            }
        }

        // Encontrar el empleado y asignar la fecha
        for (int i = 0; i < MAX_EMPLEADOS; i++)
        {
            if (strcmp(empleados[i].infoUsuario.cedula, cedulaTemp) == 0)
            {
                // Encontrar una posicion libre en el arreglo de fechas
                for (int j = 0; j < MAX_FECHAS; j++)
                {
                    if (empleados[i].arreglosFechas[j].fechaRegistrada[0] == '\0')
                    { // Si la fecha esta vacia, asignar la fecha
                        empleados[i].arreglosFechas[j] = fecha;
                        break;
                    }
                }
                break;
            }
        }
    }

    archivo.close();
}

void cargarFechasParaTodosLosEmpleados()
{
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    {
        if (empleados[i].infoUsuario.cedula[0] != '\0')
        { // Asumiendo que una cedula no vacia indica un empleado valido
            cargarFechasDesdeCSV(i);
        }
    }
}

