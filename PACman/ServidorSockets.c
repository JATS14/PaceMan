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
#include <arpa/inet.h>

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
            if(coneccion) {
                send(conexion_cliente, mensaje, 1024, 0);
            }
        }
        close(conexion_cliente);
    }
    close(conexion_servidor);
    return;

}
void agregarAJugeo(){
    printf("------------------------------------------------------\n");
    printf("Menu para agregar Fruta / fantasma \n");
    printf("Ingrese 1 para agregar Fruta, 2 para agregar Fantasma, 3 para agregar Pastilla, \n");
    printf("        4 para modifiacar la velocidad de los fantasmas, 5 para no hacer nada\n");
    char f;
    f = getchar();
    f = getchar();
    if(f == '1') {
        printf("Creado Fruta\n");
        printf("   Ingrese el tipo (1 = cereza, 2 = fresa, 3 = naranja, 4 = manzana, 5 = uvas)\n");
        int t;
        scanf("%d", &t);

        printf("   Ingrese el puntaje \n");
        int p;
        scanf("%d", &p);

        //Eviar a socket
        sprintf(mensaje, "fruta,%d,%d", t,p);
        printf("--Fruta Creada--\n");
    }
    if(f == '2') {
        printf("Creado fantasma\n");
        printf("     Ingrese el tipo (1 = Blinky, 2 = Pinky, 3 = inky, 4 = Clynde)");
        int tipo;
        scanf("%d", &tipo);
        printf("\n   Ingrese velocidad ");
        int vel;
        scanf("%d", &vel);
        printf("\n   Ingrese La fila");
        int fil;
        scanf("%d", &fil);
        printf("\n   Ingrese La Columna");
        int col;
        scanf("%d", &col);
        //enviar a socket
        sprintf(mensaje, "fantasma,%d,%d,%d,%d", tipo,vel,fil,col);
        printf("--Fanstasma Creado--\n");
    }
    if(f == '3') {
        printf("Creado Pastilla\n");
        printf("\n   Ingrese La fila");
        int fil;
        scanf("%d", &fil);
        printf("\n   Ingrese La Columna");
        int col;
        scanf("%d", &col);
        //Enviar a socket
        sprintf(mensaje, "pastilla,%d,%d",fil,col);
        printf("--Pastilla Creada--\n");
    }
    if(f == '4') {
        printf("Cambiando velocidad a fantasmas\n");
        printf("\n   A que fantasma quiere cambiar velocidad");
        printf("\n      (1 = Blinky, 2 = Pinky, 3 = inky, 4 = Clynde)");
        int tipo;
        scanf("%d", &tipo);
        printf("\n   Nueva velocidad");
        int vel;
        scanf("%d", &vel);
        //Enviar a socket
        sprintf(mensaje, "velocidad,%d,%d",tipo,vel);
        printf("--Velocidad cambiada--\n");
    }
    if(f == '5') {
        printf("Se decide no agregar nada");
        return;
    }
    if(f == 's') {
        printf("La coneccion con el cliente se terminara\n");
        coneccion= false;
    }

    printf("EL mensaje que se enviara al Cliente es: \"%s\". \n",mensaje);
    return;
}

void cliente(){
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int PORT = 25578;


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Error en la creacion del socket \n");
        return;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nPuerto o ip incorertos \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConeccion fallida \n");
        return;
    }
    agregarAJugeo();
    send(sock , mensaje , 1024, 0 );
    printf("Se envia mensaje\n");
    printf(" Presione \"a\" si desea agregar una entidad al juego o \"s\" para salir\n");
    close(sock);
}

void iniciarCliente(){
    printf("------------------------------------------------------\n");
    printf(" Menu del Servidor\n");
    printf(" Presione \"a\" si desea agregar una entidad al juego o \"s\" para salir\n");
    while (coneccion) {
        char a;
        scanf("%c", &a);
        if(a == 's') {
            printf("La coneccion con Java se terminara\n");
            coneccion= false;
            break;
        }
        if(a == 'a') {
            cliente();
        }
    }
}