
#include "Juego.h"
#include <stdio.h>


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
int valorPuntos = 10;
int vidas = 3;
int nivel = 1;
int listaFantasmas[4] = {1,2,3,4};

struct Fantasma{
    int tipo;
    int velocidad;
    int x;
    int y;
};
struct Fruta{
    int tipo;
    int puntaje;
};
struct Jugador;


void iniciarJuego(struct Jugador jugador1){
    imprimirTablero(tablero);
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
    char move2 = obtenerMovimiento();
    iniciarJuegoaux(move2);
};

struct Fantasma crarFantasma(int tipo,int velocidad, int x, int y){
    if (tipo != 5 || tipo != 6 || tipo != 7 || tipo != 8 ){
        printf("Error en el tipo de Fantasma ");
    }
    struct Fantasma fant = {tipo, velocidad, x, y};
    //FALTA VERIFICAR QUE NO ESTE
    // FALTA PONERLOS y que se mueva
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
        if (tablero[ubicacion.i][ubicacion.j] == 5) {
            pacmanMuere(ubicacion.i, ubicacion.j);
            break;
            }
        if (tablero[ubicacion.i][ubicacion.j] == 3) jugador.puntaje += 10;
        if (tablero[ubicacion.i][ubicacion.j] == 9) jugador.puntaje += 1000;
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
void pacmanMuere(int i, int j){
    if (jugador.vidas == 0) {
        printf("(%d , %d) \n",i,j);
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
        char t= getchar();
        t = getchar();
        printf("Ingrese el puntaje \n");
        char p = getchar();
        p = getchar();

        printf("Se preciona tecla en crear : %c \n", t);
        //NO SRIVE EL SEGUNDO CHAR
        int tip = 0;
        if (t == '9') tip = 9;
        if (t == '1') tip = 10;
        if (t == '11') tip = 11;
        if (t == '12') tip = 12;
        crarFruta(tip,1000);
        printf("Fruta Creada\n");
        return;
    }
    if(f == '2') {
        printf("Creado fantasma\n");
        printf("Ingrese el tipo ");
        char t = getchar();
        printf("\n Ingrese velocidad ");
        char p = getchar();
        crarFantasma(t,p,11,14);
        printf("Fantasma Creada\n");
        return;
    }
}