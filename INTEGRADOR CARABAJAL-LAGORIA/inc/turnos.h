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
#ifndef TURNOS_H /* reemplazar por el nombre del archivo correspondiente */
#define TURNOS_H /* reemplazar por el nombre del archivo correspondiente */

/* === Inclusiones de archivos externos ======================================================== */
#include "tdaTurnos.h"
/* === Definicion y Macros ===================================================================== */

/* === Declaraciones de tipos de datos ========================================================= */
/* === Declaraciones de variables externas ===================================================== */
/*NO utilizar*/

/* === Declaraciones de funciones externas ===================================================== */

/*Función: fecha cargarFechaActual()
Tarea: Función del tipo estructura fecha que permite el ingreso de la fecha actual en el formato dia,mes,anio.
Parámetros: No recibe parámetros.
Retorna: Retorna una estructura del tipo fecha.*/
fecha cargarFechaActual();

/*Función: fecha cargarHora()
Tarea: Función del tipo estructura hora que permite el ingreso de una hora en el formato hora, minuto.
Parámetros: No recibe parámetros.
Retorna: Retorna una estructura del tipo hora.*/
hora cargarHora();

/*Función: usuario generarStruct(char cadena[])
Tarea: Función del tipo estructura usuario que recibe una cadena, la desarma, desencripta el parámetro ubicado a la derecha del separador (:) y guarda ambos parámetros en una estructura tipo usuario.
Parámetros: Recibe un parámetro char cadena[] de una longitud de máximo 125 caracteres.
Retorna: Retorna una estructura del tipo usuario.*/
usuario generarStruct(char cadena[]);

/*Función: turnos leerTurnoArchivo(int i, char nombreArchivo[])
Tarea: Función del tipo estructura turnos que permite la lectura de una estructura del mismo tipo que se encuentra dentro de un archivo e imprime esta estructura por pantalla.
Parámetros: Recibe la posición del puntero y el nombre del archivo que se desea leer.
Retorna: No retorna parâmetros.*/
turnos leerTurnoArchivo(int posicion, char nombreArchivo[]);

/*Función: void adorno()
Tarea: Realiza una serie de impresiones por pantalla donde genera un diseño que funciona como separador de procesos internos.
Parámetros: No recibe parámetros.
Retorna: No retorna parámetros.*/
void adorno();

/*Función: void nombrePrograma()
Tarea: Realiza una serie de impresiones por pantalla donde presenta el nombre del programa.
Parámetros: No recibe parámetros.
Retorna: No retorna parámetros.*/
void nombrePrograma();

/*Función: void agendaHoy(char nombreArchivo[], int codTurno)
Tarea: Recibe como parámetro el nombre del archivo de turnos, le pide al usuario el ingreso de la fecha actual y realiza una comparación entre el archivo de turnos con la fecha actual ingresada, luego guarda las coincidencias en un nuevo archivo de texto auxiliar, pasa como datos el nombre del archivo y la cantidad de coincidencias a otra función que ordena el archivo para luego volver a esta función para leerlo, mostrado por pantalla y removerlo.
Parámetros: Recibe el nombre del archivo de turnos y el código de turnos.
Retorna: No retorna parámetros.*/
void agendaHoy(char nombreArchivo[], int codTurno);

/*Función: void agendaHoy(char nombreArchivo[], int codTurno)
Tarea: Recibe como parámetro el nombre del archivo de turnos, le pide al usuario el ingreso del nombre de la mascota y realiza una comparación entre el archivo de turnos con el nombre de la mascota ingresada, luego guarda las coincidencias en un nuevo archivo de texto auxiliar que es leído, mostrado por pantalla y removido.
Parámetros: Recibe el nombre del archivo de turnos y el código de turnos.
Retorna: No retorna parámetros.*/
void buscarMascotas(char nombreArchivo[], int codTurno);

/*Función: int compararHoras(hora unTurno, hora OtroTurno)
Tarea: Compara dos estructuras del tipo hora y retorna una bandera.
Parámetros: Recibe dos estructuras del tipo hora.
Retorna: Retorna una bandera verdadera(1) en el caso de que el segundo parámetro sea mayor al primero y una bandera falsa(0) si el primer parámetro es mayor al segundo*/
int compararHoras(hora unTurno, hora OtroTurno);

/*Función: controlArchivo(char nombreDelArchivo[])
Tarea: Controla la existencia del archivo cuyo nombre es recibido como parámetro, si no existe lo crea.
Parámetros: Recibe como parámetro el nombre del archivo a comprobar.
Retorna: No retorna parámetros.*/
void controlArchivo(char nombreDelArchivo[]);

/*Función: int controlServicios(int c);
Tarea: Realiza el control de las opciones de los servicios y retorna una bandera.
Parámetros: Recibe como parámetro un entero proveniente de servicios.
Retorna: Retorna una bandera verdadera(1) si es que se cumplen y una bandera negativa(0) si estos no se cumplen.*/
int controlServicios(int c);

/*Función: int convertirEntero(char numero[6]);
Tarea: Convierte un carácter a entero con el método atoi utilizando la librería "stdlib".
Parámetros: Recibe una cadena de longitud máxima de 6 caracteres.
Retorna: Retorna el entero obtenido mediante el parámetro ingresado.*/
int convertirEntero(char numero[6]);

/*Función: void presentarMateria()
Tarea: Crea un archivo auxiliar con el nombre recibido como parámetro y lo abre en el método "a+", carga en su interior la estructura recibida y se cierra.
Parámetros: Recibe como parámetro el nombre del archivo y una estructura del tipo turno.
Retorna: No retorna parámetros.*/
void crearArchivoAux(char nombreArchivo[], turnos unTurno);

/*Función: int esDigito(char numero[7])
Tarea: Recibe una cadena de caracteres cuyo máximo es de 7, verifica que todos los caracteres ingresados sean numéricos y devuelve una bandera.
Parámetros: Recibe una cadena de longitud máxima de 7 caracteres.
Retorna: Retorna una bandera verdadera(1) en el caso de que toda la cadena ingresada sea numérica y una bandera falsa(0) en el caso de encontrar algún carácter no numérico.*/
int esDigito(char numero[7]);

/*Función: void imprimirServicios()
Tarea: Recibe un parámetro entero e imprime el servicio elegido.
Parámetros: Recibe un entero.
Retorna: No retorna parámetros*/
void imprimirServicios(int c);

/*Función: void leerCadena(char nombre[])
Tarea: Reciba una cadena de caracteres, generalmente nombres, y verifica que la cadena dada solo contenga letras y espacios, en el caso contrario le pide al usuario que ingrese nuevamente la cadena y posteriormente la copia y retorna.
Parámetros: Recibe como parámetro una cadena.
Retorna: Retorna la misma cadena de ingreso en el caso de ser correcta, si no, retorna el nuevo ingreso del usuario.*/
void leerCadena(char nombre[]);

/*Función: leerTurno(int numTurno, char nombreArchivo[])
Tarea: Crea el archivo principal de turnos, realiza la carga de turnos en una estructura del tipo turnos y los escribe en el archivo principal "turnosVete.dat"
Parámetros: Recibe como parametro el numero de turnos y el nombre del archivo a crear, escribir y editar.
Retorna: No retorna parámetros.*/
void leerTurno(int numTurno, char nombreArchivo[]);

/*Función: void menuUno(char *op)
Tarea: Muestra por pantalla el primer menú o menú principal y recibe una opción de dicho menú que luego es enviada a otra función que controla si la opción es válida y en el caso de coincidir redirige al usuario a la opción solicitada.
Parámetros: No recibe parámetros.
Retorna: No retorna parámetros.*/
void menuUno(char *op);

/*Función: void MostrarArchivo(turnos persona);
Tarea: Recibe una estructura del tipo turnos y muestra por pantalla su contenido.
Parámetros: Recibe una estructura de turnos
Retorna: No retorna parámetros.*/
void MostrarArchivo(turnos persona);

/*Función: void mostrarTurno(char nombreArchivo[]);
Tarea: Recibe el nombre del archivo y muestra todo el contenido del mismo por pantalla.
Parámetros: Recibe el nombre del archivo.
Retorna: No retorna parámetros.*/
void mostrarTurno(char nombreArchivo[]);

/*Función: void opcionServicio();
Tarea: Lee el archivo de texto "servicios.txt", reemplaza los punto y coma ";" por espacios " ", luego los muestra por pantalla hasta terminar el archivo.
Parámetros: No recibe parámetros.
Retorna: No retorna parámetros.*/
void opcionServicio();

/*Función: void ordenarArchivoAux(char nombreArchivo[], int coincidencias);
Tarea: Al comienzo del programa lee cuantas estructuras de turno hay almacenadas en el archivo "turnosVete.dat". Luego retorna como "numTurnos".
Parámetros: Recibe como parámetro el nombre del archivo donde se están almacenando los turnos.
Retorna: Retorna la cantidad de estructuras de turno y las almacena en la variable numTurnos.*/
void ordenarArchivoAux(char nombreArchivo[], int coincidencias);

/*Función: int recuperarUltimoTurno(char nombreArchivo[]);
Tarea: Al comienzo del programa lee cuantas estructuras de turno hay almacenadas en el archivo "turnosVete.dat". Luego retorna como "numTurnos".
Parámetros: Recibe como parámetro el nombre del archivo donde se están almacenando los turnos.
Retorna: Retorna la cantidad de estructuras de turno y las almacena en la variable numTurnos*/
int recuperarUltimoTurno(char nombreArchivo[]);

/*Función: void servicios(int *selector);
Tarea: Controla que la opción cargada en el menú de servicios sea válida retorna el mismo parámetro de ingreso en el caso de que este sea correcto si no, le pide al usuario que vuelva a intentarlo.
Parámetros: Recibe como parámetro un puntero.
Retorna: Retorna el mismo parámetro que recibe en el caso de ser correcto*/
void servicios(int *selector);

/* === Ciere de archivo ======================================================================== */
#endif
