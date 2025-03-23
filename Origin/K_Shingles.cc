/** @file K_Shingles.cc
    @brief Implementación de la clase K_Shingles
*/

#include "K_Shingles.hh"

void K_Shingles::generar_k_shingles(const string& archivo_entrada, const string& archivo_salida, int k) {
    ifstream entrada(archivo_entrada);

    if (!entrada) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return;
    }

    vector<string> palabras;
    string palabra;
    while (entrada >> palabra) {
        palabras.push_back(palabra);
    }
    entrada.close();

    if (k > palabras.size()) {
        cerr << "Error: k es mayor que el número total de palabras en el archivo." << endl;
        return;
    }

    ofstream salida(archivo_salida);
     if(!salida) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }
    
    for (size_t i = 0; i + k <= palabras.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            salida << palabras[i+j] << " ";
        }
        salida << endl;
    }

    salida.close();
    cout << "Se generaron " << palabras.size() - k + 1 << " k-shingles en " << archivo_salida << endl;
}