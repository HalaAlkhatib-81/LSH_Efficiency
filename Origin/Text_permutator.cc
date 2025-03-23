/** @file Text_permutator.cc
    @brief Implementación de la clase Text_permutator
*/

#include "Text_permutator.hh"

void Text_permutator::generar_permutaciones(const string& archivo_entrada, int tamano, int num_permutaciones) {
    ifstream archivo(archivo_entrada);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    vector<string> palabras_diferentes;
    string palabra;
    while (archivo >> palabra) {
        palabras_diferentes.push_back(palabra);
    }

    archivo.close();

    random_device rd;
    mt19937 g(rd());

    for (int i = 1; i <= num_permutaciones; ++i) {
        vector<string> palabras_permutadas = palabras_diferentes;
        shuffle(palabras_permutadas.begin(), palabras_permutadas.end(), g);

        string nombre_archivo = "permutacion1_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        if (!archivo) {
            cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
            continue;
        }

        int contador = 0;

        for (const string& palabra : palabras_permutadas) {
            archivo << palabra << " ";
            contador++;

            if (contador >= tamano) {
                archivo << "\n";
                contador = 0;
            }
        }
        archivo.close();
    }
    cout << "Se generaron " << num_permutaciones << " permutaciones en archivos de salida." << endl;
}