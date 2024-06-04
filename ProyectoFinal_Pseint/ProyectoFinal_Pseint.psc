SubProceso agregarEmpleado(opcion, posicion, llegada, nombre, nombres, fecha, fechas, empleado, empleados, hora, horas, minuto, minutos)
	Escribir 'Ingresa tu nombre:';
	Leer nombre;
	nombres[posicion] <- nombre;
	Escribir 'Ingresa tu ID de empleado:';
	Leer empleado;
	empleados[posicion] <- empleado;
	Escribir 'Ingresa la fecha de tu llegada:';
	Leer fecha;
	fechas[posicion] <- fecha;
	Escribir 'Ingresa la hora de tu llegada (formato 24 horas):';
	Leer hora;
	horas[posicion] <- hora;
	Escribir 'Ingrese los minutos de llegada:';
	Leer minuto;
	minutos[posicion] <- minuto;
FinSubProceso


SubProceso mostrarEmpleados(i, posicion, llegada, horas, minutos, nombres, empleados, fechas)
	Para i<-0 Hasta posicion-1 Hacer
		Si horas[i]>9 O (horas[i]=9 Y minutos[i]>0) Entonces
			llegada <- Verdadero;
		SiNo
			llegada <- Falso;
		FinSi
		Si llegada Entonces
			Escribir 'El empleado ',nombres[i],' con ID ',empleados[i],' llegó tarde el ',fechas[i],' a las ',horas[i],':',minutos[i];
			Escribir '';
		SiNo
			Escribir 'El empleado ',nombres[i],' con ID ',empleados[i],' llegó puntual el ',fechas[i],' a las ',horas[i],':',minutos[i];
			Escribir '';
		FinSi
	FinPara
FinSubProceso


SubProceso editarEmpleado(j, posicion, nombres, empleados)
	Definir nombreTemp Como Caracter;
	Definir nuevoNombre, nuevoID Como Caracter;
	Escribir "Dime el nombre del empleado a editar: ";
	Leer nombreTemp;
	
	Para j<-0 Hasta posicion-1 Hacer
		Si nombreTemp = nombres[j] Entonces;
			Escribir "Empleado: ";
			Escribir nombres[j];
			Escribir "ID: ";
			Escribir empleados[j];
		
			Escribir "";
			Escribir "Editando...";
			Escribir "Nuevo nombre: ";
			Leer nuevoNombre;
			Escribir "Nuevo ID: ";
			Leer nuevoID;
		
			nombres[j] <- nuevoNombre;
			empleados[j] <- nuevoID;
		SiNo 
			Escribir "Empleado no encontrado.";
		FinSi
	FinPara
	
FinSubProceso



Proceso main
	Definir opcion Como Entero;
	Definir i Como Entero;
	Definir posicion Como Entero;
	
	Definir llegada Como Logico;
	
	Definir nombre Como Caracter;
	Definir nombres Como Caracter;
	Dimension nombres[50];
	
	Definir fecha Como Caracter;
	Definir fechas Como Caracter;
	Dimension fechas[50];
	
	Definir empleado Como 	Caracter;
	Definir empleados Como Caracter;
	Dimension empleados[50];
	
	Definir hora Como Entero;
	Definir horas Como Entero;
	Dimension horas[50];
	
	Definir minuto Como Entero;
	Definir minutos Como Entero;
	Dimension minutos[50];
	
	Definir j Como Entero;
	j <- 0;
	
	posicion <- 0;
	llegada <- Falso;
	nombre <- "";
	fecha <- "";
	empleado <- "";
	hora <- 0;
	minuto <- 0;
	
	i <- 0;
	
	Repetir
		Escribir 'Escoge tus opciones';
		Escribir '1. Agregar datos';
		Escribir '2. Mostrar datos';
		Escribir '3. Editar empleado';
		Escribir '4. Salir';
		Leer opcion;
		
		Segun opcion  Hacer
			1:
				agregarEmpleado(opcion, posicion, llegada, nombre, nombres, fecha, fechas, empleado, empleados, hora, horas, minuto, minutos);
				posicion <- posicion+1;
			2:
				mostrarEmpleados(i, posicion, llegada, horas, minutos, nombres, empleados, fechas);
				
			3: 	
				editarEmpleado(j, posicion, nombres, empleados);
			4:
				Escribir 'Saliendo...';
			De Otro Modo:
				Escribir 'Opcion invalida, vuelve a intentarlo';
		FinSegun
	Hasta Que opcion=4
FinProceso
