#include "Funciones/menu.cpp"

using namespace std;

int main()
{
    leerHoras();
    cargarEmpleadosDesdeArchivo("empleados.txt");
    cargarFechasParaTodosLosEmpleados();
    menuPrincipal();
    return 0;
}

