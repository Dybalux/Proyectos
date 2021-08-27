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
#include <string.h>
#include <stdalign.h>
#include <ctype.h>
#include "presentacion.h"
#include "tdaTurnos.h"
#include "turnos.h"
#include "controles.h"

/* === Definicion y Macros ===================================================================== */
#define tam 50

/* === Declaraciones de tipos de datos internos ================================================ */

/* === Definiciones de variables internas ====================================================== */

/* === Declaraciones de funciones internas ===================================================== */
int main(int argc, char *argv[]) {
    adorno();
    printf("\n\t\t\tIniciar sesion:");
    adorno();
    if (argc == 3) {
        FILE *abrir;
        int bandera;
        char archivo[] = "usuarios.txt";
        char copia[125];
        usuario ingresoPorConsola;
        usuario enMemoria;
        strcpy(ingresoPorConsola.nombreUsuario, argv[1]);
        strcpy(ingresoPorConsola.contrasenia, argv[2]);
        controlArchivo(archivo);
        abrir = fopen(archivo, "rt");
        while (feof(abrir) == 0) {
            if (fgets(copia, 125, abrir) != NULL) {
                enMemoria = generarStruct(copia);
                enMemoria.nombreUsuario[strlen(enMemoria.nombreUsuario) - 1] = '\0';
                enMemoria.contrasenia[strlen(enMemoria.contrasenia) - 1] = '\0';
                ingresoPorConsola.nombreUsuario[strlen(ingresoPorConsola.nombreUsuario) - 1] = '\0';
                if (strcmp(enMemoria.nombreUsuario, ingresoPorConsola.nombreUsuario) == 0) {
                    if (strcmp(enMemoria.contrasenia, ingresoPorConsola.contrasenia) == 0) {
                        printf("\n\tACCESO CORRECTO");
                        break;
                    } else {
                        printf("\n\tACCESO DENEGADO");
                        exit(0);
                    }
                } else {
                    printf("\nACCESO DENEGADO");
                    exit(0);
                }
            }
        }
    } else {
        printf("\nERROR");
        printf("\nRecordar usar espacio entre cada llamada, y que va sin <>");
        printf("\nEl formato de ingreso en linux es:");
        printf("\n\t\tapp.out <usuario> <contrasenia>");
        printf("\nEl formato de ingreso en windows es:");
        printf("\n\t\tapp.exe <usuario> <contrasenia>");
        exit(0);
    }
    char nombreArchivo[] = "turnosVete.dat";
    fecha diaHoy;
    int codTurno = 1;
    int ban = 0;
    char opcion, mascota[tam];
    controlArchivo(nombreArchivo);
    codTurno = recuperarUltimoTurno(nombreArchivo);
    presentarMateria();
    presentarPersona();
    presentarTema();
    do {
        adorno();
        nombrePrograma();
        adorno();
        menuUno(&opcion);
        switch (opcion) {
            case 'a': /*Lectura de nuevos turnos*/
                leerTurno(codTurno, nombreArchivo);
                codTurno++;
                break;
            case 'b': /*Mostrar por pantalla los turnos de hoy*/
                adorno();
                agendaHoy(nombreArchivo, codTurno);
                adorno();
                break;
            case 'c':
                adorno();
                buscarMascotas(nombreArchivo, codTurno);
                adorno();
                break;
            case 'd':
                adorno();
                printf("\n\tMostrar todos los turnos");
                adorno();
                mostrarTurno(nombreArchivo);
                adorno();
                break;
            case 'e':
                break;
        }
    } while (opcion != 'e');

    return 0;
}

/* === Definiciones de funciones internas ====================================================== */

/* === Definiciones de funciones externas ====================================================== */

/* === Cierre de archivo ======================================================================== */
