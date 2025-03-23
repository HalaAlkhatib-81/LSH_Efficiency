/** @file JaccardSimilarityCalculator.hh
    @brief Definición de la clase para calcular la similitud de Jaccard entre documentos.
*/

#ifndef JACCARD_SIMILARITY_CALCULATOR_HH
#define JACCARD_SIMILARITY_CALCULATOR_HH

#include <set>
#include <string>
<<<<<<< HEAD
=======
#include <iostream>
#include <fstream>
#include <algorithm>
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5

using namespace std;

/** @class JaccardSimilarityCalculator
    @brief Clase para calcular la similitud de Jaccard entre dos documentos.
*/
class JaccardSimilarityCalculator {
public:
<<<<<<< HEAD
    /** @brief Constructor por defecto. */
    JaccardSimilarityCalculator() = default;
=======
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5

    /** @brief Calcula la similitud de Jaccard entre dos archivos de texto.
        
        @param filename1 Nombre del primer archivo.
        @param filename2 Nombre del segundo archivo.
        @return Un valor entre 0 y 1 representando la similitud de Jaccard.
        
        @pre Los archivos deben existir y ser accesibles.
        @post Devuelve la similitud de Jaccard calculada.
    */
<<<<<<< HEAD
    double computeSimilarity(const string &filename1, const string &filename2);
=======
    static double computeSimilarity(const string &filename1, const string &filename2, int opcion, int k = 0);
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5

private:
    /** @brief Lee un archivo de texto línea por línea e inserta cada línea en un conjunto.
        
        @param filename Nombre del archivo a leer.
        @param doc Conjunto donde se almacenarán las líneas del archivo.
        
        @pre El archivo debe existir y ser accesible.
        @post El conjunto `doc` contiene todas las líneas del archivo sin duplicados.
    */
<<<<<<< HEAD
    void readLinesFromFile(const string &filename, set<string> &doc);
=======
    static void readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k);
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5
};

#endif // JACCARD_SIMILARITY_CALCULATOR_HH