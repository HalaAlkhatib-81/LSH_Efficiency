/** @file Text_permutator.hh
    @brief Especificación de la clase Text_permutator
*/

#ifndef _TEXT_PERMUTATOR_HH_ 
#define _TEXT_PERMUTATOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>
#include "Text_utils.hh"
#endif

using namespace std;

/** @class Text_permutato
    @brief Clase que genera permutaciones de un conjunto de palabras
*/

class Text_permutator {

    public:

    /** @brief Genera permutaciones de un conjunto de palabras
        \pre el archivo con nombre 'archivo_entrada' debe de existir y no estar vacío
        \post genera un archivos con permutaciones del texto original
    */
    static void generar_permutaciones(const string& archivo_entrada, int tamano, int num_permutaciones);
};

#endif