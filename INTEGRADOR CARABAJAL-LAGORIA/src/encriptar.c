/* Copyright 2021, Cátedra de Informática y Programación I
 * Departamento de Electricidad, Electrónica y Computación
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * Copyright 2021, Mariana Sánchez <msanchez@herrera.unt.edu.ar>, Enzo A. Sémola
 * <esemola@herrera.unt.edu.ar> All rights reserved.
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
/* === Inclusiones de cabeceras
 * ================================================================ */

#include "encriptar.h"
/* === Definicion y Macros
 * ===================================================================== */

/* === Declaraciones de funciones internas
 * ===================================================== */

/* === Definiciones de funciones internas
 * ====================================================== */

void desencriptar(char frase[MAX]) {
    int i = 0, numero = 5;
    while (frase[i] != '\0') {
        if (frase[i] == '$')
            frase[i] = 'a';
        else if (frase[i] == '-')
            frase[i] = 'e';
        else if (frase[i] == '&')
            frase[i] = 'i';
        else if (frase[i] == '#')
            frase[i] = 'o';
        else if (frase[i] == '!')
            frase[i] = 'u';
        else
            frase[i] = frase[i] - numero;
        i++;
    }
}

void encriptar(char frase[MAX]) {
    int i = 0, numero = 5;
    while (frase[i] != '\0') {
        if (frase[i] == 'a')
            frase[i] = '$';
        else if (frase[i] == 'e')
            frase[i] = '-';
        else if (frase[i] == 'i')
            frase[i] = '&';
        else if (frase[i] == 'o')
            frase[i] = '#';
        else if (frase[i] == 'u')
            frase[i] = '!';
        else
            frase[i] = frase[i] + numero;
        i++;
    }
}
