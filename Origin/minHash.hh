/** @file minHash.hh
 * @brief Implementacion de un algoritmo de MinHash para calcular la similitud entre dos documentos.
 */
#ifndef MINHASH_HH
#define MINHASH_HH


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"

using namespace std;


/** @class MinHash
    @brief Clase para calcular la similitud entre dos documentos mediante funciones de MinHash.
*/

class minHash{
    public:
        /** @brief calcula los minHash de cada shingle existente en el documente
         * @param shingles conjunto de shingles del documento
         * @return vector con los minHash de los shingles
         * @pre shingles no vacio
         * @post se devuelven los minHash de los shingles en un vector de enteros
         */
        static vector<uint32_t> computarMinHash(set<string> shingles);



        /** @brief funcion general para calcular la similaridad entre dos documentos
         * @param docA nombre del archivo del documento A
         * @param docB nombre del archivo del documento B
         * @param option opcion para leer el archivo
         * @param k numero de shingles por grupo
         * @return similaridad entre los documentos
         * @pre docA y docB existen
         * @post se devuelve la similaridad entre los documentos
         */
        static double funcion_general_minHash(string docA, string docB, int option, int k);
    private:
        /** @brief lee las lineas de un archivo y las guarda en un conjunto
         * @param filename nombre del archivo
         * @param doc conjunto donde se guardaran las lineas
         * @param opcion opcion para leer el archivo
         * @param k numero de shingles por grupo
         * @pre filename existe
         * @post se guardan las lineas del archivo en el conjunto
         */
        static void readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k);    

};

#endif