	//			||	4_EDAI_2018II_CODE1	||

/*
	------------------------------------------------------------------------------------------
	Descripción de prácticas para la archivo.
	
	Uso de variables:
	
		Las variables se nombran de la siguiente manera: 
				
				(Tipo-de-variable)(Tipo-dato)_(palabra_en_funcion_del_uso_de_la_variable)  
	
				Global  = g		int   = i	* Al momento de declararla se requiere hacer una	
				funcion = f 	float = f		descripción de su uso dentro del programa.
								char  = c
				
		Al momento de declararla, por ejemplo:
					
						int fi_contadorUsuario 	// Contador del número que ingresa el usuario 
						int fi_contadorPc;	// Contador del número génerado por el pc.
				
		* Las variables que tienen la finalidad de actuar cómo contadores dentro de un 
		ciclo, son i, j, k y l. (En ese orden conforme se este trabajando).
			
	Uso de funciónes:
	
		Las funciónes se nombran de acuerdo con el siguiente criterio:
		
			(Tipo-de-funcion)_(descripción_Cada_palabra_inicil_con_mayuscula)
			
			void	= v			* Al momento de declararla se requiere hacer una
			int		= i				descripción de su uso dentro del programa.
				
		Al momento de declararla, por ejemplo:
		
						i_SumaDatos , v_RestaResultados , i_ImprimirDatos 	
	------------------------------------------------------------------------------------------
	El Programa realiza la ímplementación del cofrado César.								 °
	------------------------------------------------------------------------------------------
	This program is free software: you can redistribute it and/or modify it under the terms
	of the GNU General Public License as published by the Free Software Foundation, either
	version 3 of the License, or (at your option) any later version. 
	
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	
	See the GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License along with this program.
	If not, see <http://www.gnu.org/licenses/>. 
	
	Author Original: Jorge A. Solano 
													 		 
	Original lines of the author contains the following mark '°' on the comments.
	
	------------------------------------------------------------------------------------------
*/

/*		1- Librerias		*///--------------------------------------------------------------

	#include <stdio.h> 		 // Contiene las funciones usadas estandar usadas en el programa.°
	#include <string.h>		 // Contiene la función fgets
	#include <ctype.h>		 // Contiene la finción toupper
	#include <time.h>		 // Contiene a la función Sleep
	
/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------
	#define TAM_PALABRA 20 					 // Crea la constante TAM_PALABRA				 °
	#define TAM_ABC 26						 // Crea la constante TAM_ABC					 °
	
	/*
		Los arreglos abecedarioEnClaro y abecedarioCifrado se usan como parametros de cambio
		dentro de las funciones de cifrar y descifrar, pero se envían a imprimir en la función
		principal. 
	*/
	
	char abecedarioEnClaro[TAM_ABC] = {'A','B','C','D','E','F','G','H','I',				//	 °
									   'J','K','L','M','N','O','P','Q','R',				//	 °
									   'S','T','U','V','W','X','Y','Z'		};			//	 °
	char abecedarioCifrado[TAM_ABC] = {'D','E','F','G','H','I','J','K','L',				//	 °
									   'M','N','O','P','Q','R','S','T','U',				//	 °
									   'V','W' ,'X','Y','Z','A','B','C'		}; 			//	 °
 
/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------

	void cifrar(char *textoEnClaro); 	 // Esta función cifra el mensaje.					 °
	void descifrar(char *textoCifrado);  // Decifra el mensaje.								 °
	void v_PrintMaqueta(int parametro);	 // Imprime un membrete.
	int i_ValorDeEntrada(); // Resive los valores de entrada del usuario.
	void v_TextoAMayuscula(char *);		 // Cambia los valores a letras mayusculas.
	
/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal 			*///--------------------------------------------------
										 //		Función Principal. 
										 // Crea un menú para la interacción con el usuario.
										 //		Genera las opciones:
										 //			a)	Ingresar la parabra a cifrar.
										 //			b)	Ingresar la palabra a descifrar
										 //			c)	Salir.
	int main()		// °
	{
		short opcion = 0, contador, divisor = 0 , registro = 0, i = 0 ;							
		char palabra[20];   			// Cadena que guardara la entrada del usuario        ° 
		char *palabra_paso;				// Apuntador para el paso por referencia de los datos.
		
		/*
			
		*/
				
		while (1) 																		//   °
		{
			system("cls");
			v_PrintMaqueta(0);
			
			if ( registro == 0 )
			{
				for ( contador = 0 ; contador < 20 ; contador++)palabra[contador] = ' ';
			}
			
			printf("\n\t\tCIFRADO C%cSAR\n\n\tValores de las letras:\n", 144);
			
			for ( contador = 0 ; contador < 26 ; contador++ )
			{
				if( divisor == 8 )
				{
					printf("\n");	
					divisor = 0;
				}
				printf( "| %c = %c |", *(abecedarioEnClaro+contador) , *(abecedarioCifrado+contador));
				divisor++;	
			}
			
			printf("\n\n\tElige una opci%cn:\n\t\t1) Cifrar\n\t\t2) Desifrar\n\t\t3) Salir\n\t", 162);
			opcion = i_ValorDeEntrada();
			
			switch(opcion)																// °
			{
				case 1:																	// °
					system("cls");
					v_PrintMaqueta(1);
					
					printf("\n\n\t\tIngresa la palabra a cifrar: ");					// °
					fgets( palabra, 20, stdin);
					palabra_paso = palabra;
					v_TextoAMayuscula(palabra_paso);
					
					cifrar(palabra);													// °
					break;																// °
						
				case 2:																	// °	
					system("cls");
					v_PrintMaqueta(1);
					
					printf("\n\n\t\tIngresa el texto a descifrar: ");					// °
					fgets( palabra, 20, stdin);
					palabra_paso = palabra;
					v_TextoAMayuscula(palabra_paso);
					
					descifrar(palabra);													// °
					break;																// °
					
				case 3:																	// °
					system("cls");
					v_PrintMaqueta(2);
					printf("\n\n\t\t Saliendo");
					for( i = 0 ; i < 10 ; i++)
					{
						printf(".");
						Sleep(100);
					}
					
					printf("\n\n\n");
					return 0;															// °
					
				default: 	
					v_PrintMaqueta(3); 		
			}
			
			registro++;	
		}
		
		fflush(stdin);
		return 0;																		// °
	}
	
/*--	4- Función principal 	--*/

/*		5- Manejo de funciones		*///------------------------------------------------------
								 	 // 	Función cifrar:
									 //	 Resive los valores por referencia de la entrada del 
									 //  usuario, compara cada letra en mayuscula con abecedarioEnClaro
									 //  y los cambia por el mismo valor en posicion de  abecedarioCifrado.
									 
	void cifrar(char *textoEnClaro)
	{
		int contadorAbcedario, contadorPalabra, indice = 0, i; 
			
		printf("\n\t\tEl texto %s cifrado es: ", textoEnClaro);     
	    /* contador palabra se restringe en funcion del tamaño de textoEnClaro*/
		for (contadorPalabra=0 ; contadorPalabra<textoEnClaro[contadorPalabra] ; contadorPalabra++)
		{
			/* TAM_ABC restringe el número de comparaciones hasta 26 (Que es el número de conparaciones que hay en los abecedarios)*/
			for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++)
			{
				if (abecedarioEnClaro[contadorAbcedario] == textoEnClaro[contadorPalabra])
				{                 
					printf("%c", abecedarioCifrado[contadorAbcedario]);                 
					contadorAbcedario = 26; // Esta linea evita que siga la comparacion y hacce que se siga con la siguiente letra.            
				} 
			}
		}    
		
		printf("\n\n");    
		for( i = 0 ; i < 75 ; i++)printf("%c", 219);  
        printf("\n\n");
		system("pause"); 	
	}
	
/*--	5- Manejo de funciones 	  --*/
/*		6- Manejo de funciones		*///------------------------------------------------------
								 	 // Funcion Descifrar
								 	 
	/*
		La función realiza lo mismo que cifrar mensaje, lo unico que cambia es la posicion de 
		abecedarioCifrado y abecedarioEnClaro, dado que la conparacio y cambio de valores se realiza
		de manera contraria. 
		
		Las restricciones de tamaño y número funcionan igual.  
	*/
									  
	void descifrar(char *textoCifrado)
	{
		int contadorAbcedario, contadorPalabra, indice = 0, i; 
				
		printf("\n\t\tEl texto %s descifrado es: ", textoCifrado);         
		
		for (contadorPalabra=0 ; contadorPalabra<textoCifrado[contadorPalabra] ; contadorPalabra++)
		{
			for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++)
			{
				if (abecedarioCifrado[contadorAbcedario] == textoCifrado[contadorPalabra])
				{                
					printf("%c", abecedarioEnClaro[contadorAbcedario]);                 
					contadorAbcedario = 26;             
				} 
			}
		} 
		
		printf("\n\n");
		for( i = 0 ; i < 75 ; i++)printf("%c", 219);                    
    	printf("\n\n"); 
		system("pause");		
	}								  
									   
/*--	6- Manejo de funciones 	  --*/
/*		7- Manejo de funciones		*///------------------------------------------------------
								 	 // 
								 	 
	void v_PrintMaqueta(int parametro)
	{
		int i;
		
		switch(parametro)
		{
			case 0 : 
				system("color 71");
				break;
				
			case 1 :
				system("color 72");
				break;
				
			case 2 :
				system("color 70");
				break;
				
			case 3 : 
				system("cls");
				system("color 47");
				break;
		}
		
		for( i = 0 ; i < 75 ; i++)printf("%c", 219);
		printf("\n");
		for( i = 0 ; i < 75 ; i++)printf("%c", 219);
		
		if ( parametro == 3 )
		{
			printf("\n\n\n\t\t\tValor ingresado no v%clido.\n\n\n", 160);
			for( i = 0 ; i < 75 ; i++)printf("%c", 219);
			printf("\n");
			system("pause");
		}
		
	}
	
/*--	7- Manejo de funciones 	  --*/
/*		8- Manejo de funciones		*///------------------------------------------------------
								 	 // 
								 	 
	int i_ValorDeEntrada()
	{
		char entrada[10];
		int i, i_cambio[10], i_referencia = 0 ;
				
		printf("%c ", 219);
		fgets( entrada, 10, stdin);
		
		for ( i = 0 ; i < 10 ; i++)
		{
			i_cambio[i] = ((int)entrada[i]);
		}
		
		int gato = sizeof(entrada);
		
		if ( i_cambio[0] < 49 || i_cambio[0] > 51 ) i_referencia++;
		
		if ( i_referencia > 0 )return 4;
		
		return (i_cambio[0]-48);
	}
	
/*--	8- Manejo de funciones 	  --*/
/*		9- Manejo de funciones		*///------------------------------------------------------
								 	 // 
								 	 
	void v_TextoAMayuscula(char *texto)
	{
		int i_contador;
		int i_parametro;
		char c_value[20];
		
		for ( i_contador = 0 ; i_contador < 20 ; i_contador++ )
		{
			i_parametro = ((int)texto[i_contador]);
			
			if ( i_parametro > 96 && i_parametro < 123 )
			{
				c_value[i_contador] = toupper(texto[i_contador]);
			}
			else if ( i_parametro > 123 && i_parametro < 65 )
			{
				c_value[i_contador] = ' ';	
			}
			
		}
		
		for ( i_contador = 0 ; i_contador < 20 ; i_contador++)texto[i_contador] = c_value[i_contador];
			
	}
		
/*--	9- Manejo de funciones 	  --*/

/*
		||		Datos Generales del archivo:		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	1227 Estructura de Datos y Algoritmos 1
	Grupo: 09
	
	Práctica: 02 Aplicacionde de arreglos
	Autor: José Luis Bautista Rodríguez
	Fecha de inicio: 01/03/2018
	
	Lugar: AV. UNIVERSIDAD Nº 3000, UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO, C.U., CDMX, 04510
	------------------------------------------------------------------------------------------	

*/
