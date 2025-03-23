/** @file K_Shingles_Permutator.cc
    @brief Implementación de la clase K_Shingles_Permutator
*/

#include "K_Shingles_Permutator.hh"

void K_Shingles_Permutator::generar_permutaciones(const string& archivo_entrada, int tamano, int num_permutaciones, int n) {
    ifstream archivo(archivo_entrada);

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    vector<vector<string> > k_shingles;
    string linea;
    while (getline(archivo, linea)) {
        vector<string> aux;
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) {
            aux.push_back(palabra);
        }
        if (!aux.empty()) {
            k_shingles.push_back(aux);
        }
    }

    archivo.close();

    if (k_shingles.empty()) {
        cerr << "Error: el archivo está vacío o no contiene k-shingles válidos." << endl;
        return;
    }

    if (n >= k_shingles.size()) {
        cerr << "Error: el valor de n es mayor o igual al número total de k-shingles." << endl;
        return;
    }

    if (tamano <= 0) {
        cerr << "Error: El tamaño de línea debe ser mayor que 0." << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());

    for (int i = 1; i <= num_permutaciones; ++i) {
        uniform_int_distribution<> distrib(0, k_shingles.size() - 1);
        unordered_set<int> indices_elegidos; //queremos evitar repeticiones

        while (indices_elegidos.size() < n) {
            int indice = distrib(gen);
            indices_elegidos.insert(indice);
        }
        
        string nombre_archivo = "permutacion2_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        if (!archivo) {
            cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
            continue;
        }

        int contador = 0;
        for (int j : indices_elegidos) {
            for (const string& palabra : k_shingles[j]) {
                archivo << palabra << " ";
                contador++;

                if (contador >= tamano) {
                    archivo << "\n";
                    contador = 0;
                }
            }
        }
        archivo.close();
    }
    cout << "Se generaron " << num_permutaciones << " permutaciones en archivos de salida." << endl;
}