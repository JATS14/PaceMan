
#include "Juego.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


int tablero[31][28]= {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,3,1},
        {1,3,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,3,1},
        {1,3,3,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,3,3,1},
        {1,1,1,1,1,1,3,1,1,1,1,1,0,1,1,0,1,1,1,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,1,1,1,0,1,1,0,1,1,1,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,0,0,0,0,0,0,0,0,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {0,0,0,0,0,0,3,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,0,0,0,0,0,0,0,0,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {1,1,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,1,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,1,1,1,1,3,1,1,1,1,1,3,1,1,3,1,1,1,1,1,3,1,1,1,1,3,1},
        {1,3,3,3,1,1,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,1,1,3,3,3,1},
        {1,1,1,3,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,3,1,1,1},
        {1,1,1,3,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,3,1,1,1},
        {1,3,3,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,1,1,3,3,3,3,3,3,1},
        {1,3,1,1,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,1,1,3,1},
        {1,3,1,1,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,1,1,3,1},
        {1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
struct Jugador jugador;
struct Fruta frutaEnMapa;
int listaFantasmas[4] = {5,6,7,8};
bool modoPastilla = false;
int tableroNuevoNivel[31][28];
//Fantasmas
struct Fantasma fantBlinky;
struct Fantasma fantPinky;
struct Fantasma fantInky;
struct Fantasma fantClynde;

//Variables necesarias para los threads
pthread_t pacman;
pthread_t ModoPastilla;
pthread_t blinky;
pthread_t pinky;
pthread_t inky;
pthread_t clynde;


//pthread_create(&thread_id, NULL, myThreadFun, NULL);
//pthread_join(thread_id, NULL);
//exit(0);

struct Fantasma{
    int tipo;
    int velocidad;
    int x;
    int y;
    int sobreEl;
};
struct Fruta{
    int tipo;
    int puntaje;
};
struct Jugador;


void iniciarJuego(struct Jugador jugador1){
    imprimirTablero(tablero);
    copiarTableros();
    jugador =  jugador1;
    char move = obtenerMovimiento();
    iniciarJuegoaux(move);
    return;
};

void iniciarJuegoaux(char move){
    printf("Se preciona tecla : %c \n", move);
    if(move == 'p') {
        printf("El juego se ah detenido");
        return;
    }
    if(move == 'i') {
        imprimirTablero(tablero);
    }
    if(move == 'f') {
        agregarFrutaFantasma();
    }
    if(move == 'e') {
        printf("---------------------------------------- \n");
        printf("El Puntaje actual es: %d \n" , jugador.puntaje);
        printf("las vidas actuales son: %d \n" , jugador.vidas);
        printf("El nivel actual es: %d \n" , jugador.nivel);
        printf("---------------------------------------- \n");
    }
    moverPacman(move);
    moverPacman(move);
    //PASA DE NIVEL?
    if(pasaDeNivel() == true){
        //HACER COSAS QUE HACEN PASAR DE NIVEL
        jugador.nivel++;
        resetearTablero();
        listaFantasmas[0] = 5; listaFantasmas[1] = 6; listaFantasmas[2] = 7; listaFantasmas[3] = 8;
        //Parar theads de los fantasmas

        printf("Pasaste de Nivel\n");
        printf("El nivel actual es: %d \n" , jugador.nivel);
    }
    char move2 = obtenerMovimiento();
    iniciarJuegoaux(move2);
};

void crarFantasma(int tipo,int velocidad, int x, int y){
    if (tipo == 5 || tipo == 6 || tipo == 7 || tipo == 8) {
        int e = entidadEn(x, y);
        printf("Se Encontro: %d \n", e);
        bool noEsta = buscarTipoFantasma(tipo);
        if (e != 1 && noEsta == true) {
            struct Fantasma fant = {tipo, velocidad, x, y,0};
            tablero[x][y] = fant.tipo;
            if(fant.tipo == 5){
                fantBlinky = fant;
            }
            if(fant.tipo == 5){

            }
            if(fant.tipo == 5){

            }
            if(fant.tipo == 5){

            }
            printf("Fantasma Creada\n");
        }
        else{
            printf("Error en la posicicon del Fantasma ");
        }
    } else {
        printf("Error en el tipo de Fantasma ");
    }
};
void crarFruta(int tipo,int puntaje){
    if (tipo == 9 || tipo == 10 || tipo == 11 || tipo == 12 || tipo == 13){
        struct Fruta frut = {tipo,puntaje};
        frutaEnMapa = frut;
        tablero[17][14] = tipo;
        return;
    }
    printf("Error en el tipo de fruta ");
};

void imprimirTablero(int tab[31][28]){
    for (int i = 0; i < 31;i++){
        for (int j = 0; j < 28;j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}
char obtenerMovimiento(){
    char c = getchar();
    if (c == 'w') return c;
    if (c == 'a') return c;
    if (c == 's') return c;
    if (c == 'd') return c;
    if (c == 'p') return c;
    if (c == 'i') return c;
    if (c == 'e') return c;
    if (c == 'f') return c;
    else {
        obtenerMovimiento();
    }
};
void moverPacman(char move) {
    if(move == 'i') {
        return;
    }
    if(move == 'e') {
        return;
    }
    if(move == 'f') {
        return;
    }
    struct Pos ubicacion = buscarEntidad(2);
    int ix = 0;
    int jx = 0;
    int ii = ubicacion.i;
    int ji = ubicacion.j;
    if (move == 'w') ix = -1;
    if (move == 's') ix = 1;
    if (move == 'a') jx = -1;
    if (move == 'd') jx = 1;
    ubicacion.i += ix;
    ubicacion.j += jx;
    while (tablero[ubicacion.i][ubicacion.j] != 1) {
        int entTable = tablero[ubicacion.i][ubicacion.j];
        if (entTable== 5 || entTable== 6 || entTable== 7 || entTable== 8) {
            if (modoPastilla == false) {
                pacmanMuere(ubicacion.i, ubicacion.j);
                break;
            }else{
                //PONER QUE SE COMIO A UN FANTASMA
                break;
            }
            }
        if (entTable == 3) jugador.puntaje += 10;
        if (entTable == 9 || entTable == 10 || entTable == 11 || entTable == 12 || entTable == 13) {
            jugador.puntaje += frutaEnMapa.puntaje;
            frutaEnMapa.puntaje = 0;
            frutaEnMapa.tipo = 0;
            //enviar a java la matriz
        }
        tablero[ii][ji] = 0;
        tablero[ubicacion.i][ubicacion.j] = 2;
        ii = ubicacion.i;
        ji = ubicacion.j;
        ubicacion.i += ix;
        ubicacion.j += jx;
    }
};
//printf("pocisicon de pacman en i = %d \n",ubicacion.i);
//printf("pocisicon de pacman en j = %d \n",ubicacion.j);
struct Pos buscarEntidad(int tipo){
    for (int i = 0; i < 31;i++){
        for (int j = 0; j < 28;j++) {
            if(tablero[i][j] == tipo){
                printf("(%d , %d) \n",i,j);
                struct Pos pos1 = {i,j};
                return pos1;
            }
        }
    }
};
int entidadEn(int i, int j){
    return tablero[i][j];
};
bool buscarTipoFantasma(int tipo){
    for (int i = 0; i < 4; i++){
        if (listaFantasmas[i] == tipo){
            listaFantasmas[i] = 0;
            return true;
        }
    }
    return false;
}
void pacmanMuere(int i, int j){
    if (jugador.vidas == 0) {
        printf("Perdiste :cc \n");
        //Cosas para hcaer cuando pierde
        return;
    }
    else{
        jugador.vidas -= 1;
        struct Pos ubicacion = buscarEntidad(2);
        tablero[ubicacion.i][ubicacion.j] = 0;
        tablero[23][14] = 2;
    }

}
void agregarFrutaFantasma(){
    printf("------------------------------------------------------\n");
    printf("Menu para agregar Fruta / fantasma \n");
    printf("Ingrese 1 para agregar Fruta o 2 para agregar Fantasma \n");
    char f = getchar();
    f = getchar();
    if(f == '1') {
        printf("Creado Fruta\n");
        printf("Ingrese el tipo \n");
        int t;
        scanf("%d", &t);

        printf("Ingrese el puntaje \n");
        int p;
        scanf("%d", &p);

        crarFruta(t,p);
        printf("Fruta Creada\n");
        return;
    }
    if(f == '2') {
        printf("Creado fantasma\n");
        printf("Ingrese el tipo (5 = Blinky, 6 = Pinky, 7 = inky, 8 = Clynde)");
        int tipo;
        scanf("%d", &tipo);
        printf("\n Ingrese velocidad ");
        int vel;
        scanf("%d", &vel);
        printf("\n Ingrese La fila");
        int fil;
        scanf("%d", &fil);
        printf("\n Ingrese La Columna");
        int col;
        scanf("%d", &col);
        crarFantasma(tipo,vel,fil,col);
        return;
    }
}

void copiarTableros(){
    for (int i = 0; i < 31;i++){
        for (int j = 0; j < 28;j++){
            tableroNuevoNivel[i][j] = tablero[i][j];
        }
    }

}
void resetearTablero(){
    for (int i = 0; i < 31;i++){
        for (int j = 0; j < 28;j++){
            tablero[i][j] = tableroNuevoNivel[i][j];
        }
    }

}
bool pasaDeNivel(){
    if (contarPuntos() == 0) return true;
    return false;
}
int contarPuntos(){
    int cant = 0;
    for (int i = 0; i < 31;i++){
        for (int j = 0; j < 28;j++){
            if(tablero[i][j] == 3 || tablero[i][j] == 4 ) cant++;
        }
    }
    return cant;
}
void movimientoBlinky(){
    int move = rand() % 4;
    struct Pos ubicacionB = buscarEntidad(5);
    int ix = 0;
    int jx = 0;
    int ii = ubicacionB.i;
    int ji = ubicacionB.j;
    if (move == 0) ix = -1;
    if (move == 1) ix = 1;
    if (move == 2) jx = -1;
    if (move == 3) jx = 1;
    ubicacionB.i += ix;
    ubicacionB.j += jx;
    while (tablero[ubicacionB.i][ubicacionB.j] != 1) {
        tablero[ii][ji] = fantBlinky.sobreEl;
        fantBlinky.sobreEl = tablero[ubicacionB.i][ubicacionB.j];
        tablero[ubicacionB.i][ubicacionB.j] = 5;
        ii = ubicacionB.i;
        ji = ubicacionB.j;
        ubicacionB.i += ix;
        ubicacionB.j += jx;
    }
}