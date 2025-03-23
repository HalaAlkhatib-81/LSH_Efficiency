/** @file DocumentsManager.hh
    @brief Definición de la clase para manejar los documentos.
*/

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

/** @class DocumentsManager
    @brief Clase para manejar los documentos.
*/
class DocumentsManager {
public:

    void creationTextBase(const string& archivo);

    void permutationsGenerator(const string& archivo, const int& size, const int& num_permutations);

    void k_shinglesGenerator(const string& archivo, int k);

    void k_shinglesPermutationsGenerator(const string& archivo, const int& size, const int& num_permutations, const int& n);

    unordered_set<string> selectionDoc(const string& archivo);

    static void docSize(const string& archivo);

private:

    /** @brief Limpia una palabra de signos de puntuación y la convierte en minúsculas
        \pre recibe una palabra en formato string
        \post el resultado es la palabra sin signos de puntuación ni tildes, en minúscula
    */
   static string limpiarPalabra(const string& palabra);


   void proccessText(unordered_set<string>& doc, const unordered_set<string>& stopwords);


    /** @brief Lee un archivo de texto línea por línea e inserta cada línea en un conjunto.
        
        @param filename Nombre del archivo a leer.
        @param doc Conjunto donde se almacenarán las líneas del archivo.
        
        @pre El archivo debe existir y ser accesible.
        @post El conjunto `doc` contiene todas las líneas del archivo sin duplicados.
    */
    static unordered_set<string> readFileSet(const string &filename);

    vector<string> readFileVector(const string &filename);

    /** @brief Escribe un archivo de texto en un documento a parte.
        
        @param document Archivo a escribir.
        
        @pre El document es no vacío.
        @post Un archivo txt con la info del document.
    */
    void writeFile(const unordered_set<string>& document, const string& path);


    unordered_set<string> readKShinglesSet(const string &filename);


    vector<vector<string>> readKShinglesMatrix(const string &filename);


    void writeKShingles(vector<string>& words, const string& path, const int& k);
};

#endif // DOCUMENTS_MANAGER_HH