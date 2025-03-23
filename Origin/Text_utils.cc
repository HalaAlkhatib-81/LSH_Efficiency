/** @file Text_utils.cc
    @brief Implementación de la clase Text_utils
*/

#include "Text_utils.hh"


unordered_set<string> Text_utils::obtener_stopwords(const string& archivo_entrada) {
    unordered_set<string> stopwords;
    ifstream archivo(archivo_entrada);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return stopwords;
    }

    // leemos cada stopword y la insertamos en el unordered set 
    string palabra;
    while (archivo >> palabra) { 
        stopwords.insert(palabra);
    }

    archivo.close();

    return stopwords;
}

string Text_utils::limpiar_palabra(const string& palabra) {
    string palabra_final;
    for (char c : palabra) {
        if (!ispunct(c)) {
            palabra_final += tolower(c);
        };
    }
    return palabra_final;
}