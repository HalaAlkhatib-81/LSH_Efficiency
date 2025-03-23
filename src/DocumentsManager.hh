#ifndef DOCUMENTS_MANAGER_HH
#define DOCUMENTS_MANAGER_HH

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>

using namespace std;

/**
 * @class DocumentsManager
 * @brief Clase para gestionar documentos y realizar operaciones sobre ellos.
 */
class DocumentsManager {
public:

    /**
     * @brief Crea un texto base a partir de un archivo.
     * @param archivo Nombre del archivo.
     * @pre El archivo debe existir y ser accesible.
     * @post Se crea un texto base a partir del archivo especificado.
     */
    void creationTextBase(const string& archivo);

    /**
     * @brief Genera permutaciones de un archivo.
     * @param archivo Nombre del archivo.
     * @param size Tamaño de las permutaciones.
     * @param num_permutations Número de permutaciones a generar.
     * @pre El archivo debe existir y ser accesible. size y num_permutations deben ser mayores que 0.
     * @post Se generan las permutaciones del archivo especificado.
     */
    void permutationsGenerator(const string& archivo, const int& size, const int& num_permutations);

    /**
     * @brief Genera k-shingles de un archivo.
     * @param archivo Nombre del archivo.
     * @param k Tamaño de los k-shingles.
     * @pre El archivo debe existir y ser accesible. k debe ser mayor que 0.
     * @post Se generan los k-shingles del archivo especificado.
     */
    void k_shinglesGenerator(const string& archivo, int k);

    /**
     * @brief Genera permutaciones de k-shingles de un archivo.
     * @param archivo Nombre del archivo.
     * @param size Tamaño de las permutaciones.
     * @param num_permutations Número de permutaciones a generar.
     * @param n Número de k-shingles a seleccionar.
     * @pre El archivo debe existir y ser accesible. size, num_permutations y n deben ser mayores que 0.
     * @post Se generan las permutaciones de k-shingles del archivo especificado.
     */
    void k_shinglesPermutationsGenerator(const string& archivo, const int& size, const int& num_permutations, const int& n);

    /**
     * @brief Selecciona un documento a partir de un archivo.
     * @param archivo Nombre del archivo.
     * @return Un conjunto no ordenado de strings que representa el documento.
     * @pre El archivo debe existir y ser accesible.
     * @post Se selecciona el documento del archivo especificado.
     */
    unordered_set<string> selectionDoc(const string& archivo);

    /**
     * @brief Muestra el tamaño de un documento.
     * @param archivo Nombre del archivo.
     * @pre El archivo debe existir y ser accesible.
     * @post Se muestra el tamaño del documento en la salida estándar.
     */
    static void docSize(const string& archivo);

private:

    /**
     * @brief Limpia una palabra eliminando signos de puntuación y convirtiendo a minúsculas.
     * @param palabra La palabra a limpiar.
     * @return La palabra limpia.
     * @pre <em>Cierto</em>
     * @post Se devuelve la palabra limpia.
     */
    static string limpiarPalabra(const string& palabra);

    /**
     * @brief Procesa un texto eliminando las stopwords.
     * @param doc El documento a procesar.
     * @param stopwords Las palabras a eliminar.
     * @pre <em>Cierto</em>
     * @post Se eliminan las stopwords del documento.
     */
    void proccessText(unordered_set<string>& doc, const unordered_set<string>& stopwords);

    /**
     * @brief Lee un archivo y devuelve un conjunto no ordenado de strings.
     * @param filename Nombre del archivo.
     * @return Un conjunto no ordenado de strings que representa el contenido del archivo.
     * @pre El archivo debe existir y ser accesible.
     * @post Se devuelve el contenido del archivo como un conjunto no ordenado de strings.
     */
    static unordered_set<string> readFileSet(const string &filename);

    /**
     * @brief Lee un archivo y devuelve un vector de strings.
     * @param filename Nombre del archivo.
     * @return Un vector de strings que representa el contenido del archivo.
     * @pre El archivo debe existir y ser accesible.
     * @post Se devuelve el contenido del archivo como un vector de strings.
     */
    vector<string> readFileVector(const string &filename);

    /**
     * @brief Escribe un documento en un archivo.
     * @param document El documento a escribir.
     * @param path La ruta del archivo.
     * @pre <em>Cierto</em>
     * @post Se escribe el documento en el archivo especificado.
     */
    void writeFile(const unordered_set<string>& document, const string& path);

    /**
     * @brief Lee un archivo y devuelve un conjunto no ordenado de k-shingles.
     * @param filename Nombre del archivo.
     * @return Un conjunto no ordenado de k-shingles.
     * @pre El archivo debe existir y ser accesible.
     * @post Se devuelve el contenido del archivo como un conjunto no ordenado de k-shingles.
     */
    unordered_set<string> readKShinglesSet(const string &filename);

    /**
     * @brief Lee un archivo y devuelve una matriz de k-shingles.
     * @param filename Nombre del archivo.
     * @return Una matriz de k-shingles.
     * @pre El archivo debe existir y ser accesible.
     * @post Se devuelve el contenido del archivo como una matriz de k-shingles.
     */
    vector<vector<string>> readKShinglesMatrix(const string &filename);

    /**
     * @brief Escribe k-shingles en un archivo.
     * @param words Las palabras a escribir.
     * @param path La ruta del archivo.
     * @param k Tamaño de los k-shingles.
     * @pre <em>Cierto</em>
     * @post Se escriben los k-shingles en el archivo especificado.
     */
    void writeKShingles(vector<string>& words, const string& path, const int& k);
};

#endif // DOCUMENTS_MANAGER_HH