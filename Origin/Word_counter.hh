/** @file Word_counter.hh
    @brief Especificación de la clase Word_counter
*/

#ifndef _WORD_COUNTER_HH_ 
#define _WORD_COUNTER_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <unordered_set>
#include <fstream>
#include "Text_utils.hh"
#endif
using namespace std;

/** @class Word_counter
    @brief Clase que cuenta palabras únicas en un texto, excluyendo stopwords.
*/

class Word_counter {

    public:

    /** @brief Ejecuta el conteo de palabras únicas
        \pre el archivo con nombre 'archivo_entrada' existe
        \post devuelve el número de palabras únicas sin stopwords
    */
    static int contpalabras(const string& archivo_entrada);

};

#endif