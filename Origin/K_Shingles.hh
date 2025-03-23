/** @file K_Shingles.hh
    @brief Especificación de la clase K_Shingles
*/

#ifndef _K_SHINGLES_HH_ 
#define _K_SHINGLES_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <fstream>
#include "Text_utils.hh"
#endif

using namespace std;

/** @class K_Shingles
    @brief Clase que genera k-shingles a partir de un texto
*/

class K_Shingles {

    public:

    /** @brief Genera k-shingles a partir de un archivo de texto
        \pre el archivo con nombre 'archivo_entrada' debe de existir y no estar vacío
        \post genera un archivos con los k-shingles
    */
    static void generar_k_shingles(const string& archivo_entrada, const string& archivo_salida, int k);
};

#endif