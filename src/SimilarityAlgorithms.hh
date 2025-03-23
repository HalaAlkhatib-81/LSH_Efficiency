#ifndef SIMILARITY_ALGORITHMS_HH
#define SIMILARITY_ALGORITHMS_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include "xxhash.h"
#include "DocumentsManager.hh"

using namespace std;

/**
 * @class SimilarityAlgorithms
 * @brief Clase que implementa varios algoritmos de similitud entre documentos.
 */
class SimilarityAlgorithms {
public:

    /**
     * @brief Calcula la similitud de Jaccard entre dos archivos.
     * @param archivo1 Ruta del primer archivo.
     * @param archivo2 Ruta del segundo archivo.
     * @pre Los archivos deben existir y ser accesibles
     * @post Se imprime la similitud de Jaccard entre los dos archivos.
     */
    void JaccardSimilarity(const string& archivo1, const string& archivo2);

    /**
     * @brief Calcula la firma MinHash de dos archivos.
     * @param archivo1 Ruta del primer archivo.
     * @param archivo2 Ruta del segundo archivo.
     * @param T Número de funciones hash a utilizar.
     * @pre Los archivos deben existir y ser accesibles
     * @post Se imprime la similitud MinHash entre los dos archivos.
     */
    void minHash(const string& archivo1, const string& archivo2, int& T);

    /**
     * @brief Calcula la similitud utilizando Locality Sensitive Hashing (LSH).
     * @param archivo1 Ruta del primer archivo.
     * @param archivo2 Ruta del segundo archivo.
     * @param T Número de funciones hash a utilizar.
     * @param b Número de bandas a utilizar en LSH.
     * @pre Los archivos deben existir y ser accesibles
     * @post Se imprime la similitud LSH entre los dos archivos.
     */
    void LSH(const string& archivo1, const string& archivo2, int& T, int& b);

private:

    /**
     * @brief Calcula la similitud entre dos conjuntos de documentos.
     * @param doc1 Conjunto de documentos del primer archivo.
     * @param doc2 Conjunto de documentos del segundo archivo.
     * @return La similitud entre los dos conjuntos de documentos.
     * @pre Los conjuntos de documentos no deben estar vacíos
     * @post Devuelve un valor entre 0 y 1 que representa la similitud.
     */
    double computeSimilarity(unordered_set<string>& doc1, unordered_set<string>& doc2);

    /**
     * @brief Calcula la firma MinHash de un conjunto de shingles.
     * @param shingles Conjunto de shingles.
     * @param T Número de funciones hash a utilizar.
     * @return Vector con las firmas MinHash.
     * @pre El conjunto de shingles no debe estar vacío
     * @post Devuelve un vector con las firmas MinHash.
     */
    static vector<uint32_t> computarMinHash(unordered_set<string> shingles, int& T);

    /**
     * @brief Calcula la similitud MinHash entre dos conjuntos de shingles.
     * @param shinglesA Conjunto de shingles del primer archivo.
     * @param shinglesB Conjunto de shingles del segundo archivo.
     * @param T Número de funciones hash a utilizar.
     * @return La similitud MinHash entre los dos conjuntos de shingles.
     * @pre Los conjuntos de shingles no deben estar vacíos
     * @post Devuelve un valor entre 0 y 1 que representa la similitud.
     */
    static double funcion_general_minHash(unordered_set<string>& shinglesA, unordered_set<string>& shinglesB, int& T);

    /**
     * @brief Divide las firmas MinHash en bandas.
     * @param minhashes Vector con las firmas MinHash.
     * @param T Número de funciones hash a utilizar.
     * @param b Número de bandas a utilizar.
     * @return Matriz con las bandas.
     * @pre El vector de firmas MinHash no debe estar vacío
     * @post Devuelve una matriz con las bandas.
     */
    static vector<vector<int>> bandes(vector<uint32_t> minhashes, int& T, int& b);

    /**
     * @brief Calcula la similitud de Jaccard entre dos firmas MinHash.
     * @param firmaA Firma MinHash del primer archivo.
     * @param firmaB Firma MinHash del segundo archivo.
     * @param T Número de funciones hash a utilizar.
     * @return La similitud de Jaccard entre las dos firmas MinHash.
     * @pre Los vectores de firmas MinHash no deben estar vacíos
     * @post Devuelve un valor entre 0 y 1 que representa la similitud.
     */
    static double similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB, int& T);

    /**
     * @brief Realiza el hashing sensible a la localidad (LSH) de las bandas.
     * @param bandes Matriz con las bandas.
     * @param docId Identificador del documento.
     * @param lshTable Tabla hash para almacenar los resultados de LSH.
     * @pre La matriz de bandas no debe estar vacía
     * @post La tabla hash se actualiza con los resultados de LSH.
     */
    static void localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable);

    /**
     * @brief Calcula la similitud utilizando LSH entre dos conjuntos de shingles.
     * @param shinglesA Conjunto de shingles del primer archivo.
     * @param shinglesB Conjunto de shingles del segundo archivo.
     * @param T Número de funciones hash a utilizar.
     * @param b Número de bandas a utilizar.
     * @return La similitud LSH entre los dos conjuntos de shingles.
     * @pre Los conjuntos de shingles no deben estar vacíos
     * @post Devuelve un valor entre 0 y 1 que representa la similitud.
     */
    static double funcion_general_LSH(unordered_set<string>& shinglesA, unordered_set<string>& shinglesB, int& T, int& b);
};

#endif