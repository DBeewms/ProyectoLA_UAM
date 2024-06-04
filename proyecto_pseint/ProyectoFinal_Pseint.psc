Algoritmo calcularSalarioNeto
	definir opcion Como Entero;
	definir i Como Entero;
	definir posicion Como Entero;
	Definir llegada Como Logico;
	
	Definir nombre Como Caracter;
	definir nombres Como Caracter;
	Dimension nombres[50];
	
	Definir fecha Como Caracter;
	definir fechas Como Caracter;
	Dimension fechas[50];
	
	Definir empleado Como entero;
	definir empleados Como entero;
	Dimension empleados[50];
	
	Definir hora Como entero;
	definir horas Como entero;
	Dimension horas[50];
	
	Definir minuto Como entero;
	definir minutos Como entero;
	Dimension minutos[50];
	
	
	posicion <- 0;
	
	Repetir
		Escribir "Escoge tus opciones";
		Escribir "1. Agregar datos";
		Escribir "2. Mostrar datos";
		Escribir "3. Salir";
		leer opcion;
		
		Segun opcion Hacer
			1:
				Escribir "Ingresa tu nombre:";
				Leer nombre;
				nombres[posicion] <- nombre;
				
				Escribir "Ingresa tu ID de empleado:";
				Leer empleado;
				empleados[posicion] <- empleado;
				
				Escribir "Ingresa la fecha de tu llegada:";
				Leer fecha;
				fechas[posicion] <- fecha;
				
				Escribir "Ingresa la hora de tu llegada (formato 24 horas):";
				Leer hora;
				horas[posicion] <- hora;
				
				Escribir "Ingrese los minutos de llegada:";
				Leer minuto;
				minutos[posicion] <- minuto;
				posicion <- posicion + 1;
				
			2:
				Para i <-0 Hasta posicion - 1 Con Paso 1 Hacer
					
					Si horas[i] > 9 o (horas[i] = 9 y minutos[i] > 0) Entonces
						llegada <- Verdadero;
					Sino
						llegada <- Falso;
					FinSi
					
					Si llegada Entonces
						Escribir "El empleado ", nombres[i], " con ID ", empleados[i], " llegó tarde el ", fechas[i], " a las ", horas[i],":", minutos[i];
						Escribir "";
					Sino
						Escribir "El empleado ", nombres[i], " con ID ", empleados[i], " llegó puntual el ", fechas[i], " a las ", horas[i],":", minutos[i];
						Escribir "";
					FinSi
				FinPara
			3:
				Escribir "Saliendo...";
			De Otro Modo:
				escribir "Opcion invalida, vuelve a intentarlo";
		FinSegun
	Hasta Que opcion = 3
	
FinAlgoritmo