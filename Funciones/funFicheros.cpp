#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <chrono>
#include "personas.h"



//Se elaboraron funciones generales para cargar y guardar empleados en un archivo
void cargarEmpleadosDesdeArchivo(const char *nombreArchivo);
void guardarEmpleadosEnArchivo(const char *nombreArchivo);

// Se corre la funcion desde el inicio del programa para cargar los empleados y que se 
// encuentren en el arreglo de empleados
void cargarEmpleadosDesdeArchivo(const char *nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        archivo >> numEmpleados;
        archivo.ignore(); // Ignorar el salto de línea después del número de empleados
        for (int i = 0; i < numEmpleados; i++)
        {
            archivo.getline(empleados[i].nombre, MAX_STR);
            archivo.getline(empleados[i].apellido, MAX_STR);
            archivo >> empleados[i].infoUsuario.cedula;
            archivo.ignore(); // Ignorar el salto de línea:
            archivo.getline(empleados[i].infoUsuario.clave, SIZE_PASS + 1);
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}

// Función para guardar empleados en el archivo
//Se guarda el número de empleados y los datos de cada empleado
//Importante para editar y eliminar empleados
void guardarEmpleadosEnArchivo(const char *nombreArchivo)
{
    ofstream archivo(nombreArchivo);
    if (archivo.is_open())
    {
        archivo << numEmpleados << endl;
        for (int i = 0; i < numEmpleados; i++)
        {
            archivo << empleados[i].nombre << endl;
            archivo << empleados[i].apellido << endl;
            archivo << empleados[i].infoUsuario.cedula << endl;
            archivo << empleados[i].infoUsuario.clave << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
}
