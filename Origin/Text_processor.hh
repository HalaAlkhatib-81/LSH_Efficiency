/** @file Text_processor.hh
    @brief Especificación de la clase Text_processor
*/

#ifndef _TEXT_PROCESSOR_HH_ 
#define _TEXT_PROCESSOR_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <fstream>
#include <unordered_set>
#include "Text_utils.hh"
#endif
using namespace std;

/** @class Text_processor
    @brief Clase que genera documentos base excluyendo stopwords.
*/

class Text_processor {

    public:

    /** @brief Genera un documento base sin stopwords
        \pre el archivo con nombre 'archivo_entrada' debe de existir
        \post genera un archivo con nombre 'archivo_salida' con el texto procesado
    */
    static void procesar_texto(const string& archivo_entrada, const string& archivo_salida, const string& num);
};

#endif