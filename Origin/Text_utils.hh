/** @file Text_utils.hh
    @brief Especificación de la clase Text_utils
*/

#ifndef _TEXT_UTILS_HH_ 
#define _TEXT_UTILS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#endif
using namespace std;

/** @class Text_utils
    @brief Representa las funciones comunes.

    Las funciones que se incluyen en esta clase son obtener_stopwords, limpiar_palabra, leer_archivo, escribir_archivo.
*/

class Text_utils {

    public:

    /** @brief Carga stopwords desde un archivo
        \pre el archivo con nombre 'archivo_entrada' debe de existir
        \post el resultado es un unordered_set con los stopwords
    */
    static unordered_set<string> obtener_stopwords(const string& archivo_entrada);
    
    /** @brief Limpia una palabra de signos de puntuación y la convierte en minúsculas
        \pre recibe una palabra en formato string
        \post el resultado es la palabra sin signos de puntuación ni tildes, en minúscula
    */
    static string limpiar_palabra(const string& palabra);
};

#endif