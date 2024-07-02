Proceso registrarEmpleado
	
	Definir posicion Como Entero;
	
	definir ultimoRegistro Como Entero;
	
	definir contrasena Como Caracter;
	Definir contrasenas Como Caracter;
	Dimension contrasenas[50];
	
	Definir nombre Como Caracter;
	Definir nombresEmpleados Como Caracter;
	Dimension nombresEmpleados[50];
	
	Definir fecha Como Caracter;
	Definir fechas Como Caracter;
	Dimension fechas[50];
	
	Definir cedula Como 	Caracter;
	Definir cedulas Como Caracter;
	Dimension cedulas[50];
	
	Definir hora Como Entero;
	Definir horas Como Entero;
	Dimension horas[50];
	
	Definir minuto Como Entero;
	Definir minutos Como Entero;
	Dimension minutos[50];
	
	posicion <- ultimoRegistro;
	
	//Ingreso de datos
	Escribir "Ingrese el nombre del empleado: ";
	Leer nombre;
	nombresEmpleados[posicion] <- nombre;
	Escribir "Ingrese la Cedula: de empleado:";
	Leer cedula;
	cedulas[posicion] <- cedula;
	Escribir "Ingrese la contrasenia para el empleado";
	leer contrasena;
	contrasenas[posicion] <- contrasena;
	
	ultimoRegistro <- ultimoRegistro + 1;	
FinProceso
