Proceso registrarAsistencia
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
	
	Definir i Como Entero;
	definir horaEntrada Como Entero;
	definir formatoHoraActual Como Entero;
	definir puntoActualCalendario Como Entero;
	definir diferenciaMinutos Como Entero;
	definir tolerancia Como Entero;
	
	definir hora como entero;
	definir minutos como entero;
	
	Definir llegadaATiempo Como Entero;
	Definir llegadasATiempo Como Entero;
	Dimension llegadasATiempo[50];
	
	definir asistencia Como entero;
	definir asistencias Como Entero;
	Dimension asistencias[50];
	
	definir llegadaTarde Como Entero;
	definir llegadasTarde como entero;
	Dimension llegadasTarde[50];
	
	asistencias <- 0;
	llegadaATiempo <- 0;
	
	// Lapso de tiempo de 5 min para la tolerancia
	tolerancia <- 5;
	
	Escribir "Ingrese la cedula del empleado: ";
	leer cedula;
	
	Para i <- 0 Hasta ultimoRegistro -1 Con Paso 1 Hacer
		Si cedula = cedulas[i] Entonces //Uso de la funcion buscar empleado
			posicion <- i;
			
			//Preguntar por la asistencia
			Escribir "Ingresa la fecha";
			Escribir "Ingresa la hora de tu llegada (solo la hora / formato 24 horas):";
			Leer fecha;
			fechas[posicion] <- fecha;
			
			Escribir "Ingrese los minutos de llegada:";
			Leer minutos;
			
			Si hora <= horaEntrada Entonces
				Si minutos <= tolerancia Entonces
					//Sumar asistencia
					asistencia <- asistencia + 1;
					asistencias[posicion] <- asistencia;
					
					//Sumar puntual
					llegadaATiempo <- llegadaATiempo + 1;
					llegadasATiempo[posicion] <- llegadaATiempo;
				
				SiNo
					//Sumar asistencia
					asistencia <- asistencia + 1;
					asistencias[posicion] <- asistencia;
					
					//Sumar retraso
					llegadaTarde <- llegadaTarde + 1;
					llegadasTarde[posicion] <- llegadaTarde;
				FinSi
			SiNo
				Escribir "Has marcado asistencia con retraso";
				//Sumar asistencia
				asistencia <- asistencia + 1;
				asistencias[posicion] <- asistencia;
				//Sumar retraso
				llegadaTarde <- llegadaTarde + 1;
				llegadasTarde[posicion] <- llegadaTarde;
				
				
			FinSi
			
		SiNo
			Escribir "Lo siento, cedula invalida";
		FinSi
	FinPara
	

FinProceso
