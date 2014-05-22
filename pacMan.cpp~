#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <cstdlib>//para utilizar la funcion rand

//matriz pantalla se deja 1 de mas
#define MAXFILAS 20//eje y
#define MAXCOLS 31//eje x

BITMAP *buffer;//variables imagen
BITMAP *roca;
BITMAP *pacbmp;//imagen general del bmp de pacman
BITMAP *pacman;//imagen de un unico pacman
BITMAP *comida;//imagen de comida
BITMAP *enemigobmp;//imagen de enemigo
BITMAP *enemigo;//imagen de enemigo en el buffer
BITMAP *muertebmp;//imagen de pacMan al morir

//direccion de pacman
//RECORDAR SIEMPRE QUE LA ESCALA GLOBAL ESTA EN RELACION A LA DIMENSION DE LOS BMP


//ZONA DE VARIABLES GLOBALES
int dir = 4;
int posx = 30*14, posy = 30*16;//posicion de pacman
int fdir = 0; //direccion de los fantasmas
int _x = 30*14 , _y = 30*15; //posicion de los fantasmas
int anteriorposx, anteriorposy; //variables para guardar las posiciones relativas de los fantasmas.

char mapa[MAXFILAS][MAXCOLS] = { //fread,fopen, fwrite, fclose.

    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "Xoooo|ooooo XXXXX ooooo|ooooX",	
    "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
    "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
    "X       |           |       X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X    |XX     XXX     XX|    X",
    "X XXX XXXXXX XXX XXXXXX XXX X",
    "X XXX XX o         o XX XXX X",
    "     |XX XXXXXXXXXXX XX|     ",
    "X XXX XX o  |ooo|  o XX XXX X",
    "X XXX XXXXXX XXX XXXXXX XXX X",
    "X    |XX     XXX     XX     X",
    "X XXX XX XXXXXXXXXXX XX XXX X",
    "X XXX|ooo|         |ooo|XXX X",
    "X XXXoXXX XXXXXXXXX XXX XXX X",
    "X XXXoXXX           XXX XXX X",
    "X  oo|oo  XXXXXXXXX  oo|oo  X",	
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

void dibujar_mapa(){
    int fila, col;

    for(fila=0; fila<MAXFILAS; fila++){
	for(col=0; col<MAXCOLS; col++){
	    if(mapa[fila][col] == 'X'){
		draw_sprite(buffer, roca, col*30 , fila*30);
	    }else
		if(mapa[fila][col] == 'o'){
		    draw_sprite(buffer, comida, col*30 , fila*30);
		    if(posy/30 == fila && posx/30 == col)
			mapa[fila][col] = ' ';

		}

	}
    }
}
//imprimir en pantalla
void pantalla(){
    blit(buffer, screen, 0,0,0,0,880,600);
}

void dibujar_personaje(){
    blit(pacbmp, pacman, dir*33, 0, 0, 0, 33, 33);
    //cogemos todo el dibujo y elegimos lo que nos sirve
    //2 primeras coor para elegir la imagen
    //2 segundas coor para saber donde pegarlas
    //2 ultimas dimensiones del dibujo
    draw_sprite(buffer, pacman, posx, posy);

}

bool game_over(){

    int fila, col;

    for(fila=0; fila<MAXFILAS; fila++){
	for(col=0; col<MAXCOLS; col++){
	    if(mapa[fila][col] == 'o') 
		return true;
	}
    }
    return false;
}

void dibujar_fantasma(){
    blit(enemigobmp, enemigo, 0, 0, 0, 0, 30, 30);
    //cogemos todo el dibujo y elegimos lo que nos sirve
    //2 primeras coor para elegir la imagen
    //2 segundas coor para saber donde pegarlas
    //2 ultimas dimensiones del dibujo
    draw_sprite(buffer, enemigo, _x, _y);
}

void muerte_pacman(){
    if(posy == _y && posx == _x || _y == anteriorposy && _x == anteriorposx){ //condicion para saber cuando se muere

	for(int j=0; j<=5 ; j++){ //un for que recorre las imagenes bmp de la muerte de pacman
	    clear(pacman);//limpiar los buffer para volver a cargar las nuevas imagenes
	    clear(buffer);
	    dibujar_mapa();

	    blit(muertebmp, pacman, j*33,0,0,0,33,33); //dibujar la muerte
	    draw_sprite(buffer, pacman, posx, posy);

	    pantalla();//imprimir de nuevo todo en pantalla

	    for (int i=0; i<5; i++){ 
		rest(900000000);//funcion de velocidad del juego
	    }//bucle for para ampliar el tiempo en el juego

	}
	//colocar de nuevo a pacman en el inicio
	posx = 30*14;
	posy = 30*16;
	dir = 4;	
    }
}

void fantasma(){
    dibujar_fantasma();//primero se dibuja el fantasma de la funcion anterior
    muerte_pacman(); //implementar la funcion de la muerte
    if(mapa[_y/30][_x/30] == '|'){ //para cambiar de direccion y no se atranque
	fdir = rand()%4;
    }
    //movimieno automatico del fantasma igual que hice antes el movimiento del personaje	
    if(fdir == 0){
	if(mapa[_y/30][(_x-30)/30] != 'X') _x-=30;
	else fdir = rand()%3;
    }
    if(fdir == 1){
	if(mapa[_y/30][(_x+30)/30] != 'X') _x+=30;
	else fdir = rand()%3;
    }
    if(fdir == 2){
	if(mapa[(_y-30)/30][(_x)/30] != 'X') _y-=30;
	else fdir = rand()%3;
    }
    if(fdir == 3){
	if(mapa[(_y+30)/30][(_x)/30] != 'X') _y+=30;
	else fdir = rand()%3;
    }
    //rutina de atajo
    if(_x <= -30) _x = 870;
    else if(_x >= 870) _x = -30;

}

int main(){

    allegro_init();
    install_keyboard();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 880,600,0,0);

    buffer = create_bitmap(880, 600);//segun el tablero que tenga
    roca = load_bitmap("roca.bmp", NULL);//cargar la imagen roca
    pacbmp = load_bitmap("pacman.bmp", NULL);
    pacman = create_bitmap(33,33);
    comida = load_bitmap("Comida.bmp", NULL);
    enemigo = create_bitmap(30,30);
    enemigobmp = load_bitmap("enemigo.bmp", NULL);	
    muertebmp = load_bitmap("muerte.bmp", NULL);

    while(!key[KEY_ESC] && game_over()){
	//guardar las posiciones relativas del movimiento, estan situadas aqui para que se puedan guardar correctamente
	anteriorposx = posx;
	anteriorposy = posy;

	//rutina para mover a pacman
	if(key[KEY_RIGHT]) dir = 1;
	else if(key[KEY_LEFT]) dir = 0;
	else if(key[KEY_UP]) dir =2;
	else if(key[KEY_DOWN]) dir =3;

	if(dir == 0){ 
	    if(mapa[posy/30][(posx-30)/30] != 'X')
		posx -= 30;
	    else dir = 4;	
	}

	if(dir == 1){ 
	    if(mapa[posy/30][(posx+30)/30] != 'X')
		posx += 30;
	    else dir = 4;	
	}
	if(dir == 2){ 
	    if(mapa[(posy-30)/30][posx/30] != 'X')
		posy -= 30;
	    else dir = 4;	
	}
	if(dir == 3){ 
	    if(mapa[(posy+30)/30][posx/30] != 'X')
		posy += 30;
	    else dir = 4;	
	}

	//rutina para atajo en mapa		
	if(posx <= -30) posx = 870;
	else if(posx >= 870) posx = -30;

	clear(buffer);
	dibujar_mapa();
	dibujar_personaje();
	fantasma();
	pantalla();
	for (int i=0; i<5; i++){ 
	    rest(900000000);//funcion de velocidad del juego
	}//bucle for para ampliar el tiempo en el juego

	clear(pacman);
	blit(pacbmp, pacman, 4*33,0,0,0,33,33);
	draw_sprite(buffer, pacman, posx, posy);
	pantalla();
	//rest(900000000);//velocidad de tu personaje
    }
}
END_OF_MAIN();

