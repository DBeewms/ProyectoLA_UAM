Proceso editarEmpleado
	Definir posicion Como Entero;
	Definir opcion como entero;
	
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
	
	Definir i Como Entero;
	
	
	
	Escribir "Ingrese la cedula del empleado: ";
	leer cedula;
	
	Para i <-0 Hasta ultimoRegistro -1 Con Paso 1 Hacer //Uso de la funcion buscar empleado
		Si cedula = cedulas[i] Entonces
			
			posicion <- i;
			
			//Uso de la funcion mostrar empleado
			Escribir "Ingrese la contrasenia del empleado: ";
			escribir "Los datos del empleado son los siguientes: ";
			Escribir "El nombre del empleado es: ", nombresEmpleados[posicion];
			Escribir "El ID del empleado es:", cedulas[posicion];
			Escribir "La contrasenia del empleado", contrasenas[posicion];
			
			Repetir
				escribir "Que quieres editar? ";
				escribir "1. Nombre";
				escribir "2. Cedula";
				escribir "3. contrasena";
				escribir "4. salir";
				escribir "Elige una opcion: ";
				leer opcion;
				
				Segun opcion Hacer
					1:
						Escribir 'Ingrese el nombre actualizado del empleado: ';
						Leer nombre;
						nombresEmpleados[posicion] <- nombre;
					2:
						Escribir 'Ingrese el ID actualizado del empleado:';
						Leer cedula;
						cedulas[posicion] <- cedula;
					3:
						Escribir "Ingrese la contrasenia actualizada para el empleado";
						leer contrasena;
						contrasenas[posicion] <- contrasena;
					4:
						Escribir "Vuelve pronto";
					De Otro Modo:
						Escribir "Lo siento, opcion invalida";
				FinSegun
			Hasta Que  opcion = 4
			
		SiNo
			Escribir "Lo siento, cedula invalida";
		FinSi
	FinPara
FinProceso
