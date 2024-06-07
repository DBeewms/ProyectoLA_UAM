Proceso eliminarEmpleado
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
	

	
	Escribir "Ingrese la cedula del empleado: ";
	leer cedula;
	
	Para i <- 0 Hasta ultimoRegistro Con Paso 1 Hacer
		Si cedula = cedulas[i] Entonces //Uso de la funcion buscar empleado
			posicion <- i;
			Escribir "Ingrese la contrasenia del empleado: "; //Uso de la funcion mostrar empleado
			escribir "Los datos del empleado son los siguientes: ";
			Escribir "El nombre del empleado es: ", nombresEmpleados[posicion];
			Escribir "El ID del empleado es:", cedulas[posicion];
			Escribir "La contrasenia del empleado", contrasenas[posicion];
		SiNo
			Escribir "Lo siento, cedula invalida";
		FinSi
		
		Escribir "Estas seguro que quieres eliminar este empleado? ";
		Escribir "1. Si";
		Escribir "2. No";
		leer opcion;
		
			Segun opcion Hacer
				1:
					Si posicion = ultimoRegistro  Entonces
						acciones_por_verdadero
					SiNo
						Para i <- posicion Hasta ultimoRegistro -1 Con Paso 1 Hacer
							secuencia_de_acciones
						FinPara
					FinSi
				2:
					escribir "Vuelve pronto";
				De Otro Modo:
					Escribir "Opcion Invalida";
			FinSegun
		
		
	FinPara
	
	
FinProceso
