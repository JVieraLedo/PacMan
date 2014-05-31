#include <stdio.h>
#include <stdlib.h>

void coordenadas(int o1);                            
// Captura de Nombres, Coordenadas e Impresion de Tableros
void grilla();                                       
// Armo y Reseteo los Tableros
void pintar(int dat1, int dat2);                     
// Pinto Tableros y Submarinos
int ataque(int tur);                                 
// Impresion de Nombres, Tableros y Ataques por Jugador

int player=0,
    proyectil[2][2]={{11,11},{3,3}},
    intent1=0,
    intent2=0;
char jugador1[40],
     jugador2[40];
char tablero1s[21][21],
     tablero2s[21][21];

int main(){
	int opcion,opsubm,decision,turno=1;  
	grilla();                                           
	// Reseteo y creo los tableros
	do{
		system("cls");
		printf("            MENU PRINCIPAL\n\n");
		printf(" 1.- Menu de configuracion de submarinos\n");
		printf(" 2.- Jugar\n");
		printf("99.- Salir\n\n");    
		printf("Seleccione una opcion: ");                                                  
		scanf("%i",&opcion);// Capturo opcion de Juego
		switch (opcion){
			case 1: if (player==3){//Ambos jugadores ya ingresaron Coor            
				printf("\nError, Ya ambos jugadores ingresaron coordenadas\n\n");
				system("pause");
				}else{
				do{  
				system("cls");
				printf("            MENU DE CONFIGURACION DE SUBMARINOS\n\n");
				printf(" 1.- Submarinos Jugador 1\n");
				printf(" 2.- Submarinos Jugador 2\n");
				printf("99.- Volver al menu principal\n\n");    
				printf("Seleccione una opcion: ");
				scanf("%i",&opsubm);// Capturo opcion de Submen
		switch (opsubm){
			case 1: coordenadas(1);                
				// Pocionamiento de Submarinos
			break;
			case 2: coordenadas(2);                
				// Pocionamiento de Submarinos
			break; 
			case 99: 
			break;       
		default: printf("\nError, Solo puede acceder a una de las tres opciones del menu\n\n");
			system("pause");
		break;                      
		}      
		}while(opsubm!=99);
	}    
		break;
			case 2: if (player<3){
				    printf("\nError, Ambos jugadores deben ingresar la pocision de sus submarinos\n\n");
				    system("pause");
				}else{
				    do{               
					decision=ataque(turno);// Ataque por turnos 
					if (decision==99)
					    opcion=99;
					else{// Pregunto si no queda ningun tipo de proyectil disponible
					    if (proyectil[0][0]==0&&proyectil[0][1]==0&&
						    proyectil[1][0]==0&&proyectil[1][1]==0){                                                                        decision=opcion=99;                                                                                 printf("\n\nAmbos jugadores ya no cuentan con proyectiles disponibles\n\n");
						printf("%s derribo %i submarinos\n",jugador1,intent1); 
						printf("%s derribo %i submarinos\n\n",jugador2,intent2);
if (intent1>intent2)
printf("%s ha ganado!!!!\n\n",jugador1);
else if (intent1<intent2)
printf("%s ha ganado!!!!\n\n",jugador2);
else
printf("Hay empate!!!!\n\n");  
system("pause");                                                                               
}else{   

if (turno==1)
turno=2;
else
turno=1;    
}
}                        
}while(decision!=99);                
}
break;
case 99: break; // Fin de Juego 
default: printf("\nError, Solo puede acceder a una de las tres opciones del menu\n\n");
system("pause");
break;// Error de Acceso
}    
}while(opcion!=99);             
return 0;
}

void coordenadas(int o1){
	int fsub,csub,a=1,b,cs,d,fs,contador,tecla=2;    
	if (player==o1) // No puede ingresar coordenadas un jugador que ya lo haya hecho
		printf("\nError, El jugador %i ya ingreso las coordenadas de sus submarinos\n\n",o1);   
	else if (player==3)
	    printf("\nError, Ambos jugadores ya ingresaron sus coordenadas\n\n");
	else if (player==0||(player!=o1))
	{
	    printf("\nIngrese su nombre: ");
	    getchar();  
	    if (o1==1)    
		gets(jugador1);// Capturo nombre Jugador 1      
	    else
		gets(jugador2);// Capturo nombre Jugador 2
	    if (player==0)
		player=o1;
	    else
		player=3;// Si player es igual 3 quiere decir que ambos jugadores ya ingresaron coordenadas
	    printf("\nIndique las posiciones de los 15 submarinos X,Y\n\n");
	    while(a<=5){
		printf("Submarino #%i: ",a);
		scanf("%i,%i",&fsub,&csub);
		// Capturo la pocision de cada submarino
		fs=2;  
		for (b=1;b<fsub;b++)   
		    fs++;
		cs=2;
		for (b=1;b<csub;b++)   
		    cs++;
		if ((fsub<1||fsub>5)&&(csub<1||csub>5))
		    printf("\nDato incorrecto, X e Y estan fuera de los limites \n\n");
		else if (fsub<1||fsub>5)
		    printf("\nDato incorrecto, X esta fuera de los limites \n\n");
		else if (csub<1||csub>5)
		    printf("\nDato incorrecto, Y esta fuera de los limites \n\n");
		else if ((tablero1s[(fsub+fs)*2][(csub+cs)*2]=='#'&&o1==1)||
			(tablero2s[(fsub+fs)*2][(csub+cs)*2]=='#'&&o1==2)) 
		    // Pregunto si en la pocision escogida ya existia un submarino                                                
		    printf("\nDato incorrecto: Esa celda esta ya ocupada por otro submarino \n\n");
		else{
		    contador=0;                                     
		    for (b=((fsub+fs)*2)-4;b<=((fsub+fs)*2)+4;b+=4){
			for (d=((csub+cs)*2)-4;d<=((csub+cs)*2)+4;d+=4){
			    if (o1==1){  
				if (tablero1s[b][d]=='#')
				// Cuento la cantidad de submarinos alrededor de tablero 1
				    contador++;
			    }else{
				if (tablero2s[b][d]=='#')                     
    // Cuento la cantidad de submarinos alrededor de tablero 2
				    contador++;  
			    }
			}
		    }
		    if (contador>0)                                  
			// Pregunto si hay submarinos alrededor
			printf("\nDato incorrecto: Alrededor de un submarino no puede haber otro  \n\n");
			else{
			a++;  
			if (o1==1)                                      
			    // Guardo el submarino en tablero 1
			    tablero1s[(fsub+fs)*2][(csub+cs)*2]='#';                  
			else
			    tablero2s[(fsub+fs)*2][(csub+cs)*2]='#';       
			// Guardo el submarino en tablero 2  
		    }
		}                   
	    }
	    while (tecla!=0&&tecla!=1){
		printf("\nDesea ver la disposicion de sus submarinos? (si=1/no=0): ");
		scanf("%i",&tecla);
		if (tecla==1)
		    pintar(1,o1);
		else if (tecla!=0&&tecla!=1)
		    printf("\nError, Solo puede ingresar 1 o 0\n"); 
	    }  
	}
	system("pause");    
}

void grilla(){

    int a,b,fil=0,col=0;
    for (a=0;a<=33;a++){
	for (b=0;b<=33;b++){                                                  
	    // Reseteo los Tableros
	    tablero1s[a][b]=tablero2s[a][b]=' ';
	}
    }
    for (a=1;a<=8;a++){
	fil+=4;  
	for (b=4;b<=32;b++)                                
	    // Armo las Columnas
	    tablero1s[fil][b]=tablero2s[fil][b]='-';
    }
    for (a=1;a<=8;a++){
	col+=4;  
	for (b=5;b<32;b++)                                 
	    // Armo las Filas
	    tablero1s[b][col]=tablero2s[b][col]='|';
    }
}

void pintar(int dat1, int dat2){

    int a,b,fil=0,col=0;   
    printf("\n\n                       SUBMARINOS DE MASACRE\n\n"); 
    printf("     ");
    for (a=1;a<=5;a++){                                 
	// Pinto los Numeros de las Columnas
	if (a<5)   
	    printf("%i   ",a);
	else
	    printf("%i  ",a); 
    }  
    printf("\n");  
    fil=6; 
    col=2;
    for (a=4;a<=32;a++){
	if (fil==a){
	    printf("%2i ",(a/2)-col);                         
	    // Pinto los Numeros de las Filas
	    fil+=4;         
	    col++;
	}      
	else      
	    printf("   ");   
	for (b=4;b<=32;b++){
	    if (dat1==1&&dat2==1)   
		printf("%c",tablero1s[a][b]);                    
	    // Pinto Todo Pocision Sub 1
	    else if (dat1==1&&dat2==2)   
		printf("%c",tablero2s[a][b]);                    
	    // Pinto Todo Pocision Sub 2
	    else if (dat1==2&&dat2==1){                        
		// Pinto Todo Ataque Sub 1
		if (tablero2s[a][b]=='#')
		    printf(" ");
		else if (tablero2s[a][b]=='1')
		    printf("#");    
		else
		    printf("%c",tablero2s[a][b]);  
	    }else{                                              
		// Pinto Todo Ataque Sub 2   
		if (tablero1s[a][b]=='#')
		    printf(" ");
		else if (tablero1s[a][b]=='1')
		    printf("#");    
		else
		    printf("%c",tablero1s[a][b]);      
	    }                 
	}
	printf("\n");  
    }
    printf("\n");
}

int ataque(int tur){

    int a,
	b,
	pro=0,
	condicion=0,
	contador=0,
	fsub,
	csub,
	fs,
	cs;  

    system("cls");
    if (tur==1)
	printf("Jugador 1: %s",jugador1);                  
    // Imprimo Nombre Jugador 1
    else
	printf("Jugador 2: %s",jugador2);                  
    // Imprimo Nombre Jugador 2      
    pintar(2,tur);                                      
    // Imprimo Cuadro de Ataque  
    printf("Convenciones: \n\n");
    printf("# - Submarino derribado\n");
    printf("0 - Proyectil desperdiciado\n\n");
    printf("Proyectiles restantes:\n\n");               
    // Imprimo Proyectiles Restantes
    printf("1) Pulso Puntual: %i\n",proyectil[0][tur-1]);
    printf("2) Pulso Estrella: %i\n",proyectil[1][tur-1]);
    printf("99) Te rindes?\n\n");
    while(pro!=1&&pro!=2&&pro!=99){
	printf("Seleccione una opcion: ");
	scanf("%i",&pro);                                  
	// Capturo Tipo de Proyectil
	if (pro!=1&&pro!=2&&pro!=99)
	    printf("\nError, Solo puede acceder a una de las tres opciones del menu\n\n");
	else if (pro==99){                                  
	    // Rendicion
	    condicion=99;   
	    if (tur==1)
		printf("\n%s se ha rendido. %s ha ganado!!!!\n\n",jugador1,jugador2);
	    else
		printf("\n%s se ha rendido. %s ha ganado!!!!\n\n",jugador2,jugador1);   
	}
	else if(proyectil[0][tur-1]==0&&pro==1){            
	    // No hay proyectiles puntual
	    printf("\nError, Ya no cuenta con Proyectiles Pulso Puntual\n\n");
	    pro=0;                             
	}
	else if(proyectil[1][tur-1]==0&&pro==2)            
	    // No hay proyectiles estrella
	{
	    printf("\nError, Ya no cuenta con Proyectiles Pulso Estrella\n\n");
	    pro=0;                             
	}else{
	    a=0;  
	    while (a!=1){  
		printf("\nIngrese las coordenadas del proyectil X,Y: ");
		scanf("%i,%i",&fsub,&csub);                      
		// Capturo la Coordenada 
		fs=2;  
		for (b=1;b<fsub;b++)   
		    fs++;
		cs=2;
		for (b=1;b<csub;b++)   
		    cs++;
		if ((fsub<1||fsub>5)&&(csub<1||csub>5))
		    printf("\nDato incorrecto, X e Y estan fuera de los limites\n");
		else if (fsub<1||fsub>15)
		    printf("\nDato incorrecto, X esta fuera de los limites\n");
		else if (csub<1||csub>15)
		    printf("\nDato incorrecto, Y esta fuera de los limites\n");
		else if ((tablero2s[(fsub+fs)*2][(csub+cs)*2]=='1'&&tur==1)||
			(tablero1s[(fsub+fs)*2][(csub+cs)*2]=='1'&&tur==2))                                                  // Pregunto si en la pocision escogida ya existia un submarino
		    printf("\nDato incorrecto: En esa celda ya se derribo un submarino\n");
		else if ((tablero2s[(fsub+fs)*2][(csub+cs)*2]=='0'&&tur==1)||
			(tablero1s[(fsub+fs)*2][(csub+cs)*2]=='0'&&tur==2))                                                  // Pregunto si en la pocision escogida ya existia un submarino
		    printf("\nDato incorrecto: En esa celda ya se uso un proyectil\n");
		else
		    a++;
	    }
	    if (pro==1){                                    
		// Impacto Pulso Puntual	    
		proyectil[0][tur-1]--;                        
		// Disminuye Cantidad de Proyectiles Puntual
		if (tablero2s[(fsub+fs)*2][(csub+cs)*2]=='#'&&tur==1){
		    printf("\nHa dado en el blanco!!!!\n\n");
		    tablero2s[(fsub+fs)*2][(csub+cs)*2]='1';
		    intent1++;
		}
		else if (tablero1s[(fsub+fs)*2][(csub+cs)*2]=='#'&&tur==2){     
		    printf("\nHa dado en el blanco!!!!\n\n");
		    tablero1s[(fsub+fs)*2][(csub+cs)*2]='1';
		    intent2++;
		}else{
		    printf("\nNo le dio a nada!!!!\n\n");  
		    if (tablero2s[(fsub+fs)*2][(csub+cs)*2]!='#'&&tur==1)
			tablero2s[(fsub+fs)*2][(csub+cs)*2]='0';    
		    else
			tablero1s[(fsub+fs)*2][(csub+cs)*2]='0';              
		}  
	    }else{                                           
		// Impacto Pulso Estrella	    
		proyectil[1][tur-1]--;                        
		// Disminuye Cantidad de Proyectiles Estrella 
		for (a=((fsub+fs)*2)-4;a<=((fsub+fs)*2)+4;a+=4){
		    for (b=((csub+cs)*2)-4;b<=((csub+cs)*2)+4;b+=4){
			if (tablero2s[a][b]=='#'&&tur==1){
			    tablero2s[a][b]='1';                       
			    // Derribo submarino
			    contador++;
			    intent1++;
			}
			else if (tablero2s[a][b]==' '&&tur==1)
			    tablero2s[a][b]='0';                       
			// No le dio a nada
			else if (tablero1s[a][b]=='#'&&tur==2){
			    tablero1s[a][b]='1';                       
			    // Derribo submarino
			    contador++;
			    intent2++;
			}else if (tablero1s[a][b]==' '&&tur==2)
			    tablero1s[a][b]='0';                       
			// No le dio a nada
		    }   
		}
		if (contador>0)
		    printf("\nHa dado en el blanco!!!!\n\n");
		else
		    printf("\nNo le dio a nada!!!!\n\n");        
	    }
	    if(intent1==5||intent2==5)                     
		// Uno de los jugadores derribo los 15 submarinos del otro
	    {
		condicion=99;  
		if (intent1==5)                       
		    printf("%s ha ganado!!!!\n\n",jugador1);
		else
		    printf("%s ha ganado!!!!\n\n",jugador2);
	    }              
	}
    }            
    system("pause");
    return condicion;  
}
