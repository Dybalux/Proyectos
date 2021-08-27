/* Copyright 2021, Cátedra de Informática y Programación I
 * Departamento de Electricidad, Electrónica y Computación
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana Sánchez <msanchez@herrera.unt.edu.ar>, Enzo A. Sémola <esemola@herrera.unt.edu.ar>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* === Inclusiones de cabeceras ================================================================ */
/* En primer lugar incluir el archivo .h correspondiente a éste archivo .c si corresponde*/
/* #include "plantilla.h"*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <controles.h>
#include "encriptar.h"
#include "tdaTurnos.h"

/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de funciones internas ====================================================== */
void adorno() {
    int i;
    printf("\n");
    for (i = 1; i <= 134; i++) {
        printf("*");
    }
}

void nombrePrograma() {
    printf("\n\t\t\t\t\t\t CENTRO DE ESTETICA PARA MASCOTAS");
}

int recuperarUltimoTurno(char nombreArchivo[]) {
    FILE *salvarTurno;
    turnos persona;
    int numTurno = 0;
    int pesoPersona = sizeof(persona);
    int tamanioStructs = 0;
    int cantidadStruct = 0;
    salvarTurno = fopen(nombreArchivo, "rb");
    while (feof(salvarTurno) == 0) {
        fread(&persona, sizeof(persona), 1, salvarTurno);
        tamanioStructs = tamanioStructs + sizeof(persona);
    }
    fclose(salvarTurno);
    numTurno = tamanioStructs / pesoPersona;
    return numTurno;
}

int esDigito(char numero[7]) {
    int control = 0, i;
    for (i = 0; i < strlen(numero); i++) {
        if (isdigit(numero[i]) == 0) {
            control = 1;
            return control;
        } else {
            control = 0;
        }
    }
    return control;
}

void leerCadena(char nombre[]) {
    int i = 0, c = 0, ban;
    char cadena[50];
    do {
        fgets(cadena, 50, stdin);
        cadena[strlen(cadena) - 1] = '\0';
        for (i = 0; i < strlen(cadena); i++) {
            if (isdigit(cadena[i]) != 0) {
                do {
                    printf("\n\tError, intentalo de nuevo:");
                    fgets(cadena, 50, stdin);
                    cadena[strlen(cadena) - 1] = '\0';
                    ban = esDigito(cadena);
                } while (ban == 0);
            } else if (isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0) {
                c++;
            }
        }
    } while (c != 0);

    strcpy(nombre, cadena);
}

int convertirEntero(char numero[6]) {
    int aux;
    aux = atoi(numero);
    return aux;
}

usuario generarStruct(char cadena[]) {
    usuario datos;
    int inicio = 0;
    char *partir = strtok(cadena, ":");
    strcpy(datos.nombreUsuario, partir);
    partir = strtok(NULL, ":");
    desencriptar(partir);
    strcpy(datos.contrasenia, partir);
    return datos;
}

fecha cargarFechaActual() {
    fecha hoy;
    int aux = 0;
    char diaAct[7], mesAct[7], anioAct[7];
    printf("\n");
    printf("\n\t\tIngrese la fecha del turno:");
    do {
        printf("\n\t\t\t\tIngrese dia-->");
        fgets(diaAct, 7, stdin);
        diaAct[strlen(diaAct) - 1] = '\0';
        aux = esDigito(diaAct);
    } while (aux != 0);
    hoy.dia = convertirEntero(diaAct);
    do {
        printf("\n\t\t\t\tIngrese mes-->");
        fgets(mesAct, 7, stdin);
        mesAct[strlen(mesAct) - 1] = '\0';
        aux = esDigito(mesAct);
    } while (aux != 0);
    hoy.mes = convertirEntero(mesAct);
    do {
        printf("\n\t\t\t\tIngrese anio-->");
        fgets(anioAct, 7, stdin);
        anioAct[strlen(anioAct) - 1] = '\0';
        aux = esDigito(anioAct);
    } while (aux != 0);
    hoy.anio = convertirEntero(anioAct);
    return hoy;
}
hora cargarHora() {
    hora ingreso;
    int aux = 0;
    char hs[7], min[7];
    printf("\n");
    printf("\n\tIngrese la hora del turno");
    do {
        printf("\n\n\t\t\t\tIngrese la hora-->");
        fgets(hs, 7, stdin);
        hs[strlen(hs) - 1] = '\0';
        aux = esDigito(hs);
    } while (aux != 0);
    ingreso.hora = convertirEntero(hs);
    do {
        printf("\n\n\t\t\t\tIngrese minutos-->");
        fgets(min, 7, stdin);
        min[strlen(min) - 1] = '\0';
        aux = esDigito(min);
    } while (aux != 0);
    ingreso.minutos = convertirEntero(min);
    return ingreso;
}

void controlArchivo(char nombre[]) {
    FILE *baseDeDatos;
    baseDeDatos = fopen(nombre, "r");
    if (baseDeDatos == NULL) {
        printf("\nNo se pudo abrir en modo lectura, El archivo no existe se intentara crearlo…");
        baseDeDatos = fopen(nombre, "w");
        if (baseDeDatos == NULL) {
            printf("\nNo se pudo crear el archivo… ");
            exit(0);
        } else {
            printf("\n\nIniciando...\n");
        }
    }
    fclose(baseDeDatos);
    return;
}
void crearArchivoAux(char nombreArchivo[], turnos unTurno) {
    FILE *aux;
    controlArchivo(nombreArchivo);
    aux = fopen(nombreArchivo, "a+");
    fwrite(&unTurno, sizeof(unTurno), 1, aux);
    fclose(aux);
}

void opcionServicio() {
    int i;
    char nombre[] = "servicios.txt";
    char cadena[50];
    controlArchivo(nombre);
    FILE *abrir;
    abrir = fopen(nombre, "rt");
    while (fgets(cadena, sizeof(cadena), abrir) != 0) {
        for (i = 0; i < strlen(cadena); i++) {
            if (cadena[i] == ';') {
                cadena[i] = ' ';
            }
        }
        printf("\n\t\t\t\t%s", cadena);
    }
    fclose(abrir);
}
void imprimirServicios(int c) {
    if (c == 1) {
        printf("\n\n\tEl servicio elegido es peinado");
    } else if (c == 2) {
        printf("\n\n\tEl servicio elegido es baño");
    } else if (c == 3) {
        printf("\n\n\tEl servicio elegido es corte de pelos higiénicos");
    }
}
int controlServicios(int c) {
    int aux = 0;
    if (c == 1) {
        aux = 1;
    } else if (c == 2) {
        aux = 1;
    } else if (c == 3) {
        aux = 1;
    } else {
        aux = 0;
    }
    return aux;
}

void servicios(int *selector) {
    int entero = 0, aux = 0, ban = 0;
    char seleccionar[5];
    printf("\n\n\tSeleccione el servicio que desea contratar:\n\n");
    opcionServicio();
    do {
        do {
            printf("\n\n\t\t\t\tIngrese una opcion-->");
            fgets(seleccionar, 5, stdin);
            seleccionar[strlen(seleccionar) - 1] = '\0';
            aux = esDigito(seleccionar);

        } while (aux != 0);
        entero = convertirEntero(seleccionar);
        ban = controlServicios(entero);
    } while (ban != 1);
    *selector = entero;
}

turnos ingresarDatos(int numTurno) {
    char dia[6], mes[6], anio[6], minutos, hora;
    int verificar = 0;
    turnos persona;

    persona.codTurno = numTurno;
    printf("\n\n\tIngrese el nombre del duenio de la mascota-->");
    leerCadena(persona.nomDuenio);
    printf("\n\n\tIngrese el nombre de la mascota-->");
    leerCadena(persona.nomMascota);

    do {
        persona.unaFecha = cargarFechaActual();
        verificar = controlFecha(persona.unaFecha);
    } while (verificar != 1);
    do {
        persona.unaHora = cargarHora();
        verificar = controlHora(persona.unaHora);
    } while (verificar != 1);
    servicios(&(persona.servicio));
    printf("\nLos datos del turno guardado son:");
    printf("\n\n\tNombre del duenio: %s ", persona.nomDuenio);
    printf("\n\tNombre de la mascota: %s", persona.nomMascota);
    printf("\n\tFecha: %i/%i/%i", persona.unaFecha.dia, persona.unaFecha.mes, persona.unaFecha.anio);
    printf("\n\tHora: %i:%i", persona.unaHora.hora, persona.unaHora.minutos);
    imprimirServicios(persona.servicio);
    printf("\n\tNumero de turno: %i", persona.codTurno);
    return persona;
}

void leerTurno(int numTurno, char nombreArchivo[]) {
    FILE *guardarTurno;
    turnos cargarPersona;
    cargarPersona = ingresarDatos(numTurno);
    guardarTurno = fopen(nombreArchivo, "ab");
    fwrite(&cargarPersona, sizeof(cargarPersona), 1, guardarTurno);
    fclose(guardarTurno);
    return;
}

void MostrarArchivo(turnos persona) {
    printf("\n\n\tEl codigo de este turno es: %i", persona.codTurno);
    printf("\n\n\tEl nombre del duenio es: %s", persona.nomDuenio);
    printf("\n\n\tEl nombre de la mascota es : %s", persona.nomMascota);
    printf("\n\n\tLa fecha ingresada fue: %i/%i/%i", persona.unaFecha.dia, persona.unaFecha.mes, persona.unaFecha.anio);
    printf("\n\n\tLa hora ingresada fue: %i:%i", persona.unaHora.hora, persona.unaHora.minutos);
    imprimirServicios(persona.servicio);
    printf("\n\n");
    return;
}

void mostrarTurno(char nombreArchivo[]) {
    int i = 0;
    FILE *mostrarArchivo;
    turnos persona;
    int cantidad;
    char cadena[cantidad];
    mostrarArchivo = fopen(nombreArchivo, "rb");
    while (feof(mostrarArchivo) == 0) {
        fread(&persona, sizeof(persona), 1, mostrarArchivo);

        if (feof(mostrarArchivo) == 0) {
            MostrarArchivo(persona);
        }
    }
    fclose(mostrarArchivo);
    return;
}

int condicionMenuUno(char cond) {
    int aux = 0;
    if (isalpha(cond) != 0) {
        if (cond == 'a' || cond == 'b' || cond == 'c' || cond == 'd' || cond == 'e') {
            aux = 1;
        }
    } else {
        aux = 0;
    }
    return aux;
}
void menuUno(char *op) {
    int ban;
    char eleccion;
    do {
        printf("\n\n\ta) Solicitar un turno.");
        printf("\n\n\tb) Mostrar al usuario la agenda de mascotas a ser atendidas en el dia.");
        printf("\n\n\tc) Mostrar la ultima fecha en la que fue atendida una determinada mascota");
        printf("\n\n\td) Mostrar todos los turnos.");
        printf("\n\n\te) Salir del programa.");
        printf("\n\n\tIngrese su eleccion(letra) por teclado-->");
        scanf("%c", &eleccion);
        fgetc(stdin);
        ban = condicionMenuUno(eleccion);
    } while (ban != 1);

    *op = eleccion;
}

turnos leerTurnoArchivo(int posicion, char nombreArchivo[]) {
    turnos unaPersona;
    FILE *archivo;
    turnos aux;
    int posicionPuntero = posicion;
    archivo = fopen(nombreArchivo, "rb");
    fseek(archivo, posicionPuntero * sizeof(unaPersona), 0);
    fread(&aux, sizeof(aux), 1, archivo);
    fclose(archivo);
    return aux;
}

int compararHoras(hora unTurno, hora OtroTurno) {
    int ban = 0;
    if (unTurno.hora < OtroTurno.hora) {
        ban = 1;
    } else if (unTurno.hora == OtroTurno.hora) {
        if (unTurno.minutos < OtroTurno.minutos) {
            ban = 1;
        }
    }
    return ban;
}

void ordenarArchivoAux(char nombreArchivo[], int coincidencias) {
    turnos unTurno, otroTurno, aux;
    FILE *archivoAux;
    controlArchivo(nombreArchivo);
    long i;
    long j;
    long k = coincidencias;
    archivoAux = fopen(nombreArchivo, "r+b");
    for (i = 0; i < k - 1; i++) {
        fseek(archivoAux, i * sizeof(unTurno), 0);
        fread(&unTurno, sizeof(unTurno), 1, archivoAux);
        for (j = i + 1; j < k; j++) {
            fseek(archivoAux, j * sizeof(otroTurno), 0);
            fread(&otroTurno, sizeof(otroTurno), 1, archivoAux);

            if (compararHoras(unTurno.unaHora, otroTurno.unaHora) == 0) {
                fseek(archivoAux, i * sizeof(unTurno), 0);
                fwrite(&otroTurno, sizeof(unTurno), 1, archivoAux);

                fseek(archivoAux, j * sizeof(otroTurno), 0);
                fwrite(&unTurno, sizeof(otroTurno), 1, archivoAux);

                fseek(archivoAux, i * sizeof(otroTurno), 0);
                fread(&unTurno, sizeof(otroTurno), 1, archivoAux);
            }
        }
    }
    fclose(archivoAux);
    return;
}

void agendaHoy(char nombreArchivo[], int codTurno) {
    turnos unTurno, otroTurno, aux;
    fecha diaHoy;

    int cantidadDatos = codTurno;
    int ban;
    int coincidencias = 0;
    char nombreArchivoAuxiliar[] = "agendaHoy.dat";

    printf("\n\n\tIngrese la fecha actual");
    do {
        diaHoy = cargarFechaActual();
        ban = controlFecha(diaHoy);
    } while (ban != 1);

    for (int i = 0; i < cantidadDatos; i++) {
        unTurno = leerTurnoArchivo(i, nombreArchivo);
        if (unTurno.unaFecha.anio == diaHoy.anio) {
            if (unTurno.unaFecha.mes == diaHoy.mes) {
                if (unTurno.unaFecha.dia == diaHoy.dia) {
                    aux = unTurno;
                    crearArchivoAux(nombreArchivoAuxiliar, aux);
                    coincidencias++;
                }
            }
        }
    }
    if (coincidencias > 1) {
        printf("\nLa genda de hoy es la siguiente: ");
        ordenarArchivoAux(nombreArchivoAuxiliar, coincidencias);
        mostrarTurno(nombreArchivoAuxiliar);
    } else if (coincidencias == 1) {
        MostrarArchivo(aux);
    } else {
        printf("\n\n\tNo se ha encontrado ningun registro para el dia de hoy");
    }
    remove(nombreArchivoAuxiliar);
    return;
}

void buscarMascotas(char nombreArchivo[], int codTurno) {
    turnos turno, otroTurno, aux;
    int cantidadDatos = codTurno;
    char nombreMascota[50];
    char nombreArchivoAuxiliar[] = "turnosOrdNombreaux.dat";
    int coincidencias = 0;
    printf("\n\n\tIngrese el nombre de la mascota que desea buscar --> ");
    leerCadena(nombreMascota);

    for (int j = 0; j < cantidadDatos; j++) {
        turno = leerTurnoArchivo(j, nombreArchivo);
        if (strcmp(nombreMascota, turno.nomMascota) == 0) {
            aux = turno;
            crearArchivoAux(nombreArchivoAuxiliar, aux);
            coincidencias++;
        }
    }
    if (coincidencias > 1) {
        printf("\nEl turno más reciente encontrado fue: ");
        ordenarArchivoAux(nombreArchivoAuxiliar, coincidencias);
        aux = leerTurnoArchivo(coincidencias - 1, nombreArchivoAuxiliar);
        MostrarArchivo(aux);
    } else if (coincidencias == 1) {
        MostrarArchivo(aux);
    } else {
        printf("\n\n\tNo se ha encontrado ningun registro de la mascota: %s", nombreMascota);
    }
    remove(nombreArchivoAuxiliar);
}
