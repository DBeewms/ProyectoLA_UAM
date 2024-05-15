#include "personas.cpp"
#include <iostream>
#include <chrono>
#include <ctime>

int anio, mes, dias;

//Guarda la fecha como string en un vector

/*
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

vector<string> asistencias;

int main(int argc, char const *argv[])
{
    auto start = chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(start);
    cout << "La hora UTC es: " << ctime(&start_time);

    asistencias.push_back(ctime(&start_time));

    cout << asistencias[0] << endl;

    return 0;
}
*/


void registrarFecha()
{
    cout << "Ingresa el año: ";
    cin >> anio;
    cout << "Ingresa el mes: ";
    cin >> mes;
    cout << "Ingresa el dia: ";
    cin >> dias;

    if (mes >= 1 && mes <= 12)
    {
        if (dias <= calcularDiasMes(mes, anio) && dias > 0)
        {
            cout << "Fecha: " << dias << "/" << mes << "/" << anio << endl;
            cout << "Fecha actualizada" << endl;
        }
    }
    else
    {
        cout << "Fecha incorrecta" << endl;
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