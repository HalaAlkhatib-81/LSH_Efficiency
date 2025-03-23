#include "DocumentsManager.hh"

void DocumentsManager::creationTextBase(const string& archivo){
    // string filename = "../documents/" + archivo + ".txt";
    //unordered_set<string> doc = readFileSet(filename);
    //if(doc.empty()) return;

    unordered_set<string> stopwords = readFileSet("../documents/stopwords-es.txt");
    if(stopwords.empty()) return;

    string filename = "../documents/" + archivo + ".txt";
    ifstream entrada(filename);
    if (!entrada) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }

    string path = "../documents/" + archivo + "_text_base.txt";
    ofstream salida(path);

    string palabra;
    bool primero = true;
    while(entrada >> palabra) {
        string palabra_final = limpiarPalabra(palabra);
        if (!palabra_final.empty() && !stopwords.count(palabra_final)) {
            if (primero) {
                salida << palabra_final;
                primero = false;
            }
            else salida << " " << palabra_final;
        }
    }

    // proccessText(doc, stopwords);

    //string path = "../documents/" + archivo + "_text_base.txt";
    //writeFile(doc, path);
}


void DocumentsManager::permutationsGenerator(const string& archivo, const int& size, const int& num_permutations){
    string filename = "../documents/" + archivo + ".txt";
    vector<string> palabras_diferentes = readFileVector(filename);
    if(palabras_diferentes.empty()) return;

    random_device rd;
    mt19937 g(rd());

    for (int i = 1; i <= num_permutations; ++i) {
        vector<string> palabras_permutadas = palabras_diferentes;
        shuffle(palabras_permutadas.begin(), palabras_permutadas.end(), g);

        string nombre_archivo = "../documents/" + archivo + "_basic_permutation_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        int contador = 0;

        for (const string& palabra : palabras_permutadas) {
            archivo << palabra << " ";
            contador++;

            if (contador >= size) {
                archivo << "\n";
                contador = 0;
            }
        }
        archivo.close();
    }
}


void DocumentsManager::k_shinglesGenerator(const string& archivo, int k) {
    string filename = "../documents/" + archivo + ".txt";
    vector<string> words = readFileVector(filename);
    if(words.empty()) return;

    if (k > words.size()) {
        cerr << "Error: k es mayor que el número total de palabras en el archivo." << endl;
        return;
    }

    string path = "../documents/" + archivo + "_" + to_string(k) + "-shingles.txt";
    writeKShingles(words, path, k);
}


void DocumentsManager::k_shinglesPermutationsGenerator(const string& archivo, const int& size, const int& num_permutations, const int& n){
    string filename = "../documents/" + archivo + ".txt";
    vector<vector<string>> k_shingles = readKShinglesMatrix(filename);
    if(k_shingles.empty()) return;

    if (k_shingles.empty()) {
        cerr << "Error: el archivo está vacío o no contiene k-shingles válidos." << endl;
        return;
    }

    if (n >= k_shingles.size()) {
        cerr << "Error: el valor de n es mayor o igual al número total de k-shingles." << endl;
        return;
    }

    if (size <= 0) {
        cerr << "Error: El tamaño de línea debe ser mayor que 0." << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());

    for (int i = 1; i <= num_permutations; ++i) {
        uniform_int_distribution<> distrib(0, k_shingles.size() - 1);
        unordered_set<int> indices_elegidos; //queremos evitar repeticiones

        while (indices_elegidos.size() < n) {
            int indice = distrib(gen);
            indices_elegidos.insert(indice);
        }
        
        string nombre_archivo = "../documents/" + archivo + "_permutation_" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);

        int contador = 0;
        for (int j : indices_elegidos) {
            for (const string& palabra : k_shingles[j]) {
                archivo << palabra << " ";
                contador++;

                if (contador >= size) {
                    archivo << "\n";
                    contador = 0;
                }
            }
        }
        archivo.close();
    }
}


unordered_set<string> DocumentsManager::selectionDoc(const string& archivo){
    string filename = "../documents/" + archivo + ".txt";
    unordered_set<string> doc = readKShinglesSet(filename);
    return doc;
}


void DocumentsManager::docSize(const string& archivo){
    string filename = "../documents/" + archivo + ".txt";
    unordered_set<string> doc = readFileSet(filename);
    cout << doc.size();
}


string DocumentsManager::limpiarPalabra(const string& palabra) {
    string palabra_final;
    for (char c : palabra) {
        if (!ispunct(c)) {
            palabra_final += tolower(c);
        };
    }
    return palabra_final;
}


void DocumentsManager::proccessText(unordered_set<string>& doc, const unordered_set<string>& stopwords){
    for(auto it: stopwords) doc.erase(it);
}


unordered_set<string> DocumentsManager::readFileSet(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(-1);
    }

    unordered_set<string> result;
    string palabra;

    while(file >> palabra) {
        string palabra_final = limpiarPalabra(palabra);
        result.insert(palabra_final);
    }

    file.close();

    return result;
}


vector<string> DocumentsManager::readFileVector(const string &filename){
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(-1);
    }

    vector<string> result;
    string palabra;

    while(file >> palabra) {
        result.push_back(palabra);
    }

    file.close();

    return result;
}


void DocumentsManager::writeFile(const unordered_set<string>& document, const string& path) {
    ofstream file(path);

    for(auto it: document) file << it << '\n';

    file.close();
}

unordered_set<string> DocumentsManager::readKShinglesSet(const string &filename){
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(-1);
    }

    unordered_set<string> result;
    string grupo;
    string linea;
    bool primer = true;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) {
            if (primer) {
                grupo += palabra;
                primer = !primer;
            } else {
                grupo += " " + palabra;
            }
        }
        result.insert(grupo);
        grupo.clear();
        primer = !primer;
    }

    file.close();

    return result;
}

vector<vector<string>> DocumentsManager::readKShinglesMatrix(const string &filename){
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(-1);
    }

    vector<vector<string>> k_shingles;
    string linea;
    while (getline(file, linea)) {
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

    file.close();

    return k_shingles;
}

void DocumentsManager::writeKShingles(vector<string>& words, const string& path, const int& k){
    ofstream file(path);

    for (size_t i = 0; i + k <= words.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            file << words[i+j] << " ";
        }
        file << endl;
    }

    file.close();
}