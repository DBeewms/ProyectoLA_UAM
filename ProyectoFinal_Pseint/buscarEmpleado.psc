Proceso buscarEmpleado
	Definir posicion Como Entero;
	Definir opcion como entero;
	
	Definir ultimoRegistro Como Entero;
	
	Definir contrasena Como Caracter;
	Definir contrasenas Como Caracter;
	Dimension contrasenas[50];
	
	Definir nombre Como Caracter;
	Definir nombresEmpleados Como Caracter;
	Dimension nombresEmpleados[50];
	
	Definir fecha Como Caracter;
	Definir fechas Como Caracter;
	Dimension fechas[50];
	
	Definir cedula Como Caracter;
	Definir cedulas Como Caracter;
	Dimension cedulas[50];
	
	Definir hora Como Entero;
	Definir horas Como Entero;
	Dimension horas[50];
	
	Definir minuto Como Entero;
	Definir minutos Como Entero;
	Dimension minutos[50];
	
	Definir i Como Entero;
	
	//necesita parametro cedula
	Para i <- 0 Hasta ultimoRegistro -1 Con Paso 1 Hacer
		Si cedula = cedulas[i] Entonces 
			posicion <- i;
		SiNo
			Escribir "Lo siento, cedula invalida";
		FinSi
	FinPara
	
	
FinProceso
