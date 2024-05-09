#include <iostream>
#include <cstdlib> //stdlib.h
#include <time.h>
#define sizePass 5

using namespace std;

void generarContrasena(char *contrasena);

void generarContrasena(char *contrasena)
{
    srand(time(0));
    for (int i = 0; i < sizePass; i++)
    {
        int num = rand() % 10;
        contrasena[i] = '0' + num;
    }
    contrasena[sizePass] = '\0';
}
