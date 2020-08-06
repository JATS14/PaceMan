//
// Created by adrian on 8/5/20.
//

#include "ServidorSockets.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>

char mensaje[1024];
bool coneccion = true;

void server(){
    int conexion_servidor, conexion_cliente, puerto;
    socklen_t longc;
    struct sockaddr_in servidor, cliente;
    char buffer[100];



        puerto = 25558;
        conexion_servidor = socket(AF_INET, SOCK_STREAM, 0);
        bzero((char *)&servidor, sizeof(servidor));
        servidor.sin_family = AF_INET;
        servidor.sin_port = htons(puerto);
        servidor.sin_addr.s_addr = INADDR_ANY;

        if (bind(conexion_servidor, (struct sockaddr *) &servidor, sizeof(servidor)) < 0) {
            printf("Error al asociar el puerto a la conexion\n");
            close(conexion_servidor);
            return;
        }
        while (coneccion) {
            sprintf(mensaje, "");
           listen(conexion_servidor, 3);
            printf("A la escucha en el puerto %d\n", ntohs(servidor.sin_port));
            longc = sizeof(cliente); //Asignamos el tamaño de la estructura a esta variable

            conexion_cliente = accept(conexion_servidor, (struct sockaddr *) &cliente, &longc);
            if (conexion_cliente < 0) {
            while (conexion_cliente < 0) {
                conexion_cliente = accept(conexion_servidor, (struct sockaddr *) &cliente, &longc);
            }
        }
        printf("Conectando con el cliente\n");


        if (recv(conexion_cliente, buffer, 100, 0) < 0) {
            //Si recv() recibe 0 el cliente ha cerrado la conexion. Si es menor que 0 ha habido algún error.
            printf("Error al recibir los datos\n");
            close(conexion_servidor);
            return;
        } else {
            printf("%s\n", buffer);
            bzero((char *) &buffer, sizeof(buffer));
            agregarAJugeo();
            send(conexion_cliente, mensaje, 1024, 0);

        }
        close(conexion_cliente);
    }
    close(conexion_servidor);
    return;

}
void agregarAJugeo(){
    printf("------------------------------------------------------\n");
    printf("Menu para agregar Fruta / fantasma \n");
    printf("Ingrese 1 para agregar Fruta, 2 para agregar Fantasma, 3 para agregar Pastilla \n");
    char f;
    f = getchar();
    if(f == '1') {
        printf("Creado Fruta\n");
        printf("Ingrese el tipo \n");
        int t;
        scanf("%d", &t);

        printf("Ingrese el puntaje \n");
        int p;
        scanf("%d", &p);

        //Eviar a socket
        sprintf(mensaje, "fruta(%d,%d)", t,p);
        printf("Fruta Creada\n");
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
        //enviar a socket
        sprintf(mensaje, "fantasma(%d,%d,%d,%d)", tipo,vel,fil,col);
        printf("Fanstasma Creado\n");
    }
    if(f == '3') {
        printf("Creado Pastilla\n");
        printf("\n Ingrese La fila");
        int fil;
        scanf("%d", &fil);
        printf("\n Ingrese La Columna");
        int col;
        scanf("%d", &col);
        //Enviar a socket
        sprintf(mensaje, "fantasma(%d,%d)",fil,col);
        printf("Pastilla Creada\n");
    }
    if(f == 's') {
        printf("La coneccion con el cliente se terminara\n");
        coneccion= false;
    }
    printf("EL mensaje que se enviara al Cliente es: \"%s\". \n",mensaje);
    return;
}