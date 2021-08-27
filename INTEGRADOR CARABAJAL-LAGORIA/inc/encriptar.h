/* Copyright 2021, CÃ¡tedra de InformÃ¡tica y ProgramaciÃ³n I
 * Departamento de Electricidad, ElectrÃ³nica y ComputaciÃ³n
 * Facultad de Ciencias Exactas y TecnologÃ­a 
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana SÃ¡nchez <msanchez@herrera.unt.edu.ar>, Enzo A. SÃ©mola <esemola@herrera.unt.edu.ar>
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


/* === Ifndef: para prevenir las inclusiones duplicadas ======================================================== */
#ifndef ENCRIPTAR_H  /* reemplazar por el nombre del archivo correspondiente */
#define ENCRIPTAR_H  /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* === Definicion y Macros ===================================================================== */
#define MAX 128
/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */
/* === Declaraciones de funciones internas ===================================================== */

/*Función: encriptar
Tarea: encripta una cadena dada y guarda ese valor en la misma cadena
Parámetros: recibe una cadena de caracteres de longitud máxima MAX
Retorna: no retorna valor*/
void encriptar(char frase[MAX]);

/*
Función: desencriptar
Tarea: desencripta una cadena dada y guarda ese valor en la misma cadena
Parámetros: recibe una cadena de caracteres de longitud máxima MAX
Retorna: no retorna valor
*/
void desencriptar(char frase[MAX]);
/* === Ciere de archivo ======================================================================== */
#endif
