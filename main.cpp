#include "Funciones/menu.cpp"

using namespace std;

int main()
{
    cargarEmpleadosDesdeArchivo("empleados.txt");
    menuPrincipal();
    return 0;
}

