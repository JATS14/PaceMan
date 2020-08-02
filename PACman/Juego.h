
#ifndef PACMAN_JUEGO_H
#define PACMAN_JUEGO_H



int valorPuntos;
int vidas;
int nivel;
int listaFantasmas[4];


struct Fantasma;
struct Fruta;
struct Jugador{
    int vidas;
    int nivel;
    int puntaje;
};
struct Pos{
    int i;
    int j;
};

/*
 * Funciones necesarias para correr el juego
 */

struct Fantasma crarFantasma(int tipo,int velocidad, int x, int y);
struct Fruta crarFruta(int tipo,int puntaje);
void iniciarJuego(struct Jugador jugador1);
void iniciarJuegoaux(char move);
void imprimirTablero(int tab[31][28]);
char obtenerMovimiento();
void moverPacman(char move);
struct Pos buscarEntidad(int tipo);
void pacmanMuere(int i, int j);


#endif //PACMAN_JUEGO_H
