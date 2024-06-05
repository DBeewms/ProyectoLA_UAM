#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_EMPLEADOS 100
#define MAX_FECHAS 100
#define MAX_HORAS 100
#define MAX_ASISTENCIAS 100
#define MAX_LLEGADA_TARDE 100
#define SIZE_PASS 10

typedef struct PERSONA
{
    string nombre;
    string apellido;
    string cedula;
    string fechas[MAX_FECHAS];
    string horas[MAX_HORAS];
    int asistencias[MAX_ASISTENCIAS];
    int llegadaTarde[MAX_LLEGADA_TARDE];
    int inasistencias;
    string horasExtras;
    string clave;
    int numFechas; // Contador para las fechas
    int numHoras; // Contador para las horas
    int numAsistencias; // Contador para asistencias
    int numLlegadaTarde; // Contador para llegadas tarde

    PERSONA() : inasistencias(0), numFechas(0), numHoras(0), numAsistencias(0), numLlegadaTarde(0) {}
};

PERSONA empleados[MAX_EMPLEADOS];
int numEmpleadosRegistrados = 0;