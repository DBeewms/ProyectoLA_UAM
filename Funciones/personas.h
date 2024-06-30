//Librerias
#include <iostream>
#include <string>

//Constantes de empleados
#define MAX_EMPLEADOS 100
#define MAX_STR 50

//Constantes de Inicio de Sesion
#define MAX_ID 10
#define SIZE_PASS 10

//Constante de Fechas
#define MAX_LONG_FECHA 10
#define MAX_FECHAS 100
#define MAX_ASISTENCIAS 100

using namespace std;


// Variables globales
int numEmpleados = 0;


//Estructuras
struct INICIO_SESION
{
    int id;
    char clave[SIZE_PASS];
};

struct FECHAS
{
    int asistencia;
    int llegadaTarde;
    char fechaRegistrada[MAX_LONG_FECHA];
    int mesDeFecha;
    int diasDelMes;
};

struct EMPLEADO
{
    struct INICIO_SESION infoUsuario;
    char nombre[MAX_STR];
    char apellido[MAX_STR];
    struct FECHAS arreglosFechas[MAX_FECHAS];
} empleados[MAX_EMPLEADOS];

// typedef struct PERSONA
// {
//     char nombre;
//     char apellido;
//     char id;
//     char fechas[MAX_FECHAS];
//     char horas[MAX_HORAS];
//     int asistencias[MAX_ASISTENCIAS];
//     int llegadaTarde[MAX_LLEGADA_TARDE];
//     int inasistencias;
//     char horasExtras;
//     char clave;
//     int numFechas; // Contador para las fechas
//     int numHoras; // Contador para las horas
//     int numAsistencias; // Contador para asistencias
//     int numLlegadaTarde; // Contador para llegadas tarde
// };

// PERSONA empleados[MAX_EMPLEADOS];
// int numEmpleadosRegistrados = 0;