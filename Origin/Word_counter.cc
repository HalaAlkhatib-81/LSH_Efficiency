/** @file Word_counter.cc
    @brief Implementación de la clase Word_counter
*/

#include "Word_counter.hh"

int Word_counter::contpalabras(const string& archivo_entrada){
    unordered_set<string> stopwords = Text_utils::obtener_stopwords("stopwords-es.txt");
    ifstream archivo(archivo_entrada);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return -1;
    }
    
    unordered_set<string> palabras_diferentes;
    string palabra;

    while (archivo >> palabra) {
        string palabra_final = Text_utils::limpiar_palabra(palabra);
        //agrego palabra al set si no es un stopword
        if (!palabra_final.empty() && !stopwords.count(palabra_final)) {
            palabras_diferentes.insert(palabra_final);
        }
    }

    archivo.close();

    return palabras_diferentes.size();
}