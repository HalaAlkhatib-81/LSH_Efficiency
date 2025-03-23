

#ifndef LSH_HH
#define LSH_HH

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include "xxhash.h"
using namespace std;

/** @class MinHash
    @brief Clase para calcular la similitud entre dos documentos mediante Locality Sensitive Hashing.
*/

class LSH{
    public:
        /** @brief calcula los minHash de cada shingle existente en el documente
         * @param shingles conjunto de shingles del documento
         * @return vector con los minHash de los shingles
         * @pre shingles no vacio
         * @post se devuelven los minHash de los shingles en un vector de enteros
         */
        static vector<uint32_t> computarMinHash(set<string> shingles);

        /** @brief calcula las bandas de los minHash
         * @param minhashes vector con los minHash del documento
         * @param b numero de bandas
         * @return vector con las bandas de los minHash
         * @pre minhashes no vacio
         * @post se devuelven las bandas de los minHash en un vector de vectores de enteros
         */
        static vector<vector<int>> bandes(vector<uint32_t> minhashes, int b);

        /** @brief calcula la similaridad de Jaccard aproximada entre dos documentos usando los minHash creados
         * @param firmaA vector con los minHash del documento A
         * @param firmaB vector con los minHash del documento B
         * @return similaridad de Jaccard aproximada entre los documentos
         * @pre firmaA y firmaB no vacios
         * @post se devuelve la similaridad de Jaccard aproximada entre los documentos
         */
        static double similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB);



        /** @brief guarda en una tabla hash los documentos que coinciden en una banda
         * @param bandes vector con las bandas de los minHash
         * @param docId id del documento
         * @param lshTable tabla hash donde se guardaran los documentos que coinciden en una banda
         * @pre bandes no vacio
         */
        static void localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable);
        
        /** @brief funcion general para calcular la similaridad entre dos documentos
         * @param docA nombre del archivo del documento A
         * @param docB nombre del archivo del documento B
         * @param option opcion para leer el archivo
         * @param k numero de shingles por grupo
         * @param b numero de bandas
         * @return similaridad entre los documentos
         * @pre docA y docB existen
         * @post se devuelve la similaridad entre los documentos
         */

        static double funcion_general_LSH(string docA, string docB, int option, int k, int b);
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