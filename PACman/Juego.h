
#ifndef PACMAN_JUEGO_H
#define PACMAN_JUEGO_H


#include <stdbool.h>


int listaFantasmas[4];
bool modoPastilla;
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

void crarFantasma(int tipo,int velocidad, int x, int y);
void crarFruta(int tipo,int puntaje);
void iniciarJuego(struct Jugador jugador1);
void iniciarJuegoaux(char move);
void imprimirTablero(int tab[31][28]);
char obtenerMovimiento();
void moverPacman(char move);
struct Pos buscarEntidad(int tipo);
void pacmanMuere(int i, int j);
void agregarFrutaFantasma();
int entidadEn(int i, int j);
bool buscarTipoFantasma(int tipo);
void copiarTableros();
void resetearTablero();
bool pasaDeNivel();
int contarPuntos();


#endif //PACMAN_JUEGO_H
