/** @file JaccardSimilarityCalculator.hh
    @brief Definición de la clase para calcular la similitud de Jaccard entre documentos.
*/

#ifndef JACCARD_SIMILARITY_CALCULATOR_HH
#define JACCARD_SIMILARITY_CALCULATOR_HH

#include <set>
#include <string>

using namespace std;

/** @class JaccardSimilarityCalculator
    @brief Clase para calcular la similitud de Jaccard entre dos documentos.
*/
class JaccardSimilarityCalculator {
public:
    /** @brief Constructor por defecto. */
    JaccardSimilarityCalculator() = default;

    /** @brief Calcula la similitud de Jaccard entre dos archivos de texto.
        
        @param filename1 Nombre del primer archivo.
        @param filename2 Nombre del segundo archivo.
        @return Un valor entre 0 y 1 representando la similitud de Jaccard.
        
        @pre Los archivos deben existir y ser accesibles.
        @post Devuelve la similitud de Jaccard calculada.
    */
    double computeSimilarity(const string &filename1, const string &filename2);

private:
    /** @brief Lee un archivo de texto línea por línea e inserta cada línea en un conjunto.
        
        @param filename Nombre del archivo a leer.
        @param doc Conjunto donde se almacenarán las líneas del archivo.
        
        @pre El archivo debe existir y ser accesible.
        @post El conjunto `doc` contiene todas las líneas del archivo sin duplicados.
    */
    void readLinesFromFile(const string &filename, set<string> &doc);
};

#endif // JACCARD_SIMILARITY_CALCULATOR_HH