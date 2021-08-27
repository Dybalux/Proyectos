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


/* === Ifndef: para prevenir las inclusiones duplicadas ======================================================== */
#ifndef CONTROLES_H  /* reemplazar por el nombre del archivo correspondiente */
#define CONTROLES_H  /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include <stdlib.h>
#include "tdaTurnos.h"
/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */

/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */

/*Función: int controlFecha(fecha unaFecha)
Tarea: Recibe una estructura de datos correspondientes a la estructura de una fecha (dia,mes,anio) y comprueba que la fecha sea valida.
Parámetros: Recibe una estructura de datos entera.
Retorna: Retorna una bandera verdadera(1) y una falsa(0).*/
int controlFecha(fecha unaFecha);

/*Función: controlHora(hora unaHora)
Tarea: Recibe una estructura de datos correspondientes a la estructura de una hora (hora,minutos) y comprueba que la hora sea valida.
Parámetros: Recibe una estructura de datos entera.
Retorna: Retorna una bandera verdadera(1) y una falsa(0).*/
int controlHora(hora unaHora);

/* === Ciere de archivo ======================================================================== */
#endif
