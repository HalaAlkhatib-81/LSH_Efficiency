/** @file Text_processor.cc
    @brief Implementación de la clase Text_processor
*/

#include "Text_processor.hh"

void Text_processor::procesar_texto(const string& archivo_entrada, const string& archivo_salida, const string& num) {
    unordered_set<string> stopwords = Text_utils::obtener_stopwords("stopwords-es.txt");

    ifstream entrada(archivo_entrada);
    ofstream salida(archivo_salida);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada: " << archivo_entrada << endl;
        return;
    }

    if (!salida) {
        cerr << "Error al abrir el archivo de salida: " << archivo_salida << endl;
        return;
    }

    string palabra;
    bool primero = true;

    if (num == "1") {
         while(entrada >> palabra) {
            string palabra_final = Text_utils::limpiar_palabra(palabra);
            if (!palabra_final.empty() && !stopwords.count(palabra_final)) {
                if (primero) {
                    salida << palabra_final;
                    primero = false;
                }
                else salida << endl << palabra_final;
            }
        } 
    }

    else {
        while(entrada >> palabra) {
            string palabra_final = Text_utils::limpiar_palabra(palabra);
            if (!palabra_final.empty() && !stopwords.count(palabra_final)) {
                if (primero) {
                    salida << palabra_final;
                    primero = false;
                }
                else salida << " " << palabra_final;
            }
        }
    }
    entrada.close();
    salida.close();
}
