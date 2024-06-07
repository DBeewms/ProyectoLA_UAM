Proceso registrarAsistencia
	definir horaEntrada Como Entero;
	definir formatoHoraActual Como Entero;
	definir puntoActualCalendario Como Entero;
	definir diferenciaMinutos Como Entero;
	definir tolerancia Como Entero;
	
	Definir llegadaATiempo Como Entero;
	Definir llegadasATiempo Como Entero;
	Dimension llegadasATiempo[50];
	
	definir asistencia Como entero;
	definir asistencias Como Entero;
	Dimension asistencias[50];
	
	definir llegadaTarde Como Entero;
	definir llegadasATiempo como entero;
	Dimension llegadasATiempo[50];
	
	asistencias <- 0;
	llegadaATiempo <- 0;
	
	// Lapso de tiempo de 5 min para la tolerancia
	tolerancia <- 5;
	
	//Preguntar por la asistencia
	Escribir "Ingresa la hora de tu llegada (solo la hora / formato 24 horas):";
	Leer hora;
	
	Escribir "Ingrese los minutos de llegada:";
	Leer minuto;
	
	Si hora <= horaEntrada Entonces
		acciones_por_verdadero
	SiNo
		acciones_por_falso
	FinSi
	
	//Calcular diferencia de tiempo
	diferenciaMinutos <- formatoHoraActual - horaActual;
	
	
	Si diferenciaMinutos <= tolerancia Entonces
		// Guardar la asistencia en el vector
        // Asistencia en tiempo
		asistencia <- asistencia + 1;
		llegadaATiempo <- llegadaATiempo + 1;
	SiNo
		asistencia <- asistencia + 1;
		llegadaATiempo <- llegadaATiempo + 1;
	FinSi
FinProceso
