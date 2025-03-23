/** @file K_Shingles_Permutator.hh
    @brief Especificación de la clase K_Shingles_Permutator.
*/

#ifndef _K_SHINGLES_PERMUTATOR_HH_
#define _K_SHINGLES_PERMUTATOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include "Text_utils.hh"
#endif

using namespace std;

/** @class K_Shingles_Permutator
    @brief Clase que genera permutaciones de k-shingles.
*/
class K_Shingles_Permutator {
public:
    /** @brief genera permutaciones a partir de un archivo de k-shingles.
        \pre el archivo con nombre 'archivo_entrada' debe de existir y no estar vacío
        \post genera archivos con permutaciones de los k-shingles.
    */
    static void generar_permutaciones(const string& archivo_entrada, int tamano, int num_permutaciones, int n);
};

#endif