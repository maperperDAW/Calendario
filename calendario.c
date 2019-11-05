#include <stdio.h>
#include <stdbool.h>

bool es_bisiesto ( int year );
void calendario( int year, int month, int dia_pos, int dias_mes );

int main(){
	int year;
	int month;
	int dia_pos = 0; // Posición en la semana del día uno de cada mes.
	int resto_mes = 0; // Número de días que sobran de la última semana si el domingo de ese mes no es el último día del mes.
	// int inicio_switch;
	int dias_mes;
	int resto_mes_anterior;
	bool tipo_bis;
	int month_iter;


	printf("¿Mes (1..12)?");
	scanf("%d", &month);
	printf("¿Año (1601..3000)?");
	scanf("%d", &year);


	for ( int ii = 1601; ii <= year; ii++ ){
		tipo_bis = es_bisiesto( ii );
		resto_mes_anterior = resto_mes;
		if ( ii == year ){
			month_iter = month;
		}else{
			month_iter = 12;
		}
		for ( int jj = 1; jj <= month_iter; jj++ ){
		   switch( jj ) {
		      case 1:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 2:
			      if ( tipo_bis ){
			      	dias_mes = 29;
			      	resto_mes = resto_mes + dias_mes;
			      	resto_mes = resto_mes % 7;
			      }else{
			      	dias_mes = 28;
			      	resto_mes = resto_mes + dias_mes;
			      	resto_mes = resto_mes % 7;	
			      }			      	
			    break;
		      case 3:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 4:
		      	dias_mes = 30;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 5:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 6:
		      	dias_mes = 30;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 7:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 8:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 9:
		      	dias_mes = 30;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 10:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 11:
		      	dias_mes = 30;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      case 12:
		      	dias_mes = 31;
		      	resto_mes = resto_mes + dias_mes;
		      	resto_mes = resto_mes % 7;
		      	break;
		      	
			}
		}
	}
	if ( month != 12 ){
		dia_pos = resto_mes - ( dias_mes % 7) + 1;	
	}else{
		dia_pos = 7 - resto_mes_anterior;
	}
	//dia_pos = 43 - resto_mes - dias_mes;
	printf("El 1 del mes %d y del año %d es: %d \n", month, year, dia_pos);
	calendario( year, month, dia_pos, dias_mes );
	return 0;
}



bool es_bisiesto ( int year ){
	bool bisiesto = false;

	if ( (year % 4 == 0) && (!(year % 100 == 0) || ( (year % 400 == 0) ) )){
		bisiesto = true;
	}
	return bisiesto;
}

void calendario ( int year, int month, int dia_pos, int dias_mes ){
	//char mes_str[12];
	//char espacios[20];
	printf("\n\n");
	switch ( month ) {
		case 1:
			printf("ENERO              %d", year);
			break;
		case 2:
			printf("FEBRERO            %d", year);
			break;
		case 3:
			printf("MARZO              %d", year);
			break;
		case 4:
			printf("ABRIL              %d", year);
			break;
		case 5:
			printf("MAYO               %d", year);
			break;
		case 6:
			printf("JUNIO              %d", year);
			break;
		case 7:
			printf("JULIO              %d", year);
			break;
		case 8:
			printf("AGOSTO             %d", year);
			break;
		case 9:
			printf("SEPTIEMBRE         %d", year);
			break;
		case 10:
			printf("OCTUBRE            %d", year);
			break;
		case 11:
			printf("NOVIEMBRE          %d", year);
			break;
		case 12:
			printf("DICIEMBRE          %d", year);
			break;
	}
	
	printf("\n\n=======================\nLU MA MI JU VI | SA  DO\n");

	char array[6][23] = {
		{" .  .  .  .  . |  .   ."},
		{" .  .  .  .  . |  .   ."},
		{" .  .  .  .  . |  .   ."},
		{" .  .  .  .  . |  .   ."},
		{" .  .  .  .  . |  .   ."},
		{" .  .  .  .  . |  .   ."}
		};
	int array_pos[7] = {1, 4, 7, 10, 13, 18, 22}; // Posición de los puntos en la array.
	int cont = 1;
	int digit1;
	char digit1_c;
	int digit2;
	char digit2_c;

	for ( int ii = 0; ii < 6; ii++ ){
		for ( int jj = 1; jj <= 7; jj++ ){
			if ( ( (ii == 0) && ( jj >= dia_pos) ) || ( ii > 0 ) ){				
					if ( cont <= dias_mes){
						if ( ( cont / 10)  < 1 ){
							digit1 = (char) (48 + cont);
							array[ii][array_pos[jj-1]] = digit1;
							cont++;
						}else{
							digit1 = cont / 10;
							digit2 = cont - (cont / 10) * 10;
							digit1_c = (char)(48 + digit1);
							digit2_c = (char)(48 + digit2);
							array[ii][array_pos[jj-1]-1] = digit1_c;
							array[ii][array_pos[jj-1]] = digit2_c;
							cont++;
						}
					}

			}
		}
	}
	
	//Imprime el calendario
	for ( int ii = 0; ii < 6; ii++ ){
		for ( int jj = 0; jj < 23; jj++ ){
			printf("%c", array[ii][jj]);
		}
		printf("\n");
	}
	printf("\n\n\n");



}

/*
ABRIL              1971

=======================
LU MA MI JU VI | SA  DO
 .  .  .  1  2 |  3   4
 5  6  7  8  9 | 10  11
12 13 14 15 16 | 17  18
19 20 21 22 23 | 24  25
26 27 28 29 30  


tamaño del marco = 23
*/
